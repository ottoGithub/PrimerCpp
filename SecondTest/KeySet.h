#ifndef _KEY_SET_H_
#define _KEY_SET_H_

#include "KeyDef.h"
#include "Singleton.h"

class KeyDirArray
{
#define DIRECTION_VALUE 4
public:
	KeyDirArray();

	void Push(KeyDirValue eKeyCode);
	void Pull(KeyDirValue eKeyCode);

	Vector2D GetCurKeyDirection();
private:
	int ArrayCode[DIRECTION_VALUE];
	int nKeyDirCurIndex;
};

class KeySet : public Singleton<KeySet>
{
public:
	KeySet();
	Vector2D OnDirectionKeyEvent(KeyDirValue eKeyCode, int nActionMode);

private:
	KeyDirArray m_KeyArray;
};




#endif