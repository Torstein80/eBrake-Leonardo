#include <Arduino.h>
// Simple gamepad example that demonstraits how to read five Arduino
// digital pins and map them to the Arduino Joystick library.
//
// The digital pins 2 - 6 are grounded when they are pressed.
// Pin 2 = UP
// Pin 3 = RIGHT
// Pin 4 = DOWN
// Pin 5 = LEFT
// Pin 6 = FIRE
//
// NOTE: This sketch file is for use with Arduino Leonardo and
//       Arduino Micro only.
//
// by Matthew Heironimus
// 2016-11-24
//--------------------------------------------------------------------

#include <Joystick.h>

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_GAMEPAD,
  3, 0,                  // Button Count, Hat Switch Count
  false, false, false,     // X and Y, but no Z Axis
  false, false, false,   // No Rx, Ry, or Rz
  false, false,          // No rudder or throttle
  false, true, false);  // No accelerator, brake, or steering


void setup()
{
  // Initialize Button Pins
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(A0, INPUT); 
  
  Joystick.begin();
   
}

const int pinToAnalogMap = A0;
// Constant that maps the phyical pin to the joystick button.
const int pinToButtonMap = 2;

// Last state of the button
int lastButtonState[3] = {0,0,0};

void loop()
{

  // Read pin values
  for (int index = 0; index < 3; index++)
  {
    int currentButtonState = !digitalRead(index + pinToButtonMap);
    if (currentButtonState != lastButtonState[index])
    {
      Joystick.setButton(index, currentButtonState);
      lastButtonState[index] = currentButtonState;
    }
  }

int pot = analogRead(A0);
int mapped = map(pot,0,1023,0,255);
{Joystick.setBrake(mapped);}
}


// Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_GAMEPAD,
//   1, 0,                  // Button Count, Hat Switch Count
//   true, true, false,     // X and Y, but no Z Axis
//   false, false, false,   // No Rx, Ry, or Rz
//   false, false,          // No rudder or throttle
//   false, false, false);  // No accelerator, brake, or steering

// void setup() {
//   // Initialize Button Pins
//   pinMode(2, INPUT_PULLUP);
//   pinMode(3, INPUT_PULLUP);
//   pinMode(4, INPUT_PULLUP);
//   pinMode(5, INPUT_PULLUP);
//   pinMode(6, INPUT_PULLUP);

//   // Initialize Joystick Library
//   Joystick.begin();
//   Joystick.setXAxisRange(-1, 1);
//   Joystick.setYAxisRange(-1, 1);
// }

// // Last state of the buttons
// int lastButtonState[5] = {0,0,0,0,0};

// void loop() {

//   // Read pin values
//   for (int index = 0; index < 5; index++)
//   {
//     int currentButtonState = !digitalRead(index + 2);
//     if (currentButtonState != lastButtonState[index])
//     {
//       switch (index) {
//         case 0: // UP
//           if (currentButtonState == 1) {
//             Joystick.setYAxis(-1);
//           } else {
//             Joystick.setYAxis(0);
//           }
//           break;
//         case 1: // RIGHT
//           if (currentButtonState == 1) {
//             Joystick.setXAxis(1);
//           } else {
//             Joystick.setXAxis(0);
//           }
//           break;
//         case 2: // DOWN
//           if (currentButtonState == 1) {
//             Joystick.setYAxis(1);
//           } else {
//             Joystick.setYAxis(0);
//           }
//           break;
//         case 3: // LEFT
//           if (currentButtonState == 1) {
//             Joystick.setXAxis(-1);
//           } else {
//             Joystick.setXAxis(0);
//           }
//           break;
//         case 4: // FIRE
//           Joystick.setButton(0, currentButtonState);
//           break;
//       }
//       lastButtonState[index] = currentButtonState;
//     }
//   }

//   delay(10);
// }

