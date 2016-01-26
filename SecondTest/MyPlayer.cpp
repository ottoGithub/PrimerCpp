#include "StdAfx.h"
#include "MyPlayer.h"

MyPlayer::MyPlayer()
{
	ADD_TO_KEYEVENT_LISTENER(this);
}

MyPlayer::~MyPlayer()
{
	REMOVE_FROM_KEYEVENT_LISTENER(this);
}

void MyPlayer::Tick(int nFrameTime)
{
	//CalculateDirection();
	Actor::Tick(nFrameTime);
}

void MyPlayer::PostKeyEvent(SDL_Event& e)
{
	if(e.type == SDL_KEYDOWN)
	{
		switch(e.key.keysym.scancode)
		{
		case SDL_SCANCODE_W:
			{
				m_vDir = Vector2D(0,-1);
				return;
			}
		case SDL_SCANCODE_S:
			{
				m_vDir = Vector2D(0,1);
				return;
			}
		case SDL_SCANCODE_A:
			{
				m_vDir = Vector2D(-1,0);
				return;
			}
		case SDL_SCANCODE_D:
			{
				m_vDir = Vector2D(1,0);
				return;
			}
		default:
			return;
		}
	}
	if(e.type == SDL_KEYUP)
	{
		switch(e.key.keysym.scancode)
		{
		case SDL_SCANCODE_W:
			{
				if(m_vDir.y < 0)
				{
					m_vDir.y = 0;
				}
				return;
			}
		case SDL_SCANCODE_S:
			{
				if(m_vDir.y > 0)
				{
					m_vDir.y = 0;
				}
				return;
			}
		case SDL_SCANCODE_A:
			{
				if(m_vDir.x < 0)
				{
					m_vDir.x = 0;
				}
				return;
			}
		case SDL_SCANCODE_D:
			{
				if(m_vDir.x > 0)
				{
					m_vDir.x = 0;
				}
				return;
			}
		default:
			return;
		}
	}
}

//void MyPlayer::CalculateDirection()
//{
//	const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
//	if( currentKeyStates[ SDL_SCANCODE_W ] )
//	{
//		m_vDir = Vector2D(0,-1);
//	}
//	else if( currentKeyStates[ SDL_SCANCODE_S ] )
//	{
//		m_vDir = Vector2D(0,1);
//	}
//	else if( currentKeyStates[ SDL_SCANCODE_A ] )
//	{
//		m_vDir = Vector2D(-1,0);
//	}
//	else if( currentKeyStates[ SDL_SCANCODE_D ] )
//	{
//		m_vDir = Vector2D(1,0);
//	}
//	else
//	{
//		m_vDir = Vector2D(0,0);
//	}
//}