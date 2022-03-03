
#include <avr/pgmspace.h>

#define noOfLevels 8

// Bullets | Target 1 (targetSize, targetSpeed, topLeftXCoord, topLeftYCoord) | Target 2 | Target 3

const uint8_t level [] [13] = {
{3,    32,3,0,1,    0,0,0,0,    0,0,0,0},        // Level 0
{3,    32,3,0,1,    0,0,0,0,    0,0,0,0},        // Level 1
{2,    32,5,0,1,    0,0,0,0,    0,0,0,0},        // Level 2
{2,    32,10,0,1,   0,0,0,0,    0,0,0,0},        // Level 3
{3,    16,3,0,1,    0,0,0,0,    0,0,0,0},        // Level 4
{4,    32,10,0,0,   16,5,0,4,   0,0,0,0},        // Level 5
{4,    16,5,0,0,    16,6,0,3,   0,0,0,0},        // Level 6
{4,    16,5,0,0,    16,10,0,3,  0,0,0,0},        // Level 7
{5,    16,5,0,0,    16,6,0,2,   16,4,0,4}        // Level 8
};
