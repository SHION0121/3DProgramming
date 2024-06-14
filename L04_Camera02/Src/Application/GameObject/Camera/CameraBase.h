#pragma once

class CameraBase :public KdGameObject
{
public:
	CameraBase() {}
	~CameraBase() {}

	void Init()override;
	void Update()override;
	void PreDraw()override;

	//カメラのターゲットとしたいオブジェクト情報の設定
	void SetTarget(std::shared_ptr<KdGameObject>target) { m_wpTarget = target; }

protected:
	void 	UpdateRotateByMouse();

	std::shared_ptr<KdCamera>m_spCamera = nullptr;
	std::weak_ptr<KdGameObject>m_wpTarget;

	Math::Matrix m_mLocalPos;
	Math::Matrix m_mRotation;

	POINT m_FixMousePos;

	//カメラ回転用角度
	Math::Vector3 m_DegAng;
};