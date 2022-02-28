
#include "Target.h"
#include "Sprites.h"

#include <ssd1306xled.h>
#include <font6x8.h>

Target::Target(uint8_t _size, uint8_t _speed, uint8_t _x0, uint8_t _y0)
{
  this->size = _size;                        // the size of the target (8, 16 or 32)
  this->speed = _speed;                      // the speed which the target moves at (1-25)
  this->x0 = _x0;                            // x coordinate of the top left corner
  this->y0 = _y0;                            // y coordinate of the top left corner
  this->x1 = _x0 + _size;                    // x coordinate of the bottom right corner 
  this->y1 = _y0 + (_size / 8);              // y coordinate of the bottom right corner

  this->active = true;                       // whether the target is moving or inactive (shot)
  this->dir = 0;                             // direction of travel (0=right  1=left)
}

//---------------------------------------------------------------------------------------------------------------------------------------------------
bool Target::isActive()
{
  return active;                                                     
}

//---------------------------------------------------------------------------------------------------------------------------------------------------
// updates the position of the target based on where it is moving
void Target::updateTarget()                   
{
  if (dir == 0)                            // if moving right
  {
    if (x1 < (screenWidth - speed))        // if within the bounds of the screen
    {
      x0 = x0 + speed;                     // move the target to the right (distance depends on the speed of the target)
      x1 = x0 + size;                      // update the bottom right coordinate                          
    }
    else                                   // if the target will go out of bounds
    {
      dir = 1;                             // change direction (go left)
    }
  }
  
  if (dir == 1)                            // if moving left
  {
    if (x0 > (0 + speed))                  // if within the bounds of the screen
    {
      x0 = x0 - speed;                     // move the target to the left (distance depends on the speed of the target) 
      x1 = x0 + size;                      // update the bottom right coordinate                           
    }
    else                                   // if the target will go out of bounds 
    {
      dir = 0;                             // change direction (go left)
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------------------------------------
void Target::drawTarget()
{ 
  if (size == 8)  
    SSD1306.ssd1306_draw_bmp(x0, y0, x1, y1, smallTarget);
  if (size == 16) 
    SSD1306.ssd1306_draw_bmp(x0, y0, x1, y1, mediumTarget);
  if (size == 32) 
    SSD1306.ssd1306_draw_bmp(x0, y0, x1, y1, largeTarget);  
}

//---------------------------------------------------------------------------------------------------------------------------------------------------
void Target::drawBlank()
{
  if (size == 8)  
    SSD1306.ssd1306_draw_bmp(x0, y0, x1, y1, smallBlank);
  if (size == 16) 
    SSD1306.ssd1306_draw_bmp(x0, y0, x1, y1, mediumBlank);
  if (size == 32) 
    SSD1306.ssd1306_draw_bmp(x0, y0, x1, y1, largeBlank);                                           
}
