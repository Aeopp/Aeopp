#pragma once
#include "Object.h"

class Wall : public Object
{
public:
	Wall(int x, int y);
	virtual ~Wall();

	// Object을(를) 통해 상속됨
	virtual eObjectType GetObjectType() const override;
};

