
#ifndef _SCREENS_H_
#define _SCREENS_H_

#include <Arduino.h>

void levelScreen(uint8_t levelNo, uint8_t noOfBullets);
void levelCompleteScreen(int score);
void newHighScoreScreen(int highScore);
void gameOverScreen(int score, int highScore);
void gameCompleteScreen(int score, int highScore);
void printScore(int score);
void printHighScore(int highScore);

#endif // _SCREENS_H_
