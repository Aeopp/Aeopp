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
// ��ź�� ���� �ڽ��� ����ó���� 
// RemoveObject(this); �Լ�ȣ��� ����
// RemoveObject �Լ��� ���� ���� ���� !!
// ��ü������ ������ !!
// DropItem(this) �Լ��� ȣ�������� ���� �������� �ʾ���


