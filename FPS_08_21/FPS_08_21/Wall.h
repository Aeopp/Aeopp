#pragma once
#include "Object.h"

class Wall : public Object
{
public:
	Wall(int x, int y);
	virtual ~Wall();

	// Object��(��) ���� ��ӵ�
	virtual eObjectType GetObjectType() const override;
};

