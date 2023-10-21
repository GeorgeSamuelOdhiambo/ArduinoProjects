///////[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[ca]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]].///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <Keypad.h>////////////////////////////////////////////////////////////...................
/#include <Servo.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

Servo myservo;
LiquidCrystal_I2C lcd(0x27, 16, 2);

int pos=0;
const byte rows=4;
const byte cols=4;
 
char key[rows][cols]={
{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}
};
byte rowPins[rows]={13,12,7,6};
byte colPins[cols]={5,4,3,2};
Keypad keypad= Keypa//////d/(makeKeymap(key),rowPins,colPins,rows,cols);
char password[] = "1234";
char passwordsec[] = "BBBB";
char inputpass[4];
char inputpassre[4];
char chekop[] = "*#1234B789";
int currentposition=0;
int currentposi = 0;
int redled=10;
int greenled=11;
int buzz=8;
int invalidcount=12;
 
 
 
void setup()
{
displayscreen();
Serial.begin(9600);
pinMode(redled, OUTPUT);
pinMode(greenled, OUTPUT);
pinMode(buzz, OUTPUT);
myservo.attach(9); //SERVO ATTACHED//
lcd.begin();
}
 
void loop(){
if( currentposition==0){
displayscreenone();
}

int l ;
char code=keypad.getKey();
if(code != NO_KEY && code == chekop[0] || code == chekop[2] || code == chekop[3] || code == chekop[4] || code == chekop[5]){
    ++currentposition;
   if(currentposition == 1){  
       displayscreen(); 
       }
   Serial.print(currentposition);
    if(code != NO_KEY && currentposition > 1){
        Serial.print("Invalid Input");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("PASSWORD:");
    lcd.setCursor(7,1);
    lcd.print(" ");
    lcd.setCursor(7,1);
 for(l=0;l<=currentposi;++l){
 lcd.print("*");
 keypress();
 }
 
 if (code){
    inputpass[currentposi] = code;
    ++currentposi; 

 if(currentposi == 4){
  if(password[0] == inputpass[0] && password[1] == inputpass[1] && password[2] == inputpass[2] && password[3] == inputpass[3]){
 Serial.print("Valid input");
 unlockdoor();
 currentposition=0;
 currentposi = 0;
 }
 else{
  Serial.print("Ati Invalid");
  ++invalidcount;
  incorrect();
  currentposition=0;
  currentposi = 0;
}}
} 
    }
}

if(code != NO_KEY && code == chekop[1] || code == chekop[6]){
     ++currentposition;
   if(currentposition == 1){  
       displayscreenreset(); 
       }
   Serial.print(currentposition);
    if(code != NO_KEY && currentposition > 1){
        Serial.print("Invalid Input");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("SEC_KEY:");
    lcd.setCursor(7,1);
    lcd.print(" ");
    lcd.setCursor(7,1);
for(l=0;l<=currentposi;++l){
lcd.print(code);
keypress();
}
 
if (code){
    inputpassre[currentposi] = code;
    ++currentposi; 

if(currentposi == 4){
  if(passwordsec[0] == inputpassre[0] && passwordsec[1] == inputpassre[1] && passwordsec[2] == inputpassre[2] && passwordsec[3] == inputpassre[3]){
 Serial.print("Valid input");
 
#include <Keypad.h>
#include <Servo.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

Servo myservo;
LiquidCrystal_I2C lcd(0x27, 16, 2);

int pos=0;
const byte rows=4;
const byte cols=4;
 
char key[rows][cols]={
{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}
};
byte rowPins[rows]={13,12,7,6};
byte colPins[cols]={5,4,3,2};
Keypad keypad= Keypad(makeKeymap(key),rowPins,colPins,rows,cols);
char password[] = "1234";
char passwordsec[] = "BBBB";
char inputpass[4];
char inputpassre[4];
char chekop[] = "*#1234B789";
int currentposition=0;
int currentposi = 0;
int redled=10;
int greenled=11;
int buzz=8;
int invalidcount=12;
 
 
 
void setup()
{
displayscreen();
Serial.begin(9600);
pinMode(redled, OUTPUT);
pinMode(greenled, OUTPUT);
pinMode(buzz, OUTPUT);
myservo.attach(9); //SERVO ATTACHED//
lcd.begin();
}
 
void loop(){
if( currentposition==0){
displayscreenone();
}

int l ;
char code=keypad.getKey();
if(code != NO_KEY && code == chekop[0] || code == chekop[2] || code == chekop[3] || code == chekop[4] || code == chekop[5]){
    ++currentposition;
   if(currentposition == 1){  
       displayscreen(); 
       }
   Serial.print(currentposition);
    if(code != NO_KEY && currentposition > 1){
        Serial.print("Invalid Input");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("PASSWORD:");
    lcd.setCursor(7,1);
    lcd.print(" ");
    lcd.setCursor(7,1);
 for(l=0;l<=currentposi;++l){
 lcd.print("*");
 keypress();
 }
 
 if (code){
    inputpass[currentposi] = code;
    ++currentposi; 

 if(currentposi == 4){
  if(password[0] == inputpass[0] && password[1] == inputpass[1] && password[2] == inputpass[2] && password[3] == inputpass[3]){
 Serial.print("Valid input");
 unlockdoor();
 currentposition=0;
 currentposi = 0;
 }
 else{
  Serial.print("Ati Invalid");
  ++invalidcount;
  incorrect();
  currentposition=0;
  currentposi = 0;
}}
} 
    }
}

if(code != NO_KEY && code == chekop[1] || code == chekop[6]){
     ++currentposition;
   if(currentposition == 1){  
       displayscreenreset(); 
       }
   Serial.print(currentposition);
    if(code != NO_KEY && currentposition > 1){
        Serial.print("Invalid Input");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("SEC_KEY:");
    lcd.setCursor(7,1);
    lcd.print(" ");
    lcd.setCursor(7,1);
for(l=0;l<=currentposi;++l){
lcd.print(code);
keypress();
}
 
if (code){
    inputpassre[currentposi] = code;
    ++currentposi; 

if(currentposi == 4){
  if(passwordsec[0] == inputpassre[0] && passwordsec[1] == inputpassre[1] && passwordsec[2] == inputpassre[2] && passwordsec[3] == inputpassre[3]){
 Serial.print("Valid input");
 unlockdoor();
 currentposition=0;
 currentposi = 0;
 }
 else{
  Serial.print("Ati Invalid");
  ++invalidcount;
  incorrect();
  currentposition=0;
  currentposi = 0;
}}
} 
    }
}

if(code != NO_KEY && code != chekop[0] && code != chekop[1] && code != chekop[2] && code != chekop[3] && code != chekop[4] && code != chekop[5] && code != chekop[6]){
   
   ++currentposition;
   if(currentposition == 1){  
   lcd.setCursor(0,0);
   lcd.println("*INVALID INPUT*");
   lcd.setCursor(1 ,1); 
   lcd.println("Try Again"); 
       }
       delay(2500);
   currentposition = 0;
}
// LOOP ENDS!!!//
}

//********OPEN THE DOOR FUNCTION!!!!***********//
 
void unlockdoor(){

delay(900);
lcd.setCursor(0,0);
lcd.println(" ");
lcd.setCursor(1,0);
lcd.print("Access Granted");
lcd.setCursor(4,1);
lcd.println("WELCOME!!");
lcd.setCursor(15,1);
lcd.println(" ");
lcd.setCursor(16,1);
lcd.println(" ");
lcd.setCursor(14,1);
lcd.println(" ");
lcd.setCursor(13,1);
lcd.println(" ");
unlockbuzz();
 
for(pos = 180; pos>=0; pos-=5) // goes from 180 degrees to 0 degrees
{
myservo.write(pos); // tell servo to go to position in variable 'pos'
delay(100); // waits 15ms for the servo to reach the position
}
 
for(pos = 0; pos <= 180; pos +=5) // goes from 0 degrees to 180 degrees
{ // in steps of 1 degree
myservo.write(pos); // tell servo to go to position in variable 'pos'
delay(1000);
lcd.setCursor(0,0);
lcd.println(" ");
lcd.setCursor(1,0);
lcd.print("ENTER, RELOCKING");
lcd.setCursor(4,1);
lcd.println("INITIATED");
lcd.setCursor(15,1);
lcd.println(" ");
lcd.setCursor(16,1);
lcd.println(" ");
lcd.setCursor(14,1);
lcd.println(" ");
lcd.setCursor(13,1);
lcd.println(" ");
}
 
currentposition=0;
lcd.clear();
displayscreen();
}
 
//************WRONG CODE FUNCTION********//
 
void incorrect()
{
delay(500);
lcd.clear();
lcd.setCursor(1,0);
lcd.print("PASSWORD");
lcd.setCursor(6,0);
lcd.print(" INCORRECT");
lcd.setCursor(15,1);
lcd.println(" ");
lcd.setCursor(4,1);
lcd.println("ACCESS!!!");
 
lcd.setCursor(13,1);
lcd.println(" ");
Serial.println("ACCESS DENAYED");
digitalWrite(redled, HIGH);
digitalWrite(buzz, HIGH);
delay(3000);
lcd.clear();
digitalWrite(redled, LOW);
digitalWrite(buzz,LOW);
displayscreen();
}
//************** CLEAR THE SCREEN!!!*************//
void clearscreen()
{
lcd.setCursor(0,0);
lcd.println(" ");
lcd.setCursor(0,1);
lcd.println(" ");
lcd.setCursor(0,2);
lcd.println(" ");
lcd.setCursor(0,3);
lcd.println(" ");
}
//**************KEYPRESS********************//
void keypress()
{
 
 
 
digitalWrite(buzz, HIGH);
delay(50);
digitalWrite(buzz, LOW);
}
//********DISPALAY FUNCTION!!!*************//
void displayscreen()
{
 
lcd.setCursor(0,0);
lcd.println("*ENTER THE CODE*");
lcd.setCursor(1 ,1); 
lcd.println("TO _/_ (OPEN)!!");
}

void displayscreenreset(){
    lcd.setCursor(0,0);
    lcd.println("*Verify its you*");
lcd.setCursor(1 ,1); 
lcd.println("ent sec pass");
}

void displayscreenone(){
    lcd.setCursor(0,0);
    lcd.println("TO-OPEN           ");
    lcd.setCursor(8,0);
    lcd.println("RESET-P           ");
    lcd.setCursor(2 ,1);
    lcd.println("*                             ");
    lcd.setCursor(10 ,1);
    lcd.println("#                            ");
}

//**********UNLOCK BUZZ*************//
void unlockbuzz()
{
 
digitalWrite(buzz, HIGH);
delay(80);
digitalWrite(buzz, LOW);
delay(80);
digitalWrite(buzz, HIGH);
delay(80);
digitalWrite(buzz, LOW);
delay(200);
digitalWrite(buzz, HIGH);
delay(80);
digitalWrite(buzz, LOW);
delay(80);
digitalWrite(buzz, HIGH);
delay(80);
digitalWrite(buzz, LOW);
delay(80);
}
 
 unlockdoor();
 currentposition=0;
 currentposi = 0;
 }
 else{
  Serial.print("Ati Invalid");
  ++invalidcount;
  incorrect();
  currentposition=0;
  currentposi = 0;
}}
} 
    }
}

if(code != NO_KEY && code != chekop[0] && code != chekop[1] && code != chekop[2] && code != chekop[3] && code != chekop[4] && code != chekop[5] && code != chekop[6]){
   
   ++currentposition;
   if(currentposition == 1){  
   lcd.setCursor(0,0);
   lcd.println("*INVALID INPUT*");
   lcd.setCursor(1 ,1); 
   lcd.println("Try Again"); 
       }
       delay(2500);
   currentposition = 0;
}
// LOOP ENDS!!!//
}

//********OPEN THE DOOR FUNCTION!!!!***********//
 
void unlockdoor(){

delay(900);
lcd.setCursor(0,0);
lcd.println(" ");
lcd.setCursor(1,0);
lcd.print("Access Granted");
lcd.setCursor(4,1);
lcd.println("WELCOME!!");
lcd.setCursor(15,1);
lcd.println(" ");
lcd.setCursor(16,1);
lcd.println(" ");
lcd.setCursor(14,1);
lcd.println(" ");
lcd.setCursor(13,1);
lcd.println(" ");
unlockbuzz();
 
for(pos = 180; pos>=0; pos-=5) // goes from 180 degrees to 0 degrees
{
myservo.write(pos); // tell servo to go to position in variable 'pos'
delay(100); // waits 15ms for the servo to reach the position
}
 
for(pos = 0; pos <= 180; pos +=5) // goes from 0 degrees to 180 degrees
{ // in steps of 1 degree
myservo.write(pos); // tell servo to go to position in variable 'pos'
delay(1000);
lcd.setCursor(0,0);
lcd.println(" ");
lcd.setCursor(1,0);
lcd.print("ENTER, RELOCKING");
lcd.setCursor(4,1);
lcd.println("INITIATED");
lcd.setCursor(15,1);
lcd.println(" ");
lcd.setCursor(16,1);
lcd.println(" ");
lcd.setCursor(14,1);
lcd.println(" ");
lcd.setCursor(13,1);
lcd.println(" ");
}
 
currentposition=0;
lcd.clear();
displayscreen();
}
 
