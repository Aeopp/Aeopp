#include "pch.h"
#include "Player.h"

#include "GameManager.h"


Player::Player(int x, int y) : Object(x, y)
, m_Data{
		{ ' ', ' ', ' ', ' ', ' ' },
		{ ' ', 'P', 'P', 'P', ' ' },
		{ ' ', 'P', ' ', 'P', ' ' },
		{ ' ', 'P', 'P', 'P', ' ' },
		{ ' ', ' ', ' ', ' ', ' ' } }
{
	m_pNowAni = &m_Data;

	rt.x += 1;
	rt.y += 1;
	rt.w = TileSize - 2;
	rt.h = TileSize - 2;
	
	// Rect 스트럭쳐 변수 초기화하는 부분 추가
}

Player::~Player()
{
	m_refStat = nullptr;
}

eObjectType Player::GetObjectType() const
{
	return eObjectType::Player;
}

Rect Player::GetRendertRect() const
{
	return Rect{ rt.x -1, rt.y - 1, rt.w, rt.h };
}     

void Player::SetStat(struct CharacterData* a_pStat)
{
	m_refStat = a_pStat;
	// 아규먼트값으로 자신 스텟 초기화
	m_nPutBombCount = 0;
	// 생성된 직후이니 폭탄카운트는 0
}

bool Player::_Update(float a_fDelta)
{
	Move(a_fDelta);
	BombCheck();
	// 업데이트 함수에서 이동처리와 폭탄체
	return false;
}

void Player::Move(float a_fDeltaTime)
{
	float fAdd = a_fDeltaTime * (m_refStat->fMoveSeepd);
	 // 델타타임을 곱함으로써 업데이트 주기에 영향을 받지않고
	 // 언제나 일정한 속도로 움직이게 가속도를 구함
	float fX = 0; // Vector2 . X
	float fY = 0; // Vector2 . Y

	if (IsKeyDown(eKey::A)) { fX -= fAdd; }
	if (IsKeyDown(eKey::D)) { fX += fAdd; }

	if (IsKeyDown(eKey::S)) { fY += fAdd; }
	if (IsKeyDown(eKey::W)) { fY -= fAdd; }

	rt.x += fX;
	rt.y += fY;
	// 좌표갱신
}

void Player::BombCheck()
{
	if(m_nPutBombCount >= m_refStat->nBombCount)  { return; }
		// 현재 설치된 폭탄이 객체가 설치할수있는 최대폭탄 개수라면 폭탄 설치 불가능
	if (IsKeyDown(eKey::Space))
	{
		COORD c = rt.Center();           // 자신 좌표에0 폭탄 설치하는 처리
		if( GameMng()->AddBomb(c.X, c.Y) == true )  
		{
			++m_nPutBombCount; // 설치된 폭탄카운트 추가
		}
	}
}
