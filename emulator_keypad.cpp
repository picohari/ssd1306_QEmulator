

#include "emulator_keypad.h"
#include "../../libraries/Adafruit_Keyboard/list.h"


#define KBD_CHECK_INTERVAL  10  /**< (ms) Timing for kbd softint */
#define KBD_DEBOUNCE_TIME   30  /**< (ms) Debounce time */
#define KBD_BEEP_TIME        5  /**< (ms) Duration of keybeep */

#define KBD_REPEAT_DELAY   400  /**< (ms) Keyboard repeat delay for first character */
#define KBD_REPEAT_RATE    100  /**< (ms) Initial interchar delay for keyboard repeat */
#define KBD_REPEAT_MAXRATE  20  /**< (ms) Minimum delay for keyboard repeat */
#define KBD_REPEAT_ACCEL     5  /**< (ms) Keyboard repeat speed increase */

#define KBD_LNG_DELAY     1000  /**< (ms) Keyboard long pression keys delay */




/** Status for keyboard repeat state machine */
static enum { KS_IDLE, KS_REPDELAY, KS_REPEAT } kbd_rptStatus;

/** Used to notify the occurrence of a key pressed event */
//static Event key_pressed;

static volatile keymask_t kbd_buf; /**< Single entry keyboard buffer */
static volatile keymask_t kbd_cnt; /**< Number of keypress events in \c kbd_buf */
static keymask_t kbd_rpt_mask;     /**< Mask of repeatable keys. */

#if CONFIG_KBD_POLL == KBD_POLL_SOFTINT
//static Timer kbd_timer;            /**< Keyboard softtimer */
#endif

static List kbd_rawHandlers;       /**< Raw keyboard handlers */
static List kbd_handlers;          /**< Cooked keyboard handlers */

static KbdHandler kbd_defHandler;  /**< The default keyboard handler */
#if CONFIG_KBD_DEBOUNCE
static KbdHandler kbd_debHandler;  /**< The debounce keyboard handler */
#endif
#if CONFIG_KBD_REPEAT
static KbdHandler kbd_rptHandler;  /**< Auto-repeat keyboard handler */
#endif
#if CONFIG_KBD_LONGPRESS
static KbdHandler kbd_lngHandler;  /**< Long pression keys handler */
#endif











/**
 * Poll keyboard and dispatch keys to handlers.
 *
 * Read the key states and invoke all keyboard
 * handlers to process the new state.
 *
 * Call this function periodically using a software
 * timer, an interrupt or a process.
 */
void kbd_poll(void)
{
	/** Currently depressed key */
	static keymask_t current_key;

	struct KbdHandler *handler;
    //keymask_t key = kbd_readkeys();

    keymask_t key = 0;

	/* Call raw input handlers */
	FOREACH_NODE(handler, &kbd_rawHandlers)
		key = handler->hook(key);

	/* If this key was not previously pressed */
	if (key != current_key)
	{
		/* Remember last key */
		current_key = key;

		/* Call cooked input handlers */
		FOREACH_NODE(handler, &kbd_handlers)
			key = handler->hook(key);
	}

	qDebug("Poll..");
}

#if 0
#if CONFIG_KBD_POLL == KBD_POLL_SOFTINT

/**
 * Keyboard soft-irq handler.
 */
static void kbd_softint(UNUSED_ARG(iptr_t, arg))
{
	kbd_poll();
	/* timer_add(&kbd_timer); */
}

#else
	#error "Define keyboard poll method"

#endif /* CONFIG_KBD_POLL */
#endif


/**
 * \brief Read a key from the keyboard buffer.
 *
 * When a key is kept depressed between calls of this function a value
 * is returned only after the time specified with KBD_REPAT_DELAY to
 * avoid too fast keyboard repeat.
 *
 * \note This function is \b not interrupt safe!
 *
 * \return The mask of depressed keys or 0 if no keys are depressed.
 *
 */
keymask_t kbd_peek(void)
{
	return kbd_peekMask((keymask_t)0xFFFFFFFFFFFFFFFFULL);
}


