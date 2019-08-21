#pragma once

#include "Object.h"

class Box : public Object
{
public:
	Box(int x, int y);
	virtual ~Box();

	// Object을(를) 통해 상속됨
	virtual eObjectType GetObjectType() const override;
};

