#ifndef _SCENE_MANAGER_H_
#define _SCENE_MANAGER_H_
#include "Singleton.h"
#include "CommonDef.h"

class Actor;
class SceneManager : public Singleton<SceneManager>
{
public:
	SceneManager();
	~SceneManager();
	void Tick(int nFrameTime);

	void LoadScene(int SceneID);
	void EnterScene(Actor* pActor);
	void RenderScene();
private:
	int m_nCurrentSceneID;
	Vector2D m_DefaultBornPoint;
	SDL_Rect m_rectClips;
};

#endif