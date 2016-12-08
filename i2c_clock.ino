#include <DS1302.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3f,16,2); 

const int kCePin   = 5;  // Chip Enable
const int kIoPin   = 6;  // Input/Output
const int kSclkPin = 7;  // Serial Clock


DS1302 rtc(kCePin, kIoPin, kSclkPin);

void setup() {
  Serial.begin(9600);
  lcd.init();                      // initialize the lcd
  lcd.backlight();
  lcd.setCursor(0,0);

  // Initialize a new chip by turning off write protection and clearing the
  // clock halt flag. These methods needn't always be called. See the DS1302
  // datasheet for details.
  rtc.writeProtect(false);
  rtc.halt(false);

  // Make a new time object to set the date and time.
  // Sunday, September 22, 2013 at 01:38:50.
  Time t(2016, 12, 17, 3, 38, 50, Time::kSaturday);

  // Set the time and date on the chip.
  rtc.time(t);

 

  
}

// Loop and print the time every second.
void loop() {
//  Serial.println(rtc.time().formatDateTime());  //Print out the time
//  delay(1000);

 String input = rtc.time().formatDateTime();
  char input2;

  for (int i = 0; i < 16; i++) {
    input2 = input.charAt(i);
    lcd.print(input2);
  }
  
  lcd.setCursor(0,1);

  for (int j = 16; j < input.length(); j++) {
    input2 = input.charAt(j);
    lcd.print(input2);
  }

  delay(10000);
  
  
}
