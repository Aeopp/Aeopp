#include "pch.h"
#include "GameManager.h"

#include "MapData.h"
#include "Object.h"
#include "Player.h"
#include "ObjectFactory.h"

CharacterData::CharacterData()
{
	fMoveSeepd = GameManager::MoveSpeed;
	fBombTime = GameManager::BombTime;
	nBombPower = GameManager::BombBasePower;
	nBombCount = GameManager::BombBaseCount;
}

GameManager::GameManager() {}
GameManager::~GameManager()
{
	ClearObject();

	// 범위기반 for문에서 ClearObject();
	// 함수호출로 변경 되었고 하는일은 동일


	SAFE_DELETE(m_pPlayer);
}

void GameManager::Init()
{
	MapData::Init();
}

void GameManager::Release()
{
	MapData::Release();
}

void GameManager::GameInit()
{
	m_nNowLife = 3;
	m_nScore = 0;
	m_nNowStage = 0;
}

void GameManager::StageStart()
{
	++m_nNowStage;
	m_fGameTime = RoundTime;

	ClearObject();

	m_refMap = MapData::Get(m_nNowStage);
	assert(m_refMap != nullptr && m_refMap->pMap != nullptr);

	int nWidth = m_refMap->x;
	int nHeight = m_refMap->y;
	const std::string& sRef = m_refMap->mapOriginData;
	m_pMap = m_refMap->pMap;

	// 맵 제작
	for(int y = 0; y<nHeight; ++y )
	{
		for (int x = 0; x < nWidth; ++x)
		{
			int nIndex = y * nWidth + x;
			eObjectType eType = MapData::DataToObjectType(sRef[nIndex]);

			if (eType == eObjectType::None) { continue; }

			if (eType == eObjectType::Player && m_pPlayer != nullptr)
			{
				m_pPlayer->SetPos(x, y);
				m_pPlayer->SetMap(m_pMap);
				continue;
			}

			auto* pObj = ObjectFactory::Make(eType, x, y);
			if(eType == eObjectType::Player)
			{
				m_pPlayer = static_cast<Player*>(pObj);
			}
			else
			{
				int nLevel = (int)eType / (int)eObjectType::LevelGap;
				// 오브젝트 벡터에 인덱스 참조를 위해 레벨값을 
				// 구해놓는다
				m_vcObj[nLevel - 1].push_back(pObj);
			}

			pObj->SetMap(m_pMap);
		}
	}
}

void GameManager::ClearObject()
{
	
	for (auto& vc : m_vcObj) // 여기서는 인덱스를 순회
	{
		for (auto* pObj : vc) // 해당 인덱스의 포인터 참조
		{
			SAFE_DELETE(pObj);
		}

		vc.clear();
	}
}

void GameManager::Update(float a_fDeltaTime)
{
	// 첫번째 ranged-for 인덱스 순회
	// 두번째 ranged-for 오브젝트 포인터 참조
	// 하며 모든 오브젝트의 업데이트 함수를 호출
	for (auto& vc : m_vcObj)
	{
		for (auto* pObj : vc)
		{
			pObj->Update(a_fDeltaTime);
		}
	}
		
	m_pPlayer->Update(a_fDeltaTime);
}

void GameManager::Render()
{
	for (auto& vc : m_vcObj)
	{
		for (auto* pObj : vc)
		{
			pObj->Render();
		}
	}

	m_pPlayer->Render();
	m_refMap->Render();
}

void GameManager::RemoveObject(class Object* a_pObj)
{
	eObjectType eType = a_pObj->GetObjectType();
	// 아규먼트에 따른 eType 로 초기화해주는 모습

	// 떄문에 Object를 상속받는 객체들은 자신의 eType 에 맞는
	// 값들로 함수를 정의해야함

	//레벨값에 맞는 인덱스 참조를 하기위함

	int nLevelIndex = (int)eType / (int)eObjectType::LevelGap;
	nLevelIndex -= 1;  

	auto& vc = m_vcObj[nLevelIndex];

	auto itor = std::find_if(std::begin(vc), std::end(vc), [a_pObj](Object*p) {return p == a_pObj;});
	assert(itor != vc.end());
	vc.erase(itor);
}

void GameManager::DropItem(Object* a_pObj)
{

}

void GameManager::ObtainItem(eItem a_eItem)
{
	switch (a_eItem)
	{
	case eItem::PowerUp:
		m_stPlayerData.nBombPower += 1;
		break;
	case eItem::BombCount:
		m_stPlayerData.nBombCount += 1;
		break;
	case eItem::SpeedUp:
		m_stPlayerData.fMoveSeepd += 1;
		break;
	default:
		assert(false && "arg error");
		break;
	}

}

#include "Bomb.h"
void GameManager::GetBombData(Bomb* a_refBomb) const
{
	a_refBomb->m_fLifeTime = m_stPlayerData.fBombTime;
	a_refBomb->m_nExplosiveRange = m_stPlayerData.nBombPower;
}