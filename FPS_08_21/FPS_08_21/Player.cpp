#include "pch.h"
#include "Player.h"


Player::Player(int x, int y) : Object(x, y)
{
}


Player::~Player()
{
}

eObjectType Player::GetObjectType() const
{
	return eObjectType::Player;
}
