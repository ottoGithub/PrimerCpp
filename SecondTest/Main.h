#ifndef _GAME_MAIN_H_
#define _GAME_MAIN_H_

#include <stdio.h>
#include "LTexture.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

bool InitializeEngine();
void ShutdownEngine();

// Main game functions.
bool GameInitialize();
void GameLoop();
void GameShutdown();


#endif