//---------------------------------------------------------------------------------------------------------------------------------------------------
// ATtiny: Astro Barrier
// Sean Price
// V0.5.1
//---------------------------------------------------------------------------------------------------------------------------------------------------


#include <ssd1306xled.h>
#include <font6x8.h>

#include "Button.h"
#include "Target.h"
#include "Player.h"
#include "Bullet.h"
#include "Levels.h"
#include "Screens.h"

void setupLevel(uint8_t levelNo);       // loads the level information from the Levels.h file and configures the targets
void drawTargets();                     // draws all enabled targets on the display
void showNoOfBullets();                 // show the number of remaining bullets in the corner of the display
void checkButtons();                    // checks all of the buttons for user input
void updateTargets();                   // calculates the positions of all of the targets and removes the target from the display
bool levelIsComplete();                 // checks if all of the enabled targets have been shot
bool outOfBullets();                    // checks if the player has run out of bullets


#define actionButtons A3
#define directionButtons A2

// CONSTRUCTOR Button(pinNo, lowerBound, upperBound)
Button LEFT(directionButtons, 230, 255);
Button RIGHT(directionButtons, 50, 67);
Button A(actionButtons, 125, 255);

Target t1;     
Target t2;
Target t3;

Player player;

Bullet bullet;
uint8_t noOfBullets = 3;


//---------------------------------------------------------------------------------------------------------------------------------------------------
void setup() {
  SSD1306.ssd1306_init();             
  SSD1306.ssd1306_fillscreen(0x00);   // clear the screen
}

//---------------------------------------------------------------------------------------------------------------------------------------------------
void loop() 
{
  for(uint8_t levelNo = 1; levelNo <= noOfLevels; levelNo++)       // go through every level
  {     
    setupLevel(levelNo);                                           // load the level information and configure the targets
   
    levelScreen(levelNo, noOfBullets);                             // show the level screen (includes level number and number of bullets)
    
    delay(2000);

    SSD1306.ssd1306_fillscreen(0x00);                              // clear the screen

    while((!levelIsComplete()) && (!outOfBullets()))               // loop until the level has been completed or the player runs out of bullets
    {
      showNoOfBullets();
      
      if (bullet.fired)                                            // draw the bullet if it has been fired
        bullet.drawBullet();

      drawTargets();                                               

      player.drawPlayer();
      
      delay(50);

      checkButtons();   
    
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

      updateTargets();
    }

    if (levelIsComplete())
    {
      levelCompleteScreen();
      delay(2000);
      
      if (levelNo == noOfLevels)
      {
        gameCompleteScreen();
        delay(2000); 
      }
    }
    else if (outOfBullets())
    {
      gameOverScreen();
      delay(2000);
      break;
    }
  }
    
}

//---------------------------------------------------------------------------------------------------------------------------------------------------
void setupLevel(uint8_t levelNo)
{
  noOfBullets = level[levelNo][0];
  
  t1.configure(level[levelNo][1], level[levelNo][2], level[levelNo][3], level[levelNo][4]);
  t2.configure(level[levelNo][5], level[levelNo][6], level[levelNo][7], level[levelNo][8]);
  t3.configure(level[levelNo][9], level[levelNo][10], level[levelNo][11], level[levelNo][12]);
}

//---------------------------------------------------------------------------------------------------------------------------------------------------
void drawTargets()
{
  if (t1.isEnabled())
    t1.drawTarget();
  if (t2.isEnabled())
    t2.drawTarget();
  if (t3.isEnabled())
    t3.drawTarget();
}

//---------------------------------------------------------------------------------------------------------------------------------------------------
void showNoOfBullets()
{
  char bulletsStr[1];
  itoa(noOfBullets, bulletsStr, 10); 
  SSD1306.ssd1306_setpos(0, 0);
  SSD1306.ssd1306_string_font6x8(bulletsStr);
  SSD1306.ssd1306_string_font6x8("x Bullets");
}

//---------------------------------------------------------------------------------------------------------------------------------------------------
void checkButtons()
{
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
    bullet.fire((player.playerX0 + 3), (player.playerX1 - 3));   // fire a bullet from the current player position
    noOfBullets--;                                               // deduct 1 from the number of bullets remaining                
  }
}

//---------------------------------------------------------------------------------------------------------------------------------------------------
void updateTargets()
{
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

//---------------------------------------------------------------------------------------------------------------------------------------------------
bool levelIsComplete()
{
  if(t1.isEnabled() && t1.isActive())
    return false; 
  else if(t2.isEnabled() && t2.isActive())
    return false; 
  else if(t3.isEnabled() && t3.isActive())
    return false;
  else
    return true;   
}

//---------------------------------------------------------------------------------------------------------------------------------------------------
bool outOfBullets()
{
  if ((noOfBullets == 0) && (!(bullet.fired)))  // if there are no bullets still on the screen and there are no bullets, they are out of bullets
    return true;
  else
    return false;  
}
