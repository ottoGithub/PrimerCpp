#ifndef _C_ACTOR_H_
#define _C_ACTOR_H_
#include "CommonDef.h"

class CActor
{
public:
	CActor();
	virtual ~CActor();

public:
	void SetDir(int nDir) { m_nDir = nDir; }
	void SetPos(int x, int y) { m_Pos.x = x ; m_Pos.y = y; }
	void SetPos(Point& point) { m_Pos.x = point.x; m_Pos.y = point.y; }
	void SetSpeed(float v) { m_fSpeed = v;}

	void SetScene(int nSceneID) { m_nSceneID = nSceneID; }
private:
	int m_nDir;
	Point m_Pos;
	float m_fSpeed;

	int m_nSceneID;
};

#endif