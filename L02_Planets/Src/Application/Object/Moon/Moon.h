#pragma once

class Moon :public KdGameObject
{
public:
	Moon();
	~Moon()override;

public:
	void Init()override;
	void Update()override;
	void DrawLit()override;

private:
	std::shared_ptr<KdModelData>m_Moon;
	Math::Matrix m_worldMat, m_rotMat, m_transMat;

	Math::Vector3 m_Pos;

};