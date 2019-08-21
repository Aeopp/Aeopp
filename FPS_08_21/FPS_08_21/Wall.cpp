#include "pch.h"
#include "Wall.h"


Wall::Wall(int x, int y) : Object(x, y)
{
}


Wall::~Wall()
{
}

eObjectType Wall::GetObjectType() const
{
	return eObjectType::Wall;
}
