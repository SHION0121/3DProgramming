#include "Moon.h"

Moon::Moon()
{
}

Moon::~Moon()
{
}

void Moon::Init()
{
	m_Moon = std::make_shared<KdModelData>();
	m_Moon->Load("Asset/Data/LessonData/Planets/moon.gltf");
}

void Moon::Update()
{
}

void Moon::DrawLit()
{
	static float deg = 0;
	deg -= 1;
	if (deg < -360) { deg += 360; }
	m_rotMat = Math::Matrix::CreateRotationY(DirectX::XMConvertToRadians(deg));

	static float a, b, c = 7, degB = 360;
	degB -= 1.0f;
	a = cos(degB * 3.14 / 180) * c;
	b = sin(degB * 3.14 / 180) * c;

	m_Pos.x = 0 + a;
	m_Pos.z = 0 + b;

	m_transMat = Math::Matrix::CreateTranslation(m_Pos.x, 0, m_Pos.z);

	m_worldMat = m_rotMat * m_transMat;

	KdShaderManager::Instance().m_StandardShader.DrawModel(*m_Moon, m_worldMat);
}
