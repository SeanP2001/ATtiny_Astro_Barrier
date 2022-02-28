
#ifndef _TARGET_H_
#define _TARGET_H_

#include <Arduino.h>

class Target{
public:
  uint8_t size;
  uint8_t speed;
  uint8_t x0;
  uint8_t x1;
  uint8_t y0;
  uint8_t y1;

  bool active;
  bool dir;


  Target(uint8_t _size, uint8_t _speed, uint8_t _x0, uint8_t _y0);

  bool isActive();

  void updateTarget();

  void drawTarget();
  
  void drawBlank();
};


#endif // _TARGET_H_
