#include "StdAfx.h"
#include "MyPlayer.h"


void MyPlayer::Tick(int nFrameTime)
{
	CalculateDirection();
	Actor::Tick(nFrameTime);
}

void MyPlayer::CalculateDirection()
{
	const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
	if( currentKeyStates[ SDL_SCANCODE_W ] )
	{
		m_vDir = Vector2D(0,-1);
	}
	else if( currentKeyStates[ SDL_SCANCODE_S ] )
	{
		m_vDir = Vector2D(0,1);
	}
	else if( currentKeyStates[ SDL_SCANCODE_A ] )
	{
		m_vDir = Vector2D(-1,0);
	}
	else if( currentKeyStates[ SDL_SCANCODE_D ] )
	{
		m_vDir = Vector2D(1,0);
	}
	else
	{
		m_vDir = Vector2D(0,0);
	}
}