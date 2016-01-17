#include "StdAfx.h"
#include "GameManager.h"
#include "SceneManager.h"
#include "ActorManager.h"

void GameManager::EnterGameState(int nStateID)
{
	gGameStateID = nStateID;
	if(gGameStateID == eGameState_LoadScene)
	{
		SceneManager::Instance().LoadScene(0);
		ActorManager::Instance().CreateActor(0, ObjType_MyPlayer);
		SceneManager::Instance().EnterScene((Actor*)ActorManager::Instance().GetMyPlayer());
		
		for(int x = 0, i = 0; x < gCharacterTexture.getWidth(); x += 32, ++i)
			for(int y = 0, j = 0; y < gCharacterTexture.getHeight(); y += 48, ++j)
			{
				gRectCharterAnim[j][i].x = x;
				gRectCharterAnim[j][i].y = y;
				gRectCharterAnim[j][i].w = 32;
				gRectCharterAnim[j][i].h = 48;
			}
	}
}

void GameManager::Tick(int nFrameTime)
{
	SceneManager::Instance().Tick(nFrameTime);
	ActorManager::Instance().Tick(nFrameTime);
}