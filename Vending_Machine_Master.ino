#include <LiquidCrystal.h>
#include <Key.h>
#include <Keypad.h>

LiquidCrystal lcd(1, 2, 4, 5, 6, 7); //pin order for LCD screen

#define Password_length 5

char User_input[Password_length];
char TL_Password[Password_length] = "1311";
char TR_Password[Password_length] = "AD89";
char BL_Password[Password_length] = "0000";
char TR_Password[Password_length] = "3121";
byte inputCounter;
char pressedKey;


const byte ROWS = 4; 
const byte COLS = 4; 
char keys[ROWS][COLS] = 
{
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {5, 4, 3, 2}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {9, 8, 7, 6}; //connect to the column pinouts of the keypad

Keypad matrixKeypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );



//top left corner motor
#define TL_STEPPER_PIN_1 #
#define TL_STEPPER_PIN_2 #
#define TL_STEPPER_PIN_3 #
#define TL_STEPPER_PIN_4 #

//top right corner motor
#define TR_STEPPER_PIN_1 #
#define TR_STEPPER_PIN_2 #
#define TR_STEPPER_PIN_3 #
#define TR_STEPPER_PIN_4 #

//bottom left corner motor
#define BL_STEPPER_PIN_1 #
#define BL_STEPPER_PIN_2 #
#define BL_STEPPER_PIN_3 #
#define BL_STEPPER_PIN_4 #

//bottom right corner motor
#define BR_STEPPER_PIN_1 #
#define BR_STEPPER_PIN_2 #
#define BR_STEPPER_PIN_3 #
#define BR_STEPPER_PIN_4 #


void setup() 
{
  lcd.begin(16, 2);
  Serial.begin(9600);

  pinMode(TL_STEPPER_PIN_1, OUTPUT);
  pinMode(TL_STEPPER_PIN_2, OUTPUT);
  pinMode(TL_STEPPER_PIN_3, OUTPUT);
  pinMode(TL_STEPPER_PIN_4, OUTPUT);

  pinMode(TR_STEPPER_PIN_1, OUTPUT);
  pinMode(TR_STEPPER_PIN_2, OUTPUT);
  pinMode(TR_STEPPER_PIN_3, OUTPUT);
  pinMode(TR_STEPPER_PIN_4, OUTPUT);

  pinMode(BL_STEPPER_PIN_1, OUTPUT);
  pinMode(BL_STEPPER_PIN_2, OUTPUT);
  pinMode(BL_STEPPER_PIN_3, OUTPUT);
  pinMode(BL_STEPPER_PIN_4, OUTPUT);

  pinMode(BR_STEPPER_PIN_1, OUTPUT);
  pinMode(BR_STEPPER_PIN_2, OUTPUT);
  pinMode(BR_STEPPER_PIN_3, OUTPUT);
  pinMode(BR_STEPPER_PIN_4, OUTPUT);


}

void loop() 
{

  lcd.setCursor(0,0);
  lcd.print("Enter Password:");
  
  pressedKey = matrixKeypad.getKey();

  if (pressedKey)
  {
    User_input[inputCounter] = pressedKey;
    lcd.setCursor(inputCounter, 1);
    lcd.print(User_input[inputCounter]);
    Serial.println(User_input[inputCounter]);
    inputCounter++;
  }

  if (inputCounter == Password_length-1)
  {
    lcd.clear();

    
    }
  }
  
}

void TopLeft()
{
  
