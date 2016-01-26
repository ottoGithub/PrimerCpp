#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "Singleton.h"
#include "Vector2D.h"

class Camera : public Singleton<Camera>
{
public:
	Camera();
	~Camera();

	void SetLinkEntity(int nID);
	void SetCameraPos(Vector2D& vPos) { m_vCamPos = vPos; }
	const Vector2D& GetCameraPos() { return m_vCamPos; }

protected:
	void Init();

protected:
	int m_nLinkID;
	Vector2D m_vCamPos;
	const int CameraViewWidth;
	const int CameraViewHeight;
};

#endif