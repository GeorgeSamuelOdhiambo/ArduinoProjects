#include <dht.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
dht DHT;
#define DHT11_PIN 7
int anlogPin = A0;
int anlogPin1 = A1;
void setup(){
 pinMode(anlogPin, INPUT);
 pinMode(anlogPin1, INPUT);
 pinMode(8, OUTPUT);
 pinMode(13, OUTPUT);
 Serial.begin(9600);
 lcd.begin(16,2);
}
void loop(){
 int coread = analogRead(anlogPin);
 int co2read = analogRead(anlogPin1);
 int chk = DHT.read11(DHT11_PIN);
 COread(coread);
 int tem = DHT.temperature;
 int hum = DHT.humidity; 
 tempread(tem);
 lcd.setCursor(0,0);

 lcd.print("TEM"); lcd.print(" "); lcd.print("HUM");lcd.print(" ");lcd.print("CO");lcd.print(" ");lcd.print("CO2");
 lcd.setCursor(0,1);
 lcd.print(tem); lcd.print(" "); lcd.print(hum); lcd.print(" "); lcd.print(coread); lcd.print(" "); lcd.print(co2read); 
 delay(1000);
}
void tempread(int tempvalue){
 if(tempvalue < 28){
 digitalWrite(10, HIGH);
 }
 else if(tempvalue >= 30){
 digitalWrite (10, LOW);
 digitalWrite(8, HIGH);
 digitalWrite(13, LOW);
 }
 else{
 digitalWrite(10, LOW);
 digitalWrite(8, LOW);
 digitalWrite(13, LOW);
 
 }
}
void COread(intcovalue){}
