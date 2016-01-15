#include "StdAfx.h"
#include "SceneManager.h"
#include "CActor.h"

SceneManager::SceneManager() : m_DefaultBornPoint(0,0)
{
	m_nCurrentSceneID = 0;
}

SceneManager::~SceneManager()
{

};

void SceneManager::LoadScene(int SceneID)
{
	m_nCurrentSceneID = SceneID;

}

void SceneManager::EnterScene(CActor* pActor)
{
	if(!pActor)
	{
		return;
	}
	pActor->SetScene(m_nCurrentSceneID);
	pActor->SetDir(eDwon);
	pActor->SetPos(m_DefaultBornPoint);
	pActor->SetSpeed(0);
}