/*
  DisplayCounter.ino - Example for displaying large numbers on LCD displays with I2C using the HD44780 driver.
  Displays the number of seconds since last boot on the display.
  	
  The circuit:
  * LCD SDA pin to digital pin A4
  * LCD SCL pin to digital pin A5
  * LCD VCC pin to digital pin VCC(Either 3 or 5V depending on LCD type)
  * LCD GND pin to digital pin GND
 
  Copyright (C) 2019 Anush DP
 
  License: GPL3 <http://www.gnu.org/licenses/>.
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
