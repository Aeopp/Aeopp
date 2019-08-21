#include "pch.h"
#include "Bomb.h"


Bomb::Bomb(int x, int y) : Object(x, y)
{
}

Bomb::~Bomb()
{
}

eObjectType Bomb::GetObjectType() const
{
	return eObjectType::Bomb;
}

// void Bomb::Init()
// 앞서 언급하였듯이 플레이어의 폭탄 파워와 폭탄 카운트값으로
// 자신의 변수값을 초기화하는 구현 GameMng()->GetBombData(this);

// void Bomb::Update(float a_fDelta)
// 아규먼트값으로 들어온 델타타임 만큼
// 폭탄 카운트를 줄여나가며
// 폭탄카운트가 0이 된순간 !! BOMB !!! 이지만 아직 폭발으 미구현

// void Bomb::Explosived(Bomb* a_refBomb)
// 인터페이스와 이름에서 알수있듯 폭발처리를 하는 함수이지만
// 아직 미구현



