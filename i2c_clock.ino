
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
 
LiquidCrystal_I2C lcd(0x3F,16,2);  // run ic2_scanner sketch and get the IC2 address, which is 0x3f in my case,it could be 0x3f in many cases
 
void setup()
{
  Serial.begin(9600);
  lcd.init();                      // initialize the lcd
  lcd.backlight();
  lcd.setCursor(0,0);

String ttime = "3PM";

    
  
  if (ttime.length() > 16) {
    for (int i = 0; i < 16; i++) {
      lcd.print(ttime.charAt(i));
    }
    lcd.setCursor(0,1);
    
    for (int i = 16; i < ttime.length(); i++) {
      lcd.print(ttime.charAt(i));
    
      
  }
  }

  else {
      for (int i = 0; i < ttime.length(); i++) {
        lcd.print(ttime.charAt(i));
      } 

      lcd.setCursor(ttime.length(),0);
    
    }

    free(&ttime);

}

 
void loop()
{
    
      
      

}
