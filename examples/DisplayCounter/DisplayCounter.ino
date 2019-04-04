/*
  Display_Counter.ino - Example for displaying large numbers on LCD displays using the HD44780 driver.
  Displays the number of seconds since last boot on the display.
  	
  The circuit:
  * LCD RS pin to digital pin 12
  * LCD Enable pin to digital pin 11
  * LCD D4 pin to digital pin 5
  * LCD D5 pin to digital pin 4
  * LCD D6 pin to digital pin 3
  * LCD D7 pin to digital pin 2
  * LCD R/W pin to ground
  * LCD V0 pin to digital pin 9
  * LCD backlight Anode pin to digital pin 10
 
  Copyright (C) 2019 Anush DP
 
  Lisence: GPL3 <http://www.gnu.org/licenses/>.
*/

#include <LiquidCrystal_I2C.h> 
/* You can get the LiquidCrystal_I2C library it at https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library */
#include <BigNumbers_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4); // construct LCD object
BigNumbers_I2C bigNum(&lcd); // construct BigNumbers_I2C object, passing to it the name of our LCD object

void setup()
{
  lcd.begin(); // setup LCD rows and columns
  bigNum.begin(); // set up BigNumbers
  lcd.clear(); // clear display
  
}

byte x = 0;//x & y determines position of character on screen
byte y = 0;

void loop()
{
  int currentTime = millis() / 100; // assigns the current time since boot in tenths of a second to currentTime
  byte lastDigit = currentTime % 10;
  currentTime = currentTime /= 10;
  bigNum.displayLargeInt(currentTime, x, y, 4, false);
  // print out the decimal point and the digit after it
  lcd.setCursor(12, 1);
  lcd.print(".");
  lcd.print(lastDigit);
}
