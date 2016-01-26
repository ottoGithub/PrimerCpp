#include "StdAfx.h"
#include "SceneManager.h"
#include "Actor.h"

SceneManager::SceneManager() : m_DefaultBornPoint(0,0)
{
	m_nCurrentSceneID = 0;
}

SceneManager::~SceneManager()
{

}

void SceneManager::Tick(int nFrameTime)
{
	RenderScene();
}

void SceneManager::LoadScene(int SceneID)
{
	m_nCurrentSceneID = SceneID;
	m_rectClips.x = 32* 0;//32 * 11;
	m_rectClips.y = 0;
	m_rectClips.w = 32;
	m_rectClips.h = 32;
}

void SceneManager::RenderScene()
{
	//TODO:此处通过map数据读取
	for(int x = 0; x < LEVEL_WIDTH; x+=32)
		for(int y = 0; y < LEVEL_HEIGHT; y+=32)
		{
			gTileTexture.render( x, y, &m_rectClips );
		}
}

void SceneManager::EnterScene(Actor* pActor)
{
	if(!pActor)
	{
		return;
	}
	pActor->SetScene(m_nCurrentSceneID);
	pActor->SetDir(Vector2D(0,0));
	pActor->SetPos(m_DefaultBornPoint);
	pActor->SetSpeed(VOLECITY_RUN);
}