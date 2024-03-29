/*
  Homemade vending machine created by Jeffrey Li 
  Created: November 3, 2019
  Last modified: December 5, 2019

  This program is for the use of a vending machine. An Arduino Mega 2560 is used to 
  control the four stepper motors. A 4x4 keypad allows users to input keys into the
  Arduino and an 1602 LCD display provides feedback to the user. Four passwords are
  used to control which vending slot is activated. 

  Parts List
-1602 LCD display screen
-4x4 Matrix Keypad
-4x 28BYJ-48 stepper motor
-4x ULN2003 driver
-10k potentiometer
-Jumper wires
-Arduino Mega 2560


*/


#include <LiquidCrystal.h>
#include <Stepper.h>
#include <Key.h>
#include <Keypad.h>

LiquidCrystal lcd(47, 48, 49, 50, 51, 52); //pin order for LCD screen


#define STEPS 2048 // the number of steps in one revolution of the stepper motor
  
Stepper stepperTL(STEPS, 10, 12, 11, 13);
Stepper stepperTR(STEPS, 14, 16, 15, 17);
Stepper stepperBL(STEPS, 18, 20, 19, 21);
Stepper stepperBR(STEPS, 22, 24, 23, 25);

const byte ROWS = 4; //four rows

const byte COLS = 4; //three columns

char keys[ROWS][COLS] = 
{

  {'1','2','3','A'},

  {'4','5','6','B' },

  {'7','8','9','C'},

  {'*','0','#','D'}

};

byte rowPins[ROWS] = {30, 31, 32, 33}; //connect to the row pinouts of the keypad

byte colPins[COLS] = {34, 35, 36, 37}; //connect to the column pinouts of the keypad

Keypad matrixKeypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

#define Password_length 5 /*password are 4 characters long but there is a null 
                          character at the end */

char User_input[Password_length]; //array for the users input on the keypad
char TL_Password[Password_length] = "1311"; //top left password
char TR_Password[Password_length] = "5432"; //top right password
char BL_Password[Password_length] = "6542"; //bottom left password
char BR_Password[Password_length] = "976A"; //bottom right password
byte inputCounter; 
char pressedKey;
int forLoopCounter;

void setup() 

{
  lcd.begin(16, 2); //the dimensions for the LCD screen
  Serial.begin(9600);

  lcd.setCursor(0,0); 
  lcd.print("Hello welcome to");
  lcd.setCursor(2,1);
  lcd.print("Jeff's Machine");
  delay(4000);
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Please enter");
  lcd.setCursor(2,1);
  lcd.print("a password");
}

void loop() 
{
  pressedKey = matrixKeypad.getKey();

  if (pressedKey)
  {
    User_input[inputCounter] = pressedKey; //stores user input into the array
    Serial.println(User_input[inputCounter]);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("You entered");
    lcd.setCursor(12,0);
    lcd.print(User_input);     
    inputCounter++;                        //moves to the next position in the array
  }

  if (inputCounter == Password_length-1) //when the user presses four keys on the keypad
  {
    lcd.clear();

    if (!strcmp(User_input, TL_Password)) /*compares the user input array with the password
                                          array for the top left*/                              
    {
      for (forLoopCounter = 0; forLoopCounter < 1; forLoopCounter++)
      {
       lcd.setCursor(3,1);
       lcd.print("Vending");
       stepperTL.setSpeed(14);
       stepperTL.step(-2048);
      }
      
      clearStorage(); //clear input array when a correct password is entered
    }

    else if (!strcmp(User_input, TR_Password)) //compares the user input to top right
    {
      for (forLoopCounter = 0; forLoopCounter < 1; forLoopCounter++)
      {
       
       lcd.setCursor(3,1);
       lcd.print("Vending");
       stepperTR.setSpeed(14);
       stepperTR.step(-2048);
      }
      
      clearStorage(); //clear input array when a correct password is entered
    }

    else if (!strcmp(User_input, BL_Password)) //compares the user input to bottom left
    {
      for (forLoopCounter = 0; forLoopCounter < 1; forLoopCounter++)
      {
       lcd.setCursor(3,1);
       lcd.print("Vending");
       stepperBL.setSpeed(14);
       stepperBL.step(-2048);
      }
     
      clearStorage(); //clear input array when a correct password is entered
     
    }

    else if (!strcmp(User_input, BR_Password)) //compares the user input to bottom right
    {
      for (forLoopCounter = 0; forLoopCounter < 1; forLoopCounter++)
      {
       lcd.setCursor(3,1);
       lcd.print("Vending");
       stepperBR.setSpeed(14);
       stepperBR.step(-2048);
      }
      
      clearStorage(); //clear input array when a correct password is entered

    }

    else
    {
      clearRetry(); //clears input array when they input an incorrect password
    }
 
  }
}

void clearStorage()
{
  inputCounter = 0;

  for(int eraseCounter = 0; eraseCounter <= inputCounter; eraseCounter++)
  {
    User_input[eraseCounter] = '\0'; /*goes to each address in the index and erases
                                     the values*/
  }

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Thank You!");
  delay(1000);
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Please enter");
  lcd.setCursor(2,1);
  lcd.print("a password");
}

void clearRetry()
{
  
  inputCounter = 0;

  for(int eraseCounter = 0; eraseCounter <= inputCounter; eraseCounter++)
  {
    User_input[eraseCounter] = '\0'; /*goes to each address in the index and erases
                                     the values*/
  }

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Please try again");
  delay(1000);
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Please enter");
  lcd.setCursor(2,1);
  lcd.print("a password");
}
