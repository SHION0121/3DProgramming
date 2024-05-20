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

}

void Sun::Update()
{
}

void Sun::DrawLit()
{
	m_transMat = Math::Matrix::CreateTranslation(0, 0, 0);
	KdShaderManager::Instance().m_StandardShader.DrawModel(*m_Sun, m_transMat);
}
