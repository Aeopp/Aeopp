#pragma once

class Object
{
public:
	Object(int _x, int _y);
	virtual ~Object();
	virtual eObjectType GetObjectType() const = 0;

	virtual void Render();
	virtual void Update(float a_fDelta);




public:
	int x;
	int y;
};
