#ifndef _MYPLAYER_H_
#define _MYPLAYER_H_

#include "Actor.h"

class MyPlayer : public Actor
{
public:
	void Tick(int nFrameTime);

public:
	void CalculateDirection();
};
#endif