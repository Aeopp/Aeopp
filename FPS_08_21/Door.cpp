#include "pch.h"
#include "Door.h"

Door::Door(int x, int y) : Object(x, y)
{
}

Door::~Door()
{
}

eObjectType Door::GetObjectType() const
{return eObjectType::Door;}



// void Door::Init()
// m_eState 
