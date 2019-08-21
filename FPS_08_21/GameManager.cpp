#include "pch.h"
#include "GameManager.h"

#include "MapData.h"
#include "Object.h"
#include "Player.h"
#include "ObjectFactory.h"

GameManager::GameManager() {}
GameManager::~GameManager()
{
	for( auto* pObj : m_vcObj)
	{
		SAFE_DELETE(pObj);
	}
	
	SAFE_DELETE(m_pPlayer);
}

void GameManager::Init()
{
	MapData::Init();
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

	MapData::Get(m_nNowStage);
	assert(m_refMap != nullptr);

	// 이 함수의 내부구현이 조금 추가됨

	// 1. ClearObject()
	// 단순히 동적 인스턴싱된 오브젝트 포인터를 담고있는
	// 벡터를 청소해주는 역할

	// 반복문을 돌면서 Player의 좌표를 찾는다면
	// 좌표 세팅하고  SetMap 함수를 호출

	// 오브젝트팩토리의 Make함수를 호출해서
	// 맵 데이터 값을 받고 세팅하며
	// 맵 객체는 미리 만들어놓은 벡터에 저장함.


}

void GameManager::Update(float a_fDeltaTime)
{
	for (auto obj : m_vcObj)
	{
		obj->Update(a_fDeltaTime);
	}
		
	m_pPlayer->Update(a_fDeltaTime);
}

void GameManager::Render()
{
	for (auto obj : m_vcObj)
	{
		obj->Render();
	}

	m_pPlayer->Render();
}

//void GameManager::RemoveObject(class Object* a_pObj)
// 자료형 추론 타입의 이터레이터는 std::find_if를 활용하여
// 아규먼트로 받은 오브젝트 객체와 
// 벡터  원소가 동일하다면 해당 원소를 삭제시킨....다고 분석..?
// assert(itor != m_vcObj.end()); <- 구문으로 예외상황
// 방어에도 힘썼음
// 람다를 활용해서 정말 편해보이고 삭제시킬때마다 이터레이터를
// 새로 써야 한다는건 조금 불편해보임

//void GameManager::ObtainItem(eItem a_eItem)
// 아규먼트 값을 바탕으로 switch 문을 활용하여서
// 플레이어의 스텟을 증가시키는 단순한 함수의 추가

//void GameManager::GetBombData(Bomb* a_refBomb) const
// 단순히 폭탄의 지속시간과 폭발 범위 값을
// 플레이어가 가지고있는 변수값으로 대입시키는 데이타
// 폭탄의 폭발범위값을 플레이어가 가지고 (아이템으로 증가시키든)
// (떨구든 해야하니) 폭발 지속시간도 플레이어의 데이터로
// 매번 초기화 시켜주는걸 보면 아이템중에 지속시간을 짧게해주거나
// 늘려주는 아이템의 구현을 생각중인가 싶음
