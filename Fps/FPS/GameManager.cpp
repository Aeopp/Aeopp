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
	m_eState = eGameState::Run;
	// 이 상태값으로 게임루프를 통제할수 있다
	// 현재는 시작한 상태이므로 Run 

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

			CreateObject(eType, x, y);
			// 오브젝트들 생성하고 플레이어,맵 셋업하던
			// 부분을 따로 함수로 분리
		}
	}
}

void GameManager::StageEnd()
{
	m_eState = eGameState::End;
}

void GameManager::ClearObject()
{
	for (auto& vc : m_arrObj)
	{
		for (auto* pObj : vc)
		{
			SAFE_DELETE(pObj);
		}

		vc.clear();
	}
}

void GameManager::CreateObject(eObjectType a_eObjType, int x, int y)
{
	auto* pObj = ObjectFactory::Make(a_eObjType, x, y);
	// 팩토리에 타입과 좌표만 주면 타입과 좌표 세팅해서
	// 객체를 넘겨준다
	if (a_eObjType == eObjectType::Player)
	{   // 플레이어 타입이 아규먼트라면
		// 포인터에 물려주고
		// 스텟 세팅하기
		m_pPlayer = static_cast<Player*>(pObj);
		m_pPlayer->SetStat(&m_stPlayerData);
	}
	else
	{
		int nDepthIndex = (int)a_eObjType / (int)eObjectType::RenderDepthGap;
		nDepthIndex -= 1;
		
		m_arrObj[nDepthIndex].push_back(pObj);
	}
	
	pObj->SetMap(m_pMap);
	// 맵 셋팅
}

void GameManager::Update(float a_fDeltaTime)
{
	int nSize = m_arrObj.size();

	static std::vector<class Object*> vcDelete;
	vcDelete.clear();

	// 0뎁스의 오브젝트는 업데이트 할 내용이 없음
	
	for( int i=1; i<nSize; ++i )
	{
		auto& arrObj = m_arrObj[i];
		
		for (auto* pObj : arrObj)
		{
			Object* p = nullptr;

			if( pObj->Update(a_fDeltaTime) == true )
			{
				p = pObj;
			}

			if( pObj->Interaction(m_pPlayer) == true )
			{
				p = pObj;
			}

			if( p != nullptr )
			{
				vcDelete.push_back(p);
			}
			// 오브젝트들 순회하며 업데이트와 인터렉션 호출
			// 그 이후 삭제하기 위해 vcDelete.push_back(p)
		}
	}

	// 인터렉션 이후 삭제해야할 오브젝트 삭제
	for( auto* pDeleteObj : vcDelete )
	{
		pDeleteObj->RenderClear();
		// 자신의 이미지 삭제해줌
		RemoveObject(pDeleteObj);
		// 오브젝트 삭제하는 처리
	}
	vcDelete.clear();
	// 삭제될 오브젝트 벡터 정리
	m_pPlayer->Update(a_fDeltaTime);
}

void GameManager::Render()
{
	for (auto& vc : m_arrObj)
	{
		for (auto* pObj : vc)
		{
			pObj->Render();
		}
	}

	m_pPlayer->Render();
	m_refMap->Render();

	if(m_eState == eGameState::End )
	{
		StageStart();
	}
	
	cout << "pos : " << m_pPlayer->rt.x << " /// " << m_pPlayer->rt.y << endl;
	COORD center = m_pPlayer->rt.Center();

	cout << "center : " << center.X << " /// " << center.Y << endl;

	if(m_sLog.size() > 0 )
	{
		cout << m_sLog.c_str() << endl;
		m_sLog.clear();
	}
}

void GameManager::RemoveObject(class Object* a_pObj)
{
	eObjectType eType = a_pObj->GetObjectType();

	int nLevelIndex = (int)eType / (int)eObjectType::RenderDepthGap;
	nLevelIndex -= 1; // 인덱스

	auto& vc = m_arrObj[nLevelIndex];

	auto itor = std::find_if(std::begin(vc), std::end(vc), [a_pObj](Object*p) {return p == a_pObj;});
	assert(itor != vc.end());
	vc.erase(itor);

	SAFE_DELETE(a_pObj);
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
		m_stPlayerData.fMoveSeepd += 30;
		// 인자로 들어온 아이템 값을 바탕으로
		// 플레이어 스텟 증감 작업
		break;
	default:
		assert(false && "arg error");
		break;
	}
}

void GameManager::Die(class Object* a_refObj)
{
	cout << "Player Die" << endl;

}

bool GameManager::AddBomb(int a_nPlayerX, int a_nPlayerY)
{
	int nX = a_nPlayerX / TileSize;
	int nY = a_nPlayerY / TileSize;
	
	constexpr static int nIndex = ((int)eObjectType::Bomb / (int)eObjectType::RenderDepthGap) - 1;

	bool bExsistBomb = false;
    // 폭탄 미설치 상태
	for( auto* pObj : m_arrObj[nIndex] )
	{
		if( pObj->GetObjectType() == eObjectType::Bomb )
		{
			bExsistBomb = pObj->rt.IsIn(a_nPlayerX, a_nPlayerY);
			// 폭탄 상태값 true 로 바꿔주고 좌표 세팅
			if( bExsistBomb == true )
			{
				break;
			}
		}
	}

	if( bExsistBomb == true ) // 이미 설치된 폭탄
	{
		return false;
	}
	
	CreateObject(eObjectType::Bomb , nX, nY); // 폭탄 생성
	return true; // 여기서 T 반환으로 플레이어의 Update 처리에서 폭탄이 설치됨
}

void GameManager::ResistExplosion(int a_nBombX, int a_nBombY, int a_nPower)
{
	m_pPlayer->m_nPutBombCount -= 1;



}

#include "Bomb.h"
void GameManager::GetBombData(Bomb* a_refBomb) const
{
	a_refBomb->m_fLifeTime = m_stPlayerData.fBombTime;
	a_refBomb->m_nExplosiveRange = m_stPlayerData.nBombPower;
}