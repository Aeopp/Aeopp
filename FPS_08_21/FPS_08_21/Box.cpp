#include "pch.h"
#include "Box.h"


Box::Box(int x, int y) : Object(x, y)
{
}


Box::~Box()
{
}

eObjectType Box::GetObjectType() const
{
	return eObjectType::Box;
}

// void Box::Explosived(Bomb* a_refBomb)
// 폭탄에 의한 박스의 삭제처리를 
// RemoveObject(this); 함수호출로 진행
// RemoveObject 함수는 정말 쓸모가 많다 !!
// 객체지향의 편리한점 !!
// DropItem(this) 함수도 호출하지만 아직 구현하지 않았음


