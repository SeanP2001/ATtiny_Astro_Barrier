
#include "Screens.h"

#include <ssd1306xled.h>
#include <font6x8.h>

//---------------------------------------------------------------------------------------------------------------------------------------------------
void levelScreen(uint8_t levelNo, uint8_t noOfBullets)
{
  char bulletsStr[1];
  char levelStr[2];

  SSD1306.ssd1306_fillscreen(0x00);                              // clear the screen

  SSD1306.ssd1306_setpos(40, 4);
  SSD1306.ssd1306_string_font6x8("Level ");
  itoa(levelNo, levelStr, 10);
  SSD1306.ssd1306_string_font6x8(levelStr);
  SSD1306.ssd1306_setpos(32, 5);
  
  itoa(noOfBullets, bulletsStr, 10);  
  SSD1306.ssd1306_string_font6x8(bulletsStr);
  SSD1306.ssd1306_string_font6x8("x Bullets");
}

//---------------------------------------------------------------------------------------------------------------------------------------------------
void levelCompleteScreen(int score)
{  
  SSD1306.ssd1306_fillscreen(0x00);
  SSD1306.ssd1306_setpos(16, 3);
  SSD1306.ssd1306_string_font6x8("Level Complete");

  SSD1306.ssd1306_setpos(32, 5);
  printScore(score);
}

//---------------------------------------------------------------------------------------------------------------------------------------------------
void gameOverScreen(int score)
{
  SSD1306.ssd1306_fillscreen(0x00);
  SSD1306.ssd1306_setpos(32, 3);
  SSD1306.ssd1306_string_font6x8("Game Over");

  SSD1306.ssd1306_setpos(32, 5);
  printScore(score);
}

//---------------------------------------------------------------------------------------------------------------------------------------------------
void gameCompleteScreen(int score)
{
  SSD1306.ssd1306_fillscreen(0x00);
  SSD1306.ssd1306_setpos(16, 3);
  SSD1306.ssd1306_string_font6x8("Game Complete");

  SSD1306.ssd1306_setpos(32, 5);
  printScore(score);
}

void printScore(int score)
{
  char scoreStr[5];
  
  SSD1306.ssd1306_string_font6x8("Score: ");
  itoa(score, scoreStr, 10);  
  SSD1306.ssd1306_string_font6x8(scoreStr);
}
