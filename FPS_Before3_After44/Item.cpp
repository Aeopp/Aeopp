#include "pch.h"
#include "Item.h"

#include "GameManager.h"

Item::Item(int x, int y) : Object(x, y),

m_Item{
	{
			{ ' ', ' ', ' ', ' ', ' ' },
			{ '|', 'P', 'P', ' ', '|' },
			{ '|', 'P', 'P', ' ', '|' },
			{ '|', 'P', ' ', ' ', '|' },
			{ ' ', ' ', ' ', ' ', ' ' },
	},

	{
			{ ' ', ' ', ' ', ' ', ' ' },
			{ '|', 'C', 'C', 'C', '|' },
			{ '|', 'C', ' ', ' ', '|' },
			{ '|', 'C', 'C', 'C', '|' },
			{ ' ', ' ', ' ', ' ', ' ' },
	},

	{
			{ ' ', ' ', ' ', ' ', ' ' },
			{ '|', ' ', 'S', ' ', '|' },
			{ '|', 'S', 'S', 'S', '|' },
			{ '|', ' ', 'S', ' ', '|' },
			{ ' ', ' ', ' ', ' ', ' ' },
	},
}
{
	int nNum = (rand() % (int)eItem::Max);
	m_eType = (eItem)nNum;

	m_pNowAni = &m_Item[nNum];
}

Item::~Item() { }

eObjectType Item::GetObjectType() const
{
	return eObjectType::Item;
}

void Item::Interaction(class Hero* a_refHero)
{
	GameMng()->RemoveObject(this);
	GameMng()->ObtainItem(m_eType);
}
