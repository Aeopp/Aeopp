#pragma once
#include "Object.h"

class Bomb : public Object
{
public:
	Bomb(int x, int y);
	virtual ~Bomb();

	// Object��(��) ���� ��ӵ�
	virtual eObjectType GetObjectType() const override;
};

