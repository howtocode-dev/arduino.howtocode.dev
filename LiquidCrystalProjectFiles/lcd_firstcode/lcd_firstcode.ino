#include <LiquidCrystal.h>

//LCD Dimension
#define COLS 16
#define ROWS 4

//Creating global LCD Object
LiquidCrystal my_lcd(2, 3, 4, 5, 6, 7);

void setup()
{
    //Setting up the LCD
    my_lcd.begin(COLS, ROWS);
    
    //Setting the cursor at the beginning 
    my_lcd.setCursor(0, 0);
    
    //Printing a string on the lcd
    my_lcd.print("Electroscholars");
}

void loop() {}
