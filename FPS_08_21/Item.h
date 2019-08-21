#pragma once
#include "Object.h"

class Item : public Object
{
public:
	Item(int x, int y);
	virtual ~Item();

	// Object을(를) 통해 상속됨
	virtual eObjectType GetObjectType() const override;

	//virtual void Interaction(class Hero* a_refHero) override;
	// 단순히 GameManager 의
	//RemoveObject(this); 
	//ObtainItem(m_eType); 
	// 함수를 순차적으로 호출하는 역할
	

	
};

