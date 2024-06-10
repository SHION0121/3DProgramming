#pragma once

class Character : public KdGameObject
{
public:
	Character() {}
	virtual ~Character()	override {}

	void Init()				override;
	void Update()			override;
	void DrawLit()			override;
	void DrawSprite()		override;

	void SetCamera(std::shared_ptr<KdCamera>camera) { m_wpCam = camera; }
	void SetTerrain(std::shared_ptr<KdGameObject>terrain) { m_wpTerrain = terrain; }
private:
	std::shared_ptr<KdSquarePolygon>	m_spPoly	= nullptr;
	std::weak_ptr<KdCamera>				m_wpCam;
	std::weak_ptr<KdGameObject>			m_wpTerrain;

	Math::Vector3						m_TargetPos	= Math::Vector3::Zero;
};