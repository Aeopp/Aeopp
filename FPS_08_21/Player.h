#pragma once
#include "Object.h"

class Player : public Object
{
public:
	Player(int x, int y);
	virtual ~Player();

	// Object을(를) 통해 상속됨
	virtual eObjectType GetObjectType() const override;
};

