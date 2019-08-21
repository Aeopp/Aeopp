#include "pch.h"
#include "Monster.h"


Monster::Monster(int x, int y) : Object(x, y)
{
}


Monster::~Monster()
{
}

eObjectType Monster::GetObjectType() const
{
	return eObjectType::Monster;
}
