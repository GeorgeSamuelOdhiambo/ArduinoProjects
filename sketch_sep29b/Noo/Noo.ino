#include <DHT.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define DHTPIN 7
#define DHTTYPE DHT11

DHT dht(DHTPIN,DHTTYPE);

int anlogPin = A0;
int anlogPin1 = A1;
void setup(){
 pinMode(anlogPin, INPUT);
 pinMode(anlogPin1, INPUT);
 pinMode(8, OUTPUT);
 pinMode(13, OUTPUT);
 pinMode(9, OUTPUT);
 pinMode(6, OUTPUT);
 Serial.begin(9600);
 dht.begin();
 lcd.begin(16,2);
}
void loop(){
 int coread = analogRead(anlogPin);
 int co2read = analogRead(anlogPin1);

 COread(coread);
 CO2read(co2read);
 int tem = dht.readTemperature();
 int hum = dht.readHumidity(); 
 tempread(tem);
 lcd.setCursor(0,0);

 lcd.print("TEM"); lcd.print(" "); lcd.print("HUM");lcd.print(" ");lcd.print("CO");lcd.print(" ");lcd.print("CO2");
 lcd.setCursor(0,1);
 lcd.print(tem); lcd.print(" "); lcd.print(hum); lcd.print(" "); lcd.print(coread); lcd.print(" "); lcd.print(co2read); 
 delay(5000);
}
void tempread(int tempvalue){
 if(tempvalue < 15){
 digitalWrite(10, HIGH);
 }
 else if(tempvalue >= 28){
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
void COread(int intcovalue){
  Serial.print(intcovalue);
  if(intcovalue > 450){digitalWrite (9, HIGH); }
  
  else{ digitalWrite(9,LOW);}
 }

 void CO2read(int intcovalue){
  Serial.print(intcovalue);
  if(intcovalue > 500){digitalWrite (6, HIGH); }
  
  else{ digitalWrite(6,LOW);}
 }
