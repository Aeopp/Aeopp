
#include "Object.h"

class Monster : public Object
{
public:
	Monster(int x, int y);
	virtual ~Monster();

	// Object을(를) 통해 상속됨
	virtual eObjectType GetObjectType() const override;
	RenderTile	m_Data;
};
