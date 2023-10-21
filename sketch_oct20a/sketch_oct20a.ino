#include <Keypad.h>
#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

Servo myservo;
LiquidCrystal_I2C lcd(0x27, 16, 2);

int pos = 0;
const byte rows = 4;
const byte cols = 4;

char key[rows][cols] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};
byte rowPins[rows] = {13, 12, 7, 6};
byte colPins[cols] = {5, 4, 3, 2};
Keypad keypad = Keypad(makeKeymap(key), rowPins, colPins, rows, cols);
char password[] = "1234";
char inputpass[4];
int currentposition = 0;
int invalidcount = 12;

void setup()
{
    Serial.begin(9600);
    lcd.begin();
}

void loop()
{
    if (currentposition == 0)
    {
        displayscreen();
    }
    int l;
    char code = keypad.getKey();
    if (code != NO_KEY)
    {
        if (code == "#")
        {
            currentposition += 1;
            Serial.println(code);
            if (currentposition == 1)
            {
                displayscreenpass();
            }
        }

        else if (code == "*")
        {
            currentposition += 1;
            Serial.println(code);
            if (currentposition == 1)
            {
                displayscreenress();
            }
        }
    }
}

//************** CLEAR THE SCREEN!!!*************//
void clearscreen()
{
    lcd.setCursor(0, 0);
    lcd.println(" ");
    lcd.setCursor(0, 1);
    lcd.println(" ");
    lcd.setCursor(0, 2);
    lcd.println(" ");
    lcd.setCursor(0, 3);
    lcd.println(" ");
}

//********DISPALAY FUNCTION!!!*************//
void displayscreen()
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.println(" E-PASS ");
    lcd.setCursor(8, 0);
    lcd.println("RESET-P ");
    lcd.setCursor(3, 1);
    lcd.println("#       ");
    lcd.setCursor(11, 1);
    lcd.println("*     ");
}

//********DISPALAY FUNCTION!!!*************//
void displayscreenpass()
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.println("*ENTER THE CODE*");
    lcd.setCursor(1, 1);
    lcd.println("TO _/_ (OPEN)!!");
}

void displayscreenress()
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.println("*ENTER SECURITY PIN*");
}
