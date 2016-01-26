#include "StdAfx.h"
#include "Camera.h"
#include "ActorManager.h"

Camera::Camera():m_vCamPos(0,0),CameraViewHeight(SCREEN_HEIGHT),CameraViewWidth(SCREEN_WIDTH)
{
	m_nLinkID = 0;
}

Camera::~Camera()
{

}

void Camera::SetLinkEntity(int nID)
{
	 m_nLinkID = nID;
	 Init();
}

void Camera::Init()
{
	Actor* pActor = ActorManager::Instance().GetActorByGuid(m_nLinkID);
	if(!pActor)
	{
		return;
	}
	//TODO:������ĵ���������ĵ���ôȷ����Ҫ��������
	m_vCamPos = pActor->GetPos();
}