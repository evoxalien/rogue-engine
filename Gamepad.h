#ifndef GAMEPAD_H
#define GAMEPAD_H
 
#include "XInput.h"
#include <windows.h>
#pragma comment(lib, "Xinput.lib");
 // XInput Button values
static const WORD XINPUT_Buttons[] = {
      XINPUT_GAMEPAD_A,
      XINPUT_GAMEPAD_B,
      XINPUT_GAMEPAD_X,
      XINPUT_GAMEPAD_Y,
      XINPUT_GAMEPAD_DPAD_UP,
      XINPUT_GAMEPAD_DPAD_DOWN,
      XINPUT_GAMEPAD_DPAD_LEFT,
      XINPUT_GAMEPAD_DPAD_RIGHT,
      XINPUT_GAMEPAD_LEFT_SHOULDER,
      XINPUT_GAMEPAD_RIGHT_SHOULDER,
      XINPUT_GAMEPAD_LEFT_THUMB,
      XINPUT_GAMEPAD_RIGHT_THUMB,
      XINPUT_GAMEPAD_START,
      XINPUT_GAMEPAD_BACK
};
 
// XInput Button IDs
struct XButtonIDs
{
      // Function prototypes
      //---------------------//
 
      XButtonIDs(); // Default constructor
 
      // Member variables
      //---------------------//
 
      int A,B,X,Y; // 'Action' buttons
 
      // Directional Pad (D-Pad)
      int DPad_Up, DPad_Down, DPad_Left, DPad_Right;
 
      // Shoulder ('Bumper') buttons
      int L_Shoulder, R_Shoulder;
 
      // Thumbstick buttons
      int L_Thumbstick, R_Thumbstick;
 
      int Start; // 'START' button
      int Back;  // 'BACK' button
};
////https://lcmccauley.wordpress.com/2014/01/05/gamepad-input-tutorial/
class Gamepad
{
public:
     // Function prototypes
     //---------------------//
 
     // Constructors
     Gamepad();
     Gamepad(int a_iIndex);
 
     void Update();       // Update gamepad state
     void RefreshState(); // Update button states for next frame
 
     // Thumbstick functions
     // - Return true if stick is inside deadzone, false if outside
     bool LStick_InDeadzone();
     bool RStick_InDeadzone();
 
     float LeftStick_X();  // Return X axis of left stick
     float LeftStick_Y();  // Return Y axis of left stick
     float RightStick_X(); // Return X axis of right stick
     float RightStick_Y(); // Return Y axis of right stick
 
     // Trigger functions
     float LeftTrigger();  // Return value of left trigger
     float RightTrigger(); // Return value of right trigger
 
     // Button functions
     // - 'Pressed' - Return true if pressed, false if not
     // - 'Down'    - Same as 'Pressed', but ONLY on current frame
     bool GetButtonPressed(int a_iButton);
     bool GetButtonDown(int a_iButton);
 
     // Utility functions
     XINPUT_STATE GetState(); // Return gamepad state
     int GetIndex();          // Return gamepad index
     bool Connected();        // Return true if gamepad is connected
 
     // Vibrate the gamepad (0.0f cancel, 1.0f max speed)
     void Rumble(float a_fLeftMotor = 0.0f, float a_fRightMotor = 0.0f);
 
private:
     // Member variables
     //---------------------//
      // Define the 'XButtonIDs' struct as 'XButtons'
     XButtonIDs XButtons;

     XINPUT_STATE m_State; // Current gamepad state
     int m_iGamepadIndex;  // Gamepad index (eg. 1,2,3,4)
 
     static const int ButtonCount = 14;    // Total gamepad buttons
     bool bPrev_ButtonStates[ButtonCount]; // Previous frame button states
     bool bButtonStates[ButtonCount];      // Current frame button states
 
     // Buttons pressed on current frame
     bool bGamepad_ButtonsDown[ButtonCount];
};
 
#endif // GAMEPAD_H
 
// // Externally define the 'XButtonIDs' struct as 'XButtons'
// extern XButtonIDs XButtons;

// 'XButtonIDs' - Default constructor
XButtonIDs::XButtonIDs()
{
      // These values are used to index the XINPUT_Buttons array,
      // accessing the matching XINPUT button value
 
      A = 0;
      B = 1;
      X = 2;
      Y = 3;
 
      DPad_Up    = 4;
      DPad_Down  = 5;
      DPad_Left  = 6;
      DPad_Right = 7;
 
      L_Shoulder = 8;
      R_Shoulder = 9;
 
      Start = 10;
      Back  = 11;
 
      L_Thumbstick = 12;
      R_Thumbstick = 13;
}


// Default constructor
Gamepad::Gamepad() {}
 
// Overloaded constructor
Gamepad::Gamepad(int a_iIndex)
{
    // Set gamepad index
    m_iGamepadIndex = a_iIndex - 1;
 
    // Iterate through all gamepad buttons
    for (int i = 0; i < ButtonCount; i++)
    {
          bPrev_ButtonStates[i]   = false;
          bButtonStates[i]        = false;
          bGamepad_ButtonsDown[i] = false;
    }
}

// Return gamepad index
// Index is 0-3 for four controllers
int Gamepad::GetIndex()
{
      return m_iGamepadIndex;
}


// // Return true if the gamepad is connected
// // Good to check if multiple are connected
bool Gamepad::Connected()
{
      // Zero memory
      ZeroMemory(&m_State, sizeof(XINPUT_STATE));
 
      // Get the state of the gamepad
     // DWORD Result = XInputGetState(m_iGamepadIndex, &m_State);
      DWORD Result;
      if (Result == ERROR_SUCCESS)
            return true;  // The gamepad is connected
      else
            return false; // The gamepad is not connected
}

// Return gamepad state
XINPUT_STATE Gamepad::GetState()
{
      // Temporary XINPUT_STATE to return
      XINPUT_STATE GamepadState;
 
      // Zero memory
      ZeroMemory(&GamepadState, sizeof(XINPUT_STATE));
 
      // Get the state of the gamepad
      //XInputGetState(m_iGamepadIndex, &GamepadState);
 
      // Return the gamepad state
      return GamepadState;
}
// Update gamepad state
void Gamepad::Update()
{
    m_State = GetState(); // Obtain current gamepad state
 
    // Iterate through all gamepad buttons
    for (int i = 0; i < ButtonCount; i++)
    {
          // Set button state for current frame
          bButtonStates[i] = (m_State.Gamepad.wButtons &
             XINPUT_Buttons[i]) == XINPUT_Buttons[i];
 
          // Set 'DOWN' state for current frame
          bGamepad_ButtonsDown[i] = !bPrev_ButtonStates[i] &&
            bButtonStates[i];
    }
}

// Update button states for next frame
void Gamepad::RefreshState()
{
       memcpy(bPrev_ButtonStates, bButtonStates,
         sizeof(bPrev_ButtonStates));
}


// Deadzone check for Left Thumbstick
bool Gamepad::LStick_InDeadzone()
{
       // Obtain the X & Y axes of the stick
       short sX = m_State.Gamepad.sThumbLX;
       short sY = m_State.Gamepad.sThumbLY;
 
       // X axis is outside of deadzone
       if (sX > XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE ||
           sX < -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
           return false;
 
       // Y axis is outside of deadzone
       if (sY > XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE ||
           sY < -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
           return false;
 
       // One (or both axes) axis is inside of deadzone
       return true;
}
 
// Deadzone check for Right Thumbstick
bool Gamepad::RStick_InDeadzone()
{
       // Obtain the X & Y axes of the stick
       short sX = m_State.Gamepad.sThumbRX;
       short sY = m_State.Gamepad.sThumbRY;
 
       // X axis is outside of deadzone
       if (sX > XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE ||
           sX < -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE)
           return false;
 
       // Y axis is outside of deadzone
       if (sY > XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE ||
           sY < -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE)
           return false;
 
       // One (or both axes) axis is inside of deadzone
       return true;
}


// Return X axis of left stick
float Gamepad::LeftStick_X()
{
        // Obtain X axis of left stick
        short sX = m_State.Gamepad.sThumbLX;
 
        // Return axis value, converted to a float
        return (static_cast<float>(sX) / 32768.0f);
}
 
// Return Y axis of left stick
float Gamepad::LeftStick_Y()
{
        // Obtain Y axis of left stick
        short sY = m_State.Gamepad.sThumbLY;
 
        // Return axis value, converted to a float
        return (static_cast<float>(sY) / 32768.0f);
}
 
// Return X axis of right stick
float Gamepad::RightStick_X()
{
        // Obtain X axis of right stick
        short sX = m_State.Gamepad.sThumbRX;
 
        // Return axis value, converted to a float
        return (static_cast<float>(sX) / 32768.0f);
}
 
// Return Y axis of right stick
float Gamepad::RightStick_Y()
{
        // Obtain the Y axis of the left stick
        short sY = m_State.Gamepad.sThumbRY;
 
        // Return axis value, converted to a float
        return (static_cast<float>(sY) / 32768.0f);
}


// Return value of left trigger
float Gamepad::LeftTrigger()
{
        // Obtain value of left trigger
        BYTE Trigger = m_State.Gamepad.bLeftTrigger;
 
        if (Trigger > XINPUT_GAMEPAD_TRIGGER_THRESHOLD)
              return Trigger / 255.0f;
 
        return 0.0f; // Trigger was not pressed
}
 
// Return value of right trigger
float Gamepad::RightTrigger()
{
        // Obtain value of right trigger
        BYTE Trigger = m_State.Gamepad.bRightTrigger;
 
        if (Trigger > XINPUT_GAMEPAD_TRIGGER_THRESHOLD)
              return Trigger / 255.0f;
 
        return 0.0f; // Trigger was not pressed
}

// Vibrate the gamepad (values of 0.0f to 1.0f only)
void Gamepad::Rumble(float a_fLeftMotor, float a_fRightMotor)
{
       // Vibration state
       XINPUT_VIBRATION VibrationState;
 
       // Zero memory
       ZeroMemory(&VibrationState, sizeof(XINPUT_VIBRATION));
 
       // Calculate vibration values
       int iLeftMotor  = int(a_fLeftMotor * 65535.0f);
       int iRightMotor = int(a_fRightMotor * 65535.0f);
 
       // Set vibration values
       VibrationState.wLeftMotorSpeed  = iLeftMotor;
       VibrationState.wRightMotorSpeed = iRightMotor;
 
       // Set the vibration state
       //XInputSetState(m_iGamepadIndex, &VibrationState);
}


// Return true if button is pressed, false if not
bool Gamepad::GetButtonPressed(int a_iButton)
{
      if (m_State.Gamepad.wButtons & XINPUT_Buttons[a_iButton])
      {
            return true; // The button is pressed
      }
 
      return false; // The button is not pressed
}

