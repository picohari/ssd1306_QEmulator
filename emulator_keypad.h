#ifndef EMULATOR_KEYPAD_H
#define EMULATOR_KEYPAD_H

#include <QMainWindow>

#include <QMessageBox>

#include <QDebug>

#include "mainwindow.h"



#include "../../libraries/Adafruit_Keyboard/list.h"

/// Define CONFIG_KBD_POLL to one of these
#define KBD_POLL_SOFTINT  		0

/// Keyboard polling method. $WIZ$ supports = "False"
#define CONFIG_KBD_POLL  		KBD_POLL_SOFTINT

/// Enable key beeps. $WIZ$ type = "boolean"
#define CONFIG_KBD_BEEP  		0

/// Enable long pression handler for keys. $WIZ$ type = "boolean"
#define CONFIG_KBD_LONGPRESS  	0

/// Enable repeated pression handler for keys. $WIZ$ type = "boolean"
#define CONFIG_KBD_REPEAT		0

// Enable debounce handler
#define CONFIG_KBD_DEBOUNCE		0





/**
 * \name Keycodes.
 */
/*@{*/
#define K_UP       (1 << 0)
#define K_DOWN     (1 << 1)
#define K_LEFT     (1 << 2)
#define K_RIGHT    (1 << 3)
#define K_OK       (1 << 4)


#define K_REPEAT   (1 << 13) /**< This is a repeated keyevent. */
#define K_TIMEOUT  (1 << 14) /**< Fake key event for timeouts. */
#define K_LONG     (1 << 15)
/*@}*/

#define K_LNG_MASK 0

#define K_RPT_MASK (K_UP | K_DOWN | K_LEFT | K_RIGHT | K_OK)







/**
 * Type for keyboard mask.
 */
typedef uint16_t keymask_t;

/**
 * Keyboard handler descriptor
 */
typedef struct KbdHandler
{
	Node link;
	keymask_t (*hook)(keymask_t);   /**< Hook function */
	int8_t pri;                     /**< Priority in input queue */
	uint8_t flags;                  /**< See below for definitions */
} KbdHandler;

#define KHF_RAWKEYS	(1 << 0)        /**< Handler gets raw key events */


/* HARDWARE BLOCK */

#define KBD_HW_INIT \
	do { \
			/* Put here code to init hw */ \
	} while (0)





extern "C" int emul_kbdReadCols(void);

/**
 * Read the keyboard ports and return the mask of
 * depressed keys.
 */
INLINE keymask_t kbd_readkeys(void)
{
	/* Implement me! */

	//Only for test remove when implement this function
	//return 0;

	return (keymask_t)emul_kbdReadCols();

}




/* INCLUDE FUNCTIONS */

void kbd_init(void);

void kbd_poll(void);


keymask_t kbd_peek(void);
keymask_t kbd_peekMask(keymask_t mask);
keymask_t kbd_get(void);
keymask_t kbd_getMask(keymask_t mask);

//keymask_t kbd_get_timeout(mtime_t timeout);
keymask_t kbd_get_timeout(time_t timeout);

void kbd_addHandler(struct KbdHandler *handler);
void kbd_remHandler(struct KbdHandler *handler);
keymask_t kbd_setRepeatMask(keymask_t mask);












#if 0
enum ButtonId
{
    ButtonId_None,
    ButtonId_1,
    ButtonId_2,
    ButtonId_3,
    ButtonId_4,
    ButtonId_5
};

enum ButtonState
{
    ButtonState_Up,
    ButtonState_Down,
    ButtonState_Click,
    ButtonState_DoubleClick, // not implemented yet
    ButtonState_Hold,
};

struct ButtonParam
{
    ButtonId button;
    ButtonState state;
};

extern ButtonParam param;

class EmulatorKeypad
{

public:
    EmulatorKeypad();
    ~EmulatorKeypad();

};
#endif


#endif // EMULATOR_KEYPAD_H
