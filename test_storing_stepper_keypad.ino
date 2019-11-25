#include <Stepper.h>
#include <Key.h>
#include <Keypad.h>

 
  #define STEPS 2038 // the number of steps in one revolution of your motor (28BYJ-48)
  
  Stepper stepper(STEPS, 10, 12, 11, 13);

const byte ROWS = 4; //four rows

const byte COLS = 4; //three columns

char keys[ROWS][COLS] = {

  {'1','2','3','A'},

  {'4','5','6','B' },

  {'7','8','9','C'},

  {'*','0','#','D'}

};

byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad

byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

Keypad matrixKeypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

#define Password_length 5

char User_input[Password_length];
char TL_Password[Password_length] = "1311";
byte inputCounter;
char pressedKey;
int counter;
void setup() 

{

  Serial.begin(9600);
}

void loop() 
{
 pressedKey = matrixKeypad.getKey();

  if (pressedKey)
  {
    User_input[inputCounter] = pressedKey;
    Serial.println(User_input[inputCounter]);
    inputCounter++;
  }

  if (inputCounter == Password_length-1)
  {
    

    if (!strcmp(User_input, TL_Password))
    {
      for (counter = 0; counter <= 1; counter++)
      {
       stepper.setSpeed(14);
       stepper.step(2048);
       Serial.println(counter);
      }
      Serial.print("Hey this is inputCounter ");
      Serial.println(inputCounter);
      clearData();
      Serial.print("Hey this is User_input[Password_length] ");
      Serial.println(User_input[Password_length]);
      Serial.print("Hey this is pressedKey ");
      Serial.println(pressedKey);
      Serial.print("Hey this is counter ");
      Serial.println(counter);
      Serial.print("Hey this is inputCounter after clear ");
      Serial.println(inputCounter);
    }
    

      
 
  }
}

void clearData()
{
  inputCounter = 0;
  Serial.print("inputCounter = ");
  Serial.println(inputCounter);
  
  for(int eraseCounter = 0; eraseCounter <= inputCounter; eraseCounter++)
  {
    User_input[eraseCounter] = 0;
  }
}
