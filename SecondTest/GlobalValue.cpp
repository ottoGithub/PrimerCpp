#include "StdAfx.h"
#include "GlobalValue.h"


//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

int gGameStateID = eGameState_LoadScene;
