#pragma once
#include "Object.h"

class Player : public Object
{
public:
	Player(int x, int y);
	virtual ~Player();

	// Object��(��) ���� ��ӵ�
	virtual eObjectType GetObjectType() const override;
};