keymask_t kbd_peekMask(keymask_t mask)
{
	keymask_t key = 0;

	/* Extract an event from the keyboard buffer */
    //IRQ_DISABLE;
	if (kbd_cnt && (kbd_buf & mask))
	{
		key = kbd_buf & mask;
		kbd_buf &= ~mask;
		if (!kbd_buf)
			--kbd_cnt;
	}
    //IRQ_ENABLE;

	return key;
}

/**
 * Wait for a keypress and return the mask of depressed keys.
 *
 * \note This function is \b not interrupt safe!
 */
keymask_t kbd_get(void)
{
	return kbd_getMask((keymask_t)0xFFFFFFFFFFFFFFFFULL);
}

keymask_t kbd_getMask(keymask_t mask)
{
	keymask_t key;

	#if CONFIG_KBD_POLL == KBD_POLL_SOFTINT
		do
		{
			/* event_wait(&key_pressed); */
			key = kbd_peekMask(mask);
		}
		while (!key);
	#else
		do
		{
			/* cpu_relax(); */
		}
		while (!(key = kbd_peekMask(mask)));
	#endif

	return key;
}









#if KBD_POLL_SOFTINT
/**
 * Wait up to \c timeout ms for a keypress
 * and return the mask of depressed keys, or K_TIMEOUT
 * if the timeout was reacked.
 */
keymask_t kbd_get_timeout(mtime_t timeout)
{
	if (event_waitTimeout(&key_pressed, timeout))
		return kbd_peek();
	else
		return K_TIMEOUT;
}
#endif





void kbd_addHandler(struct KbdHandler *handler)
{
	KbdHandler *node;
	List *list;

    //cpu_flags_t flags;
    //IRQ_SAVE_DISABLE(flags);

	/* Choose between raw and coocked handlers list */
	list = (handler->flags & KHF_RAWKEYS) ?
		&kbd_rawHandlers : &kbd_handlers;

	/*
	 * Search for the first node whose priority
	 * is lower than the timer we want to add.
	 */
	FOREACH_NODE(node,list)
		if (node->pri < handler->pri)
			break;

	/* Enqueue handler in the handlers chain */
	INSERT_BEFORE(&handler->link, &node->link);

    //IRQ_RESTORE(flags);
}


void kbd_remHandler(struct KbdHandler *handler)
{
	/* Remove the handler */
    //ATOMIC(REMOVE(&handler->link));
    REMOVE(&handler->link);
}






/**
 * This is the default key handler, called after
 * all other handlers have had their chance to
 * do their special processing. This handler
 * pushes all input in the keyboard FIFO buffer.
 */
static keymask_t kbd_defHandlerFunc(keymask_t key)
{
	if (key)
	{
		/* Force a single event in kbd buffer */
		kbd_buf = key;
		kbd_cnt = 1;
		#if CONFIG_KBD_POLL == KBD_POLL_SOFTINT
			/* event_do(&key_pressed); */
		#endif

		#if CONFIG_KBD_BEEP
			if (!(key & K_REPEAT))
				buz_beep(KBD_BEEP_TIME);
		#endif
	}

	/* Eat all input */
	return 0;
}


#if CONFIG_KBD_DEBOUNCE
/**
 * Handle keyboard debounce
 */
static keymask_t kbd_debHandlerFunc(keymask_t key)
{
	/** Buffer for debounce */
	static keymask_t debounce_key;

	/** Timer for keyboard debounce */
	static ticks_t debounce_time;

	/** Key aquired after debounce */
	static keymask_t new_key;


	ticks_t now = timer_clock();

	if (key != debounce_key)
	{
		/* Reset debounce timer */
		debounce_key = key;
		debounce_time = now;
	}
	else if ((new_key != debounce_key)
		&& (now - debounce_time > ms_to_ticks(KBD_DEBOUNCE_TIME)))
	{
		new_key = debounce_key;
		debounce_time = now;
	}

	return new_key;
}
#endif


#if CONFIG_KBD_LONGPRESS
/**
 * Handle long pression keys.
 */
static keymask_t kbd_lngHandlerFunc(keymask_t key)
{
	static ticks_t start;
	ticks_t now = timer_clock();

	if (key & K_LNG_MASK)
	{
		if (now - start > ms_to_ticks(KBD_LNG_DELAY))
			key |= K_LONG;
	}
	else
		start = now;
	return key;
}
#endif


