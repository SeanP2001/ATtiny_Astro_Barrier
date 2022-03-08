
#ifndef _SCREENS_H_
#define _SCREENS_H_

#include <Arduino.h>

void levelScreen(uint8_t levelNo, uint8_t noOfBullets);
void levelCompleteScreen(int score);
void gameOverScreen(int score);
void gameCompleteScreen(int score);
void printScore(int score);

#endif // _SCREENS_H_
