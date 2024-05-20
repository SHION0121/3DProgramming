#pragma once

class Sun :public KdGameObject
{
public:
	Sun();
	~Sun()override;

public:
	void Init()override;
	void Update()override;
	void DrawLit()override;

private:
	std::shared_ptr<KdModelData> m_Sun;
	Math::Matrix m_transMat;
};