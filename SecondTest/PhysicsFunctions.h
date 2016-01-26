#ifndef _PHYSICS_FUNCTIONS_H_
#define _PHYSICS_FUNCTIONS_H_
#include "Vector2D.h"

void ConvertToWorldPos(int x, int y, SDL_Rect* pRect, Vector2D& vRealWorldPos);


bool CheckCollision_Rect2Rect( SDL_Rect r1, SDL_Rect r2 );

#endif