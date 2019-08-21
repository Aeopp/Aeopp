#include "pch.h"
#include "Item.h"


Item::Item(int x, int y) : Object(x, y)
{
}


Item::~Item()
{
}

eObjectType Item::GetObjectType() const
{
	return eObjectType::Item;
}
