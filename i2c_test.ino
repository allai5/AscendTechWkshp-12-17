/*  ___   ___  ___  _   _  ___   ___   ____ ___  ____  
 * / _ \ /___)/ _ \| | | |/ _ \ / _ \ / ___) _ \|    \ 
 *| |_| |___ | |_| | |_| | |_| | |_| ( (__| |_| | | | |
 * \___/(___/ \___/ \__  |\___/ \___(_)____)___/|_|_|_|
 *                  (____/    
 * www.osoyoo.com IC2 Liquid Crysal Testing program
 * program tutorial : http://osoyoo.com/?p=72
 *  Copyright John Yu
 */
   
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
 
LiquidCrystal_I2C lcd(0x3f,16,2);  // run ic2_scanner sketch and get the IC2 address, which is 0x3f in my case,it could be 0x3f in many cases
 
void setup()
{
  Serial.begin(9600);
  lcd.init();                      // initialize the lcd
  lcd.backlight();
  lcd.setCursor(0,0);
}

 

 
void loop()
{
  if (Serial.available()) {
      char input = Serial.read();
      lcd.print(input);
      
    
  }
}
