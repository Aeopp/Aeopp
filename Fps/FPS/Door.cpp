﻿#include "pch.h"
#include "Door.h"

#include "GameManager.h"
#include "Player.h"
// 플레이어 참조가능

Door::Door(int x, int y) : Object(x, y)
, m_Close{
			{ 'X', '-', '-', '-', 'X' },
			{ '|', 'X', ' ', 'X', '|' },
			{ '|', ' ', 'X', ' ', '|' },
			{ '|', 'X', ' ', 'X', '|' },
			{ 'X', '-', '-', '-', 'X' },
}
, m_Open{
			{ ' ', 'D', 'D', 'D', ' ' },
			{ 'D', ' ', ' ', ' ', 'D' },
			{ 'D', ' ', ' ', ' ', 'D' },
			{ 'D', ' ', ' ', ' ', 'D' },
			{ ' ', 'D', 'D', 'D', ' ' },
} {
	m_pNowAni = &m_Close;
}

Door::~Door()
{
}

eObjectType Door::GetObjectType() const
{
	return eObjectType::Door;
}

void Door::Init()
{
	m_eState = eDoorState::Close;
}

bool Door::Interaction(class Player* a_refHero)
{
	if (m_eState == eDoorState::Close) { return false; }

	if( IsCross(a_refHero) == true )
	{    // 플레이어와 부딪혔는지 검사
	 		// 부딪혔다면 스테이지 종료
	 		// 불리언 반환하기때문에
	 		// 호출 측에서도 반환값으로 스테이지 종료할지 루프 진행할지
	 		// 검사하기 편해보임
		GameMng()->StageEnd();
	}

	return false;
}