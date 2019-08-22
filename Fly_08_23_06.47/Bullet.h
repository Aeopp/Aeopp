#pragma once
#include "Define.h"

class Bullet
{
public:
	float _x, _y, _disTance, _speed; string _Char;
	bool _UpDown,_exist = F; 

	//  ��ǥ ���ǵ� ��� UpDown F�̸� �Ʒ��� T�̸� ���� �߻�Ǵ� �Ѿ�
	// ���ǵ�� �ִ�Ÿ��� �˾Ƽ� �����ϱ�.
	Bullet()
	{
		_exist = F;
	}

	Bullet
	(float x, float y, bool UpDown,bool exist, float disTance, float speed, string Char);

	void Init
	(float x, float y, bool UpDown, bool exist, float disTance, float speed, string Char);

	void Render(Frame_t deltaTime)const;
	void Update(Frame_t deltaTime);
};

