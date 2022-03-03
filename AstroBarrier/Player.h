
#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <Arduino.h>

class Player{
public:
  uint8_t playerX0;
  uint8_t playerX1;

  Player();

  void drawPlayer();
  
  void drawBlank();

  void moveLeft();

  void moveRight();
};


#endif // _PLAYER_H_
