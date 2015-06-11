#ifndef MyLiquidCrystal_h
#define MyLiquidCrystal_h

//Including Necessary Header Files
#include "LiquidCrystal.h"
#include "Arduino.h"

//Naming Unsigned 8 Bit integer as "byte"
typedef uint8_t byte;

class MyLiquidCrystal : public LiquidCrystal
{
    //Properties and method goes here
private:
    //Initial Position
    byte x;
    byte y;

    //Scroll Delay
    byte scrollDelay;

    //Storing LCD Row and Column
    byte lcdRows;
    byte lcdCols;

    //Getting the string length for out of bound calculation
    byte wordLength;

    //Distance from first character to the last boundary of lcd
    byte distance;

public:

    //Function for scrolling
    void word_scroll(char *str, byte del);

    //Setting LCD Dimension
    void set_lcd(byte col, byte row);

    //Get LCD Dimension
    byte get_row(void);
    byte get_col(void);


    //Using Constructor from LiquidCrystal
    MyLiquidCrystal(byte rs, byte en, byte d4, byte d5, byte d6, byte d7) : LiquidCrystal (rs, en, d4, d5, d6, d7) { x = 0;  y = 0;}

    //Getting the distance of word
    byte get_distance(void);
};


#endif
