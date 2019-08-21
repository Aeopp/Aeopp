#pragma once
#include "Object.h"

class Door : public Object
{
public:
	Door(int x, int y);
	virtual ~Door();

	// Object을(를) 통해 상속됨
	virtual eObjectType GetObjectType() const override;
};

