#include "pch.h"
#include "Object.h"

Object::Object(int _x, int _y) : x(_x), y(_y) { }
Object::~Object() { }

void Object::Render() { }
void Object::Update(float a_fDelta) { }
