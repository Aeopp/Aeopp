#include "pch.h"
#include "Bomb.h"


Bomb::Bomb(int x, int y) : Object(x, y)
{
}

Bomb::~Bomb()
{
}

eObjectType Bomb::GetObjectType() const
{
	return eObjectType::Bomb;
}

// void Bomb::Init()
// �ռ� ����Ͽ����� �÷��̾��� ��ź �Ŀ��� ��ź ī��Ʈ������
// �ڽ��� �������� �ʱ�ȭ�ϴ� ���� GameMng()->GetBombData(this);

// void Bomb::Update(float a_fDelta)
// �ƱԸ�Ʈ������ ���� ��ŸŸ�� ��ŭ
// ��ź ī��Ʈ�� �ٿ�������
// ��źī��Ʈ�� 0�� �ȼ��� !! BOMB !!! ������ ���� ������ �̱���

// void Bomb::Explosived(Bomb* a_refBomb)
// �������̽��� �̸����� �˼��ֵ� ����ó���� �ϴ� �Լ�������
// ���� �̱���



