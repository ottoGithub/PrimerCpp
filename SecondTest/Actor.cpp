#include "StdAfx.h"
#include "Actor.h"

Actor::Actor() : m_vPos(0,0),m_vDir(0,0)
{
	m_nVelocity = 0;
	m_nGuid = 0;
	m_nSceneID = 0;
}

Actor::~Actor()
{

}

void Actor::Tick(int nFrameTime)
{
	float fFrameTime = nFrameTime / 1000.0f;
	m_vPos += m_nVelocity * fFrameTime * m_vDir;
	
	RenderActor();
}

void Actor::RenderActor()
{
	static int nFrameCount = 0;
	nFrameCount %= WALKING_ANIMATION_FRAMES * ANIM_PLAY_FRAME_COUNT;
	static int nDirAnimIndex = e_Down_Anim;
	if(m_vDir.IsEqual(Vector2D(0, -1),MIN_FLOAT))
	{
		nDirAnimIndex = e_Up_Anim;
	}
	else if(m_vDir.IsEqual(Vector2D(0, 1),MIN_FLOAT))
	{
		nDirAnimIndex = e_Down_Anim;
	}
	else if (m_vDir.IsEqual(Vector2D(-1, 0),MIN_FLOAT))
	{
		nDirAnimIndex = e_Left_Anim;
	}
	else if (m_vDir.IsEqual(Vector2D(1, 0),MIN_FLOAT))
	{
		nDirAnimIndex = e_Right_Anim;
	}
	else
	{
		nFrameCount = 0;
	}

	gCharacterTexture.render(int(m_vPos.x), int(m_vPos.y), &gRectCharterAnim[nDirAnimIndex][nFrameCount / ANIM_PLAY_FRAME_COUNT]);
	
	++nFrameCount;
}