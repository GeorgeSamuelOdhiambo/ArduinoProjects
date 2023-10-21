#include <Adafruit_GFX.h>        //OLED libraries
#include <Adafruit_SSD1306.h>
#include <Wire.h>
#include "MAX30105.h"           //MAX3010x library
#include "heartRate.h" 


int count=0,i=0,k=0,rate=0;

unsigned long time2,time1;
unsigned long time;

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_RESET  
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET); //Declaring the display name (display)


byte heart[8] = 
{
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000
};

void setup()
{
 display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //Start the OLED display
  display.display();
  delay(3000);
  // Initialize sensor
  particleSensor.begin(Wire, I2C_SPEED_FAST); //Use default I2C port, 400kHz speed
  particleSensor.setup(); //Configure sensor with default settings
  particleSensor.setPulseAmplitudeRed(0x0A); //Turn Red LED to low to indicate sensor is running
  display.createChar(1, heart);
  display.begin(128,32);
  
  display.print("Heart Beat ");
  display.write(1);
  display.setCursor(0,1);
  display.print("Monitering");
  delay(1000);
}

void loop()
{
long irValue = particleSensor.getIR();
  if(!(irValue)))
  {
    k=0;
     display.clear();
     display.print("Please wait.......");
    while(k<5)
    {
     if(irValue)
     {
      if(k==0)
      time1=millis();
      k++;
      while(irValue);
     }
    }
      time2=millis();
      rate=time2-time1;
      rate=rate/5;
      rate=60000/rate;
     display.clear();
    display.print("Heart Beat Rate:");
      display.setCursor(0,1);
      display.print(rate);
      display.print(" ");
      display.write(1);      
      k=0;
      rate=0;
    }
  if(irValue)
  {
    rate=0;
    display.clear();
      display.print("Heart Beat Rate:");
      display.setCursor(0,1);
      display.write(1);
      display.print(rate);
      k=0;
  }
}
