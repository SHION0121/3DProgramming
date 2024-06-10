#include "Character.h"
#include"../../main.h"

void Character::Init()
{
	if (!m_spPoly)
	{
		m_spPoly = std::make_shared<KdSquarePolygon>();
		m_spPoly->SetMaterial("Asset/Data/LessonData/Character/Hamu.png");
		m_spPoly->SetPivot(KdSquarePolygon::PivotType::Center_Bottom);
	}

}

void Character::Update()
{
	if (GetAsyncKeyState(VK_RBUTTON))
	{
		//①マウスの位置を取得
		POINT _mousePos;
		GetCursorPos(&_mousePos);
		ScreenToClient(Application::Instance().GetWindowHandle(), &_mousePos);

		std::shared_ptr<KdCamera>_cam = m_wpCam.lock();
		if (_cam)
		{
			Math::Vector3 _camPos = _cam->GetCameraMatrix().Translation();
			Math::Vector3 _rayDir = Math::Vector3::Zero;
			float _rayRange = 1000.0f;
			//②レイの発射方向を求める(_rayDir)
			_cam->GenerateRayInfoFromClientPos(_mousePos, _camPos, _rayDir, _rayRange);

			//③実際にレイを飛ばして衝突位置を求める
			const std::shared_ptr<KdGameObject>_terrain = m_wpTerrain.lock();
			if (_terrain)
			{
				Math::Vector3 _endRayPos = _camPos + (_rayDir * _rayRange);
				KdCollider::RayInfo _rayInfo(KdCollider::TypeGround, _camPos, _endRayPos);

				//実際の当たり判定の処理
				std::list<KdCollider::CollisionResult>_results;
				_terrain->Intersects(_rayInfo, &_results);

				//結果が一つでも帰って来ていたら
				if (_results.size())
				{
					for (KdCollider::CollisionResult result : _results)
					{
						m_TargetPos = result.m_hitPos;
					}
				}
			}

		}
	}

	// キャラクターの移動速度(真似しちゃダメですよ)
	float moveSpd = 0.05f;
	Math::Vector3 nowPos = GetPos();
	Math::Vector3 moveVec = m_TargetPos - nowPos;

	if (moveVec.Length() < moveSpd)moveSpd = moveVec.Length();
	moveVec.Normalize();
	moveVec *= moveSpd;
	nowPos += moveVec;


	// キャラクターのワールド行列を創る処理
	m_mWorld = Math::Matrix::CreateTranslation(nowPos);

}

void Character::DrawLit()
{
	if (!m_spPoly) return;

	KdShaderManager::Instance().m_StandardShader.DrawPolygon(*m_spPoly, m_mWorld);

}

void Character::DrawSprite()
{
	Math::Vector3 _result = Math::Vector3::Zero;
	std::shared_ptr<KdCamera>_cam = m_wpCam.lock();

	if (_cam)
	{
		_cam->ConvertWorldToScreenDetail(GetPos(), _result);
	}

	//↓この赤い点が常にハムスターの原点（足元）に追従するように！
	//①ハムスターの3D座標を2D座標へ変換する！
	KdShaderManager::Instance().m_spriteShader.DrawCircle(_result.x, _result.y, 10, &kRedColor);

}