#include "pch.h"
#include "Bomb.h"

#include "GameManager.h"
#include "Ani.h"

Bomb::Bomb(int x, int y) : Object(x, y), m_pAni(new Ani())
{
	m_pAni->Resize(1);
	m_pAni->Add(0,
		{
		   {{"XXXXX"},
			{"XXXXX"},
			{"|   |"},
			{"| B |"},
			{"#####"}},

		   {{"xxxxx"},
			{"xxxxx"},
			{"|   |"},
			{"| B |"},
			{"#####"}},

		   {{"XXXXX"},
			{"XXXXX"},
			{"|   |"},
			{"| B |"},
			{"#####"}},

		   {{"xxxxx"},
			{"xxxxx"},
			{"|   |"},
			{"| B |"},
			{"#####"}},

		   {{" XXX "},
			{" XXX "},
			{"|   |"},
			{"| B |"},
			{"#####"}},

		   {{" xxx "},
			{" xxx "},
			{"|   |"},
			{"| B |"},
			{"#####"}},

		   {{"  X  "},
			{"  X  "},
			{"|   |"},
			{"| B |"},
			{"#####"}},

		   {{"  x  "},
			{"  x  "},
			{"|   |"},
			{"| B |"},
			{"#####"}},

		   {{"     "},
			{"  x  "},
			{"|   |"},
			{"| B |"},
			{"#####"}},

		   {{"     "},
			{"     "},
			{"|   |"},
			{"| B |"},
			{"#####"}},
		}
	);
	// 폭탄 애니메이션의 추가
	// 애니메이션 사이즈와 폭탄 애니메이션 추가이후
	
	m_pAni->SetState(0);
	m_pNowAni = m_pAni->Get();
	// 상태갑 세팅하고 바로 애니메이션 그릴준비
}

Bomb::~Bomb() { }

eObjectType Bomb::GetObjectType() const
{
	return eObjectType::Bomb;
}

void Bomb::Init()
{
	GameMng()->GetBombData(this);
}

bool Bomb::_Update(float a_fDelta)
{
	// 애니
	m_pAni->Update(a_fDelta);
	m_pNowAni = m_pAni->Get();
   
	// 수명
	m_fLifeTime -= a_fDelta;
	if(m_fLifeTime <= 0.0f)
	{
		COORD c = rt.Center(); // 폭탄 터지는 위치
		GameMng()->ResistExplosion(c.X, c.Y); // 실제 폭탄처리 구현 호출
		return true;
	}

	return false;
}

void Bomb::Explosived(Bomb* a_refBomb)
{
	if (a_refBomb == this) { return; }

	// Bomb!
}
