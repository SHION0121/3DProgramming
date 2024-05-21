#pragma once

class Earth :public KdGameObject
{
public:
	Earth();
	~Earth()override;

public:
	void Init()override;
	void Update()override;
	void DrawLit()override;

private:
	std::shared_ptr<KdModelData>m_Earth;
	Math::Matrix m_worldMat,m_rotMat,m_transMat;

	Math::Vector3 m_Pos;

};