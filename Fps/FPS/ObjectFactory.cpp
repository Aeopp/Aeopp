#include "pch.h"
#include "ObjectFactory.h"

#include "Wall.h"
#include "Box.h"
#include "Door.h"
#include "Item.h"
#include "Bomb.h"
#include "Monster.h"
#include "Player.h"

Object* ObjectFactory::Make(eObjectType a_eType, int x, int y)
{
	Object* pReturn = nullptr;
	switch (a_eType)
	{
		case eObjectType::Wall:		{ pReturn = new Wall(x, y); }  break;
		case eObjectType::Box:		{ pReturn = new Box(x, y); } break;
		case eObjectType::Door:		{ pReturn = new Door(x, y); } break;
		case eObjectType::Item:		{ pReturn = new Item(x, y); } break;
		case eObjectType::Bomb:		{ pReturn = new Bomb(x, y); } break;
		case eObjectType::Monster:	{ pReturn = new Monster(x, y); } break;
		case eObjectType::Player:	{ pReturn = new Player(x, y); } break;
	}

	assert(pReturn != nullptr);
	return pReturn;
}