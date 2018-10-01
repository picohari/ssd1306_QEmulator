#ifndef EMULATOR_KEYPAD_H
#define EMULATOR_KEYPAD_H

#include <QMainWindow>

#include <QMessageBox>

#include <QDebug>



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



#endif // EMULATOR_KEYPAD_H
