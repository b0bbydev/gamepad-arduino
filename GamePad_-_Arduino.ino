/*
 * Name: Bobby Jonkman
 * Date: July 19th 2020
 * Purpose: Control a basic computer game with my smartphone using Arduino. In this case it is emulated Super Mario Bros.
 * https://supermarioemulator.com/supermario.php
 */

#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_SHIELD

/* Include libraries. */
#include <OneSheeld.h>
#include <Keyboard.h>


// creating variable to light up RGB Pin when a button is pressed.
int redRGB = 9;
int grnRGB = 10;
int bluRGB = 11;

void setup()
{
  /* Start communication. */
  OneSheeld.begin();
  Keyboard.begin();
  /* Set the RGB pins as output. */
  pinMode(redRGB,OUTPUT);
  pinMode(grnRGB,OUTPUT);
  pinMode(bluRGB,OUTPUT);
}// end of setup method.

void loop()
{
  sendKeystrokes();
  showRGB();
}// end of loop method.


// A method to send keystrokes to keyboard when directional button is pushed. Currently library only supports 
void sendKeystrokes()
{
  // Up Arrow.
  if(GamePad.isUpPressed())
  {
    /* Send keystroke */
    Keyboard.press(0xDA);
  }
  else
  {
    Keyboard.release(0xDA);
  }// end of if-else up arrow.

  // Down Arrow.
  if(GamePad.isDownPressed())
  {
    /* Send keystroke */
    Keyboard.press(0xD9);
  }
  else
  {
    Keyboard.release(0xD9);
  }// end of if-else up arrow.

  // Left Arrow.
  if(GamePad.isLeftPressed())
  {
    /* Send keystroke */
    Keyboard.press(0xD8);
  }
  else
  {
    Keyboard.release(0xD8);
  }// end of if-else up arrow.

  // Right Arrow.
  if(GamePad.isRightPressed())
  {
    /* Send keystroke */
    Keyboard.press(0xD7);
  }
  else
  {
    Keyboard.release(0xD7);
  }// end of if-else up arrow.
}// end of sendKeystrokes method.


// A method to show RGB when a colored button is pushed.
void showRGB()
{
  /* Turn on the LED when the red button is pressed. */
  if(GamePad.isRedPressed())
  {
    /* Turn on the LED. */
    digitalWrite(redRGB,HIGH);
  }
  else 
  {
    /* Turn off the LED. */
    digitalWrite(redRGB,LOW);
  }// end of redRGB if-else.


  /* Turn on the LED when the green button is pressed. -- This will also send keystroke to UP arrow to mimic jump. */
  if(GamePad.isGreenPressed())
  {
    /* Send keystroke */
    Keyboard.press(0xDA);
    /* Turn on the LED. */
    digitalWrite(grnRGB,HIGH);
  }
  else 
  {
    /* Release keystroke. */
    Keyboard.release(0xDA);
    /* Turn off the LED. */
    digitalWrite(grnRGB,LOW);
  }// end of grnRGB if-else.

  
  /* Turn on the LED when the blue button is pressed. -- This will also send keystroke to SHIFT button to mimic sprint. */
  if(GamePad.isBluePressed())
  {
    /* Send keystroke. */
    Keyboard.press(0x81);
    /* Turn on the LED. */
    digitalWrite(bluRGB,HIGH);
  }
  else 
  {
    /* Release keystroke. */
    Keyboard.release(0x81);
    /* Turn off the LED. */
    digitalWrite(bluRGB,LOW);
  }// end of bluRGB if-else.


  /* Turn on the LED when the yellow button is pressed. -- Doesn't look that yellow/orange due to RGB. */ 
  if(GamePad.isOrangePressed())
  {
    /* Turn on the LED. */
    digitalWrite(redRGB,HIGH);
    digitalWrite(grnRGB,HIGH);
  }
  else 
  {
    /* Turn off the LED. */
    digitalWrite(redRGB,LOW);
    digitalWrite(grnRGB,LOW);
  }// end of ylwRGB if-else.
}// end of showRGBColor.