//************WRONG CODE FUNCTION********//
 
void incorrect()
{
delay(500);
lcd.clear();
lcd.setCursor(1,0);
lcd.print("PASSWORD");
lcd.setCursor(6,0);
lcd.print(" INCORRECT");
lcd.setCursor(15,1);
lcd.println(" ");
lcd.setCursor(4,1);
lcd.println("ACCESS!!!");
 
lcd.setCursor(13,1);
lcd.println(" ");
Serial.println("ACCESS DENAYED");
digitalWrite(redled, HIGH);
digitalWrite(buzz, HIGH);
delay(3000);
lcd.clear();
digitalWrite(redled, LOW);
digitalWrite(buzz,LOW);
displayscreen();
}
//************** CLEAR THE SCREEN!!!*************//
void clearscreen()
{
lcd.setCursor(0,0);
lcd.println(" ");
lcd.setCursor(0,1);
lcd.println(" ");
lcd.setCursor(0,2);
lcd.println(" ");
lcd.setCursor(0,3);
lcd.println(" ");
}
//**************KEYPRESS********************//
void keypress()
{
 
 
 
digitalWrite(buzz, HIGH);
delay(50);
digitalWrite(buzz, LOW);
}
//********DISPALAY FUNCTION!!!*************//
void displayscreen()
{
 
lcd.setCursor(0,0);
lcd.println("*ENTER THE CODE*");
lcd.setCursor(1 ,1); 
lcd.println("TO _/_ (OPEN)!!");
}

void displayscreenreset(){
    lcd.setCursor(0,0);
    lcd.println("*Verify its you*");
lcd.setCursor(1 ,1); 
lcd.println("ent sec pass");
}

void displayscreenone(){
    lcd.setCursor(0,0);
    lcd.println("TO-OPEN           ");
    lcd.setCursor(8,0);
    lcd.println("RESET-P           ");
    lcd.setCursor(2 ,1);
    lcd.println("*                             ");
    lcd.setCursor(10 ,1);
    lcd.println("#                            ");
}

//**********UNLOCK BUZZ*************//
void unlockbuzz()
{
 
digitalWrite(buzz, HIGH);
delay(80);
digitalWrite(buzz, LOW);
delay(80);
digitalWrite(buzz, HIGH);
delay(80);
digitalWrite(buzz, LOW);
delay(200);
digitalWrite(buzz, HIGH);
delay(80);
digitalWrite(buzz, LOW);
delay(80);
digitalWrite(buzz, HIGH);
delay(80);
digitalWrite(buzz, LOW);
delay(80);
}
 