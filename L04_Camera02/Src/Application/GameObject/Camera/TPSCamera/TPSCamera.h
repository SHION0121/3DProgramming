#pragma once
#include"../CameraBase.h"

class TPSCamera :public CameraBase
{
public:
	TPSCamera() {}
	~TPSCamera() {}

	void Init()override;
	void Update()override;
};
