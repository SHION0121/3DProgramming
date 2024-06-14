#pragma once
#include"../CameraBase.h"

class FPSCamera :public CameraBase
{
public:
	FPSCamera() {}
	~FPSCamera() {}

	void Init()override;
	void Update()override;
};
