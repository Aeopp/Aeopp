#pragma once
#include "Object.h"

class Door : public Object
{
public:
	enum class eDoorState
	{
		Close,
		Open,
	};

	Door(int x, int y);
	virtual ~Door();

	// Object을(를) 통해 상속됨
	virtual eObjectType GetObjectType() const override;

	virtual void Init() override;
	virtual bool Interaction(class Player* a_refHero) override;

	eDoorState m_eState = eDoorState::Close;

	RenderTile	m_Close;
	RenderTile	m_Open;
};

