
#ifndef _BULLET_H_
#define _BULLET_H_

#include <Arduino.h>

class Bullet{
public:
  uint8_t x0;
  uint8_t y0;
  uint8_t x1;
  uint8_t y1;

  bool fired;

  Bullet();
  
  void fire(uint8_t _x0, uint8_t _x1);

  void reload();

  void updateBullet();

  void drawBullet();
  
  void drawBlank();

  bool inRange(uint8_t _x0, uint8_t _y0, uint8_t _x1, uint8_t _y1);  
};


#endif // _BULLET_H_
