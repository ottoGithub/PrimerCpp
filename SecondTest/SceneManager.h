#ifndef _SCENE_MANAGER_H_
#define _SCENE_MANAGER_H_
#include "Singleton.h"
#include "CommonDef.h"

class CActor;
class SceneManager : public Singleton<SceneManager>
{
public:
	SceneManager();
	~SceneManager();

	void LoadScene(int SceneID);
	void EnterScene(CActor* pActor);

private:
	int m_nCurrentSceneID;
	Point m_DefaultBornPoint;
};

#endif