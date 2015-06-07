#include "MyLiquidCrystal.h"

//Initialize LCD
void MyLiquidCrystal::set_lcd(byte col, byte row)
{
    lcdRows = row;
    lcdCols = col;
    begin(col, row);
}

//Getting Rows and Columns
byte MyLiquidCrystal::get_col(void)
{
    return lcdCols;
}

byte MyLiquidCrystal::get_row(void)
{
    return lcdRows;
}

//Getting Current Distance
//It is measured from the first character of the string upto the boundary

byte MyLiquidCrystal::get_distance(void)
{

    return get_col() + 1 - x;
}

//Function that actually does the scrolling
void MyLiquidCrystal::word_scroll(char *str, byte del)
{
    //Getting the string length
    wordLength = strlen(str);
    scrollDelay = del;

    //Getting row and column
    byte maxCol = get_col();
    byte maxRow = get_row();

    //Infinite Loop [You have to customize and solve it]
    //Buggy code
    while (true){
        if (get_distance() >= wordLength){

            /* Algorithm
             * -> Check if the distance is greater or equal to the wordlength
             * -> set Cursor at a coordinate
             * -> Print the string
             * -> wait about delay time
             * -> clear the lcd
             * -> Increase x one character
             * -> Check if the word is at boundary
             * -> if it's in the boundary then increase y and set x = 0
             * -> follow the  algorithm from beginning
             * */
            setCursor(x, y);
            print(str);
            delay(scrollDelay);
            clear();
            x++;
            if (get_distance() == wordLength)
            {
                x = 0;
                y++;
            }
        }

        //If the cursor is at the bottom then setting the cursor at the beginning
        if(y == maxRow) {x = 0; y = 0;}
    }
}
