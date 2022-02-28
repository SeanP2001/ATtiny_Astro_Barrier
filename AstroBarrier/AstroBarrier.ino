//---------------------------------------------------------------------------------------------------------------------------------------------------
// ATtiny: Astro Barrier
// Sean Price
// V0.1.0
//---------------------------------------------------------------------------------------------------------------------------------------------------


#include <ssd1306xled.h>
#include <font6x8.h>

#include "Button.h"
#include "Target.h"

#define actionButtons A3
#define directionButtons A2

// CONSTRUCTOR Button(pinNo, lowerBound, upperBound)
Button LEFT(directionButtons, 230, 255);
Button RIGHT(directionButtons, 50, 67);
Button A(actionButtons, 125, 255);

// CONSTRUCTOR Target(targetSize, targetSpeed, topLeftXCoord, topLeftYCoord)
Target t1(32, 3, 0, 0);     
Target t2(16, 5, 0, 4);
Target t3(8, 9, 0, 6);

//---------------------------------------------------------------------------------------------------------------------------------------------------
void setup() {
  SSD1306.ssd1306_init();             
  SSD1306.ssd1306_fillscreen(0x00);   // clear the screen
}

//---------------------------------------------------------------------------------------------------------------------------------------------------
void loop() {
  t1.drawTarget();
  t2.drawTarget();
  t3.drawTarget();
  delay(50);
   
  if (t1.isActive())
  {
    t1.drawBlank();
    t1.updateTarget();
  }
  if (t2.isActive())
  {
    t2.drawBlank();
    t2.updateTarget();
  }
  if (t3.isActive())
  {
    t3.drawBlank();
    t3.updateTarget();
  }
}
