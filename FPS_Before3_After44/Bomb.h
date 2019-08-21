#pragma once

#include "Object.h"

class Bomb : public Object
{
public:
	Bomb(int x, int y);
	virtual ~Bomb();

	// Object을(를) 통해 상속됨
	virtual eObjectType GetObjectType() const override;

	void Init() override;
	void _Update(float a_fDelta) override;
	void Explosived(class Bomb* a_refBomb) override;

	float		m_fLifeTime = 2.0f;
	int			m_nExplosiveRange = 2;
	RenderTile	m_Data;
};

