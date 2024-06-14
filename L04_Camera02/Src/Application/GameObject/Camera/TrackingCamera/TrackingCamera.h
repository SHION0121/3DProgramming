#pragma once
#include"../CameraBase.h"

class TrackingCamera :public CameraBase
{
public:
	TrackingCamera() {}
	~TrackingCamera() {}

	void Init()override;
	void Update()override;
};