#if CONFIG_KBD_REPEAT
/**
 * Set current mask of repeatable keys.
 */
keymask_t kbd_setRepeatMask(keymask_t mask)
{
	keymask_t oldmask = kbd_rpt_mask;
	ATOMIC(kbd_rpt_mask = mask);
	return oldmask;
}

/**
 * Handle keyboard repeat
 */
static keymask_t kbd_rptHandlerFunc(keymask_t key)
{
	/* Timer for keyboard repeat events. */
	static ticks_t repeat_time;

	/* Current repeat rate (for acceleration). */
	static ticks_t repeat_rate; /** Current repeat rate (for acceleration) */

	ticks_t now = timer_clock();

	switch (kbd_rptStatus)
	{
		case KS_IDLE:
			if (key & kbd_rpt_mask)
			{
				repeat_time = now;
				kbd_rptStatus = KS_REPDELAY;
			}
			break;

		case KS_REPDELAY:
			if (key & kbd_rpt_mask)
			{
				if (now - repeat_time > ms_to_ticks(KBD_REPEAT_DELAY))
				{
					key = (key & kbd_rpt_mask) | K_REPEAT;
					repeat_time = now;
					repeat_rate = ms_to_ticks(KBD_REPEAT_RATE);
					kbd_rptStatus = KS_REPEAT;
				}
				else
					key = 0;
			}
			else
				kbd_rptStatus = KS_IDLE;
			break;

		case KS_REPEAT:
			if (key & kbd_rpt_mask)
			{
				if (now - repeat_time > repeat_rate)
				{
					/* Enqueue a new event in the buffer */
					key = (key & kbd_rpt_mask) | K_REPEAT;
					repeat_time = now;

					/* Repeat rate acceleration */
					if (repeat_rate > ms_to_ticks(KBD_REPEAT_MAXRATE))
						repeat_rate -= ms_to_ticks(KBD_REPEAT_ACCEL);
				}
				else
					key = 0;
			}
			else
				kbd_rptStatus = KS_IDLE;

			break;
	}

	return key;
}
#endif









/**
 * Initialize keyboard ports and softtimer
 */
void kbd_init(void)
{
#if CONFIG_KBD_BEEP
	MOD_CHECK(buzzer);
#endif

	KBD_HW_INIT;

	/* Init handlers lists */
	LIST_INIT(&kbd_handlers);
	LIST_INIT(&kbd_rawHandlers);

	#if CONFIG_KBD_DEBOUNCE
	/* Add debounce keyboard handler */
	kbd_debHandler.hook = kbd_debHandlerFunc;
	kbd_debHandler.pri = 100; /* high priority */
	kbd_debHandler.flags = KHF_RAWKEYS;
	kbd_addHandler(&kbd_debHandler);
	#endif

	#if CONFIG_KBD_LONGPRESS
	/* Add long pression keyboard handler */
	kbd_lngHandler.hook = kbd_lngHandlerFunc;
	kbd_lngHandler.pri = 90; /* high priority */
	kbd_lngHandler.flags = KHF_RAWKEYS;
	kbd_addHandler(&kbd_lngHandler);
	#endif

	#if CONFIG_KBD_REPEAT
	/* Add repeat keyboard handler */
	kbd_rptHandler.hook = kbd_rptHandlerFunc;
	kbd_rptHandler.pri = 80; /* high priority */
	kbd_rptHandler.flags = KHF_RAWKEYS;
	kbd_addHandler(&kbd_rptHandler);
	#endif

	/* Add default keyboard handler */
	kbd_defHandler.hook = kbd_defHandlerFunc;
	kbd_defHandler.pri = -128; /* lowest priority */
	kbd_addHandler(&kbd_defHandler);


#if CONFIG_KBD_POLL == KBD_POLL_SOFTINT

	/* Initialize the keyboard event (key pressed) */
    //event_initGeneric(&key_pressed);

	/* Add kbd handler to soft timers list */
    //event_initSoftint(&kbd_timer.expire, kbd_softint, NULL);
    //timer_setDelay(&kbd_timer, ms_to_ticks(KBD_CHECK_INTERVAL));
    //timer_add(&kbd_timer);


#else
	
	#warning "Define keyboard poll method"

#endif

}
