
#include "Player.h"
#include "Sprites.h"

#include <ssd1306xled.h>
#include <font6x8.h>

#define playerSpeed 5
#define playerSize 8
#define playerY0 7
#define playerY1 8

//---------------------------------------------------------------------------------------------------------------------------------------------------
Player::Player()
{
  this->playerX0 = (screenWidth/2)-(playerSize/2);           // x coordinate of the top left corner
  this->playerX1 = playerX0 + playerSize;                    // x coordinate of the bottom right corner
}

//---------------------------------------------------------------------------------------------------------------------------------------------------
void Player::drawPlayer()
{
  SSD1306.ssd1306_draw_bmp(playerX0, playerY0, playerX1, playerY1, player);
}

//---------------------------------------------------------------------------------------------------------------------------------------------------
void Player::drawBlank()
{
  SSD1306.ssd1306_draw_bmp(playerX0, playerY0, playerX1, playerY1, smallBlank);
}

//---------------------------------------------------------------------------------------------------------------------------------------------------
void Player::moveLeft()
{
  if (playerX0 > (0 + playerSpeed))        // if within the bounds of the screen
  {
    playerX0 = playerX0 - playerSpeed;
    playerX1 = playerX0 + playerSize;   
  }                 
}

//---------------------------------------------------------------------------------------------------------------------------------------------------
void Player::moveRight()
{
  if (playerX1 < (screenWidth - playerSpeed))        // if within the bounds of the screen
  {
    playerX0 = playerX0 + playerSpeed;
    playerX1 = playerX0 + playerSize;   
  }                     
}

//---------------------------------------------------------------------------------------------------------------------------------------------------
void Player::shoot()
{
  
}
