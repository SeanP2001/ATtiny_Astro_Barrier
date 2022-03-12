# ATtiny Astro Barrier

<p align="center">
 <img src="./Images/Title_Screen_Colour_Scaled.jpg" width="100%" />
</p>

## Table of Contents

- [Introduction](#introduction)
- [Controls](#controls)
- [Game Objective](#game-objective)
- [Demonstration](#demonstration)
- [Credits](#credits)
- [Further Work](#further-work)

## Introduction

I created this game to run on my [ATtiny handheld games console]([GitHub - SeanP2001/ATtiny_Handheld_Games_Console: A handheld games console, based on the ATtiny85 AVR microcontroller.](https://github.com/SeanP2001/ATtiny_Handheld_Games_Console)). The game is loosely based on the Club Penguin minigame also called "Astro Barrier".

## Controls

| Button | Action                |
|:------:| --------------------- |
| Left   | Move the player left  |
| Right  | Move the player right |
| A      | Fire a bullet         |

## Game Objective

The objective of the game is to shoot all of the moving targets without running out of bullets. 

When you shoot a target it will stop moving and become inactive. To advance to the next level, all targets in the level must be inactive. If you run out of bullets, it's game over! 

Once you have managed to complete all 17 levels you can work to achieve a perfect score of 254. Your score is based on how many bullets you have remaining when you complete the level.

## Demonstration

Coming soon...

## Credits

To create the game sounds I used the excellent code found [here](http://www.technoblogy.com/show?20MO) written by David Johnson-Davies. I highly recommend checking out David's website, especially for anything relating to the ATtiny microcontroller series.

## Further Work

In future I would like to:

- Change the scoring system to still award points for completing a level with no remaining bullets.

- Re-assess the difficulty of each level.

- Optimise the code to reduce program storage and dynamic memory usage.

- Add a "Freeplay Mode" where players try to achieve a high score, shooting randomly generated targets.

- Add walls which block the player from shooting targets.
