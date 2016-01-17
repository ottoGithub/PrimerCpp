#ifndef _ACTOR_MANAGER_H_
#define _ACTOR_MANAGER_H_

#include "Singleton.h"
#include <map>

class Actor;
class MyPlayer;

enum eObjType
{
	ObjType_NPC,
	ObjType_MyPlayer,
	ObjType_OtherPlayer,
};

typedef std::map<int,Actor*> ActorMap;
class ActorManager : public Singleton<ActorManager>
{
public:
	ActorManager();

	void CreateActor(int guid, int nActorType);
	MyPlayer* GetMyPlayer() { return m_pMyPlayer; }

	void Tick(int nFrameTime);
private:
	ActorMap m_ActorMap;
	MyPlayer* m_pMyPlayer;
};

#endif