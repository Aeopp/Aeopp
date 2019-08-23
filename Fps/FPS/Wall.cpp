#include "pch.h"
#include "Wall.h"


Wall::Wall(int x, int y) : Object(x, y)
, m_Data{
		{ 'W', 'W', 'W', 'W', 'W' },
		{ 'W', ' ', 'W', 'W', 'W' },
		{ 'W', 'W', 'W', 'W', 'W' },
		{ 'W', 'W', 'W', 'W', ' ' },
		{ ' ', 'W', 'W', 'W', 'W' } }
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
