﻿#include "pch.h"
#include "Monster.h"

#include "Player.h"
#include "GameManager.h"


Monster::Monster(int x, int y) : Object(x, y)
, m_Data{
		{ '1', '1', '1', '1', '1' },
		{ '1', 'M', 'M', 'M', '1' },
		{ '1', 'M', ' ', 'M', '1' },
		{ '1', 'M', 'M', 'M', '1' },
		{ '1', '1', '1', '1', '1' }
}
{
	m_pNowAni = &m_Data;
}

Monster::~Monster()
{
}

eObjectType Monster::GetObjectType() const
{
	return eObjectType::Monster;
}

bool Monster::Interaction(Player* a_refHero)
{
	if( IsCross(a_refHero) == true )  // 플레이어의 죽음 플래그 On
	{
		GameMng()->Die(this);  // 몬스터에게 피격됐을시에 적절한 처리
						// 일단 지금은 Die 함수호출
	}
	return false;
}