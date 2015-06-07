#include <MyLiquidCrystal.h>


//Creating MyLiquidCrystal Object, constructor same as  LiquidCrystal
MyLiquidCrystal myLcd(2, 3, 4, 5, 6, 7);


void setup()
{
  //Initializing the lcd module, set_lcd calls begin method so don't need to call lcd.begin
  
  myLcd.set_lcd(16, 4);
  
  //String scroll method
  myLcd.word_scroll("Manash", 100);
}

void loop()
{
  
}