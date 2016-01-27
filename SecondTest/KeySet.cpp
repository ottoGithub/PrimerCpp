#include "StdAfx.h"
#include "KeySet.h"

KeyDirArray::KeyDirArray()
{
	nKeyDirCurIndex = -1;
	memset(ArrayCode,-1,sizeof(int) * DIRECTION_VALUE);
}

void KeyDirArray::Push(KeyDirValue eKeyCode)
{
	//for(int i=0;i<DIRECTION_VALUE;i++)
	//{
	//	if(ArrayCode[i] == eKeyCode)
	//	{

	//	}
	//}
	//ArrayCode[++nKeyDirCurIndex] = eKeyCode;
}

void KeyDirArray::Pull(KeyDirValue eKeyCode)
{

}

Vector2D KeyDirArray::GetCurKeyDirection()
{
	return Vector2D(0,0);
}

KeySet::KeySet()
{
}

Vector2D KeySet::OnDirectionKeyEvent(KeyDirValue eKeyCode, int nActionMode)
{
	if(nActionMode == eKey_Press)
	{
		m_KeyArray.Push(eKeyCode);
		//if(nKeyDirCurIndex > 0 && nKeyDirCurIndex < 4)
		//{
		//	KeyDirArray[nKeyDirCurIndex] = nKeyCode;
		//	nKeyDirCurIndex++;
		//}
	}
	if(nActionMode == eKey_Up)
	{
		m_KeyArray.Pull(eKeyCode);
	}
	return m_KeyArray.GetCurKeyDirection();
}