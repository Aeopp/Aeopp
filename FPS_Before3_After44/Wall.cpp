#include "pch.h"
#include "Wall.h"


Wall::Wall(int x, int y) : Object(x, y)
, m_Data{
		{ '1', '1', '1', '1', '1' },
		{ '1', 'M', 'M', 'M', '1' },
		{ '1', 'M', ' ', 'M', '1' },
		{ '1', 'M', 'M', 'M', '1' },
		{ '1', '1', '1', '1', '1' } }
{
	m_pNowAni = &m_Data;
}

Wall::~Wall()
{
}

eObjectType Wall::GetObjectType() const
{
	return eObjectType::Wall;
}
