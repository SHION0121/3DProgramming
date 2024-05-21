#include "Sun.h"

Sun::Sun()
{

}

Sun::~Sun()
{

}

void Sun::Init()
{
	m_Sun = std::make_shared<KdModelData>();
	m_Sun->Load("Asset/Data/LessonData/Planets/sun.gltf");

	m_Pos = { 0,0,0 };

}

void Sun::Update()
{
}

void Sun::DrawLit()
{
	m_transMat = Math::Matrix::CreateTranslation(m_Pos.x, m_Pos.y, m_Pos.y);
	KdShaderManager::Instance().m_StandardShader.DrawModel(*m_Sun, m_transMat);
}
