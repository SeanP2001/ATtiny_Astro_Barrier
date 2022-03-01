//---------------------------------------------------------------------------------------------------------------------------------------------------
// ATtiny: Astro Barrier
// Sean Price
// V0.3.0
//---------------------------------------------------------------------------------------------------------------------------------------------------


#include <ssd1306xled.h>
#include <font6x8.h>

#include "Button.h"
#include "Target.h"
#include "Player.h"
#include "Bullet.h"

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

Player player;

Bullet bullet;

//---------------------------------------------------------------------------------------------------------------------------------------------------
void setup() {
  SSD1306.ssd1306_init();             
  SSD1306.ssd1306_fillscreen(0x00);   // clear the screen
}

//---------------------------------------------------------------------------------------------------------------------------------------------------
void loop() 
{
  if (bullet.fired)
  {
    bullet.drawBullet();
  }
  
  t1.drawTarget();
  t2.drawTarget();
  t3.drawTarget();
  
  player.drawPlayer();
  
  delay(50);

  if (LEFT.isPressed())
  {
    player.drawBlank();
    player.moveLeft();
  }
  if (RIGHT.isPressed())
  {
    player.drawBlank();
    player.moveRight();
  }
  if (A.isPressed() && !bullet.fired)
  {
    bullet.fire((player.playerX0 + 3), (player.playerX1 - 3)); 
  }


  if (bullet.fired)
  {
    bullet.drawBlank();

    if (bullet.inRange(t1.x0, t1.y0, t1.x1, t1.y1))        // if the bullet is in t1's hitbox
    {
      t1.isHit();
      bullet.reload();
    }
     
    else if (bullet.inRange(t2.x0, t2.y0, t2.x1, t2.y1))   // if the bullet is in t2's hitbox
    {
      t2.isHit();
      bullet.reload();
    }
    
    else if (bullet.inRange(t3.x0, t3.y0, t3.x1, t3.y1))   // if the bullet is in t3's hitbox
    {
      t3.isHit();
      bullet.reload();
    }

    else
    {
      bullet.updateBullet();
    }    
  }
  
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
