#pragma once

class ObjectFactory
{
public:
	static class Object* Make(eObjectType a_eType, int x, int y);
};
