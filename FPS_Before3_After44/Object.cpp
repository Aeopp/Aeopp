#include "pch.h"
#include "Object.h"

Object::Object(int _x, int _y) : x(_x), y(_y) { }

Object::~Object() { }

void Object::Init() { }

void Object::Explosived(class Bomb* a_refBomb) { }
void Object::Interaction(class Hero* a_refHero) { }
void Object::_PreUpdate(float a_fDelta) {}
void Object::_Update(float a_fDelta) {}

void Object::SetMap(char** a_refMap)
{
	assert(a_refMap != nullptr);
	// 인자로 받은 포인터가 가리키는 맵데이터를 가리키기
	// 맵을 활용하기위한 준비

	m_refMap = a_refMap;
}

void Object::Update(float a_fDelta)
{

	_PreUpdate(a_fDelta);
	// 업데이트 하기전에 해야하는 행동은 여기서 구현
	_Update(a_fDelta);
	
}

void Object::Render()
{
	int nX = x * TileSize;
	int nY = y * TileSize;

	for (int i = 0; i < TileSize; ++i)
	{
		char* pDest = m_refMap[nY + i];

		memcpy_s((pDest + nX), TileSize * sizeof(char),
			(*m_pNowAni)[i], TileSize * sizeof(char));
	}
}

