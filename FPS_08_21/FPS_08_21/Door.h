#pragma once
#include "Object.h"

class Door : public Object
{
public:
	Door(int x, int y);
	virtual ~Door();

	// Object��(��) ���� ��ӵ�
	virtual eObjectType GetObjectType() const override;
};

