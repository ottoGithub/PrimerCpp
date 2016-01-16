#ifndef _GLOBAL_VALUE_H_
#define _GLOBAL_VALUE_H_

#include "SDL.h"

extern SDL_Window* gWindow;
extern SDL_Renderer* gRenderer;

extern int gGameStateID;
enum eGameState
{
	eGameState_LoadScene,
};

#endif