#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
 
void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);
  delay(1000);
  lcd.setCursor(0, 0);
  lcd.print("IRRIGATION");
  lcd.setCursor(0, 1);
  lcd.print("SYSTEM IS ON ");
    lcd.print("");
    delay(3000);
  lcd.clear();
}
 
void loop() {
  int value = analogRead(A0);
  Serial.println(value);
  lcd.clear();
  if (value >= 950) {
    digitalWrite(2, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("Water Your Plants");
    lcd.setCursor(0, 1);
    lcd.print("Moisture : LOW ");
  } 
  if (value <= 350) {
    digitalWrite(2, LOW);
    lcd.setCursor(0, 0);
    lcd.print("Moisture is OK");
    lcd.setCursor(0, 1);
    lcd.print("Moisture : HIGH");
  } else if (value > 350 && value < 950) {
    digitalWrite(2, LOW);
    lcd.setCursor(0, 0);
    lcd.print("Moisture is OK");
    lcd.setCursor(0, 1);
    lcd.print("Moisture : MID ");
  }
  delay(1000);
}