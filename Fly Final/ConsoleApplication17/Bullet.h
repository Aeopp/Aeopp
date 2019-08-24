#pragma once
#include "Define.h"

class Bullet
{
public:
	int Effect_Left = 100;
	int Effect_y = 100;


	float _x=0.0f, _y= 0.0f, _disTance, _speed; string _Char;

	float EffectCount = 0.0f;

	bool _UpDown, _exist = F;

	//  ��ǥ ���ǵ� ��� UpDown F�̸� �Ʒ��� T�̸� ���� �߻�Ǵ� �Ѿ�

	// ���ǵ�� �ִ�Ÿ��� �˾Ƽ� �����ϱ�.
	Bullet();

	Bullet
	(float x, float y, bool UpDown, bool exist, float disTance, float speed, string Char);

	void Init
	(float x, float y, bool UpDown, bool exist, float disTance, float speed, string Char);

	void Render(Frame_t deltaTime);
	void Update(Frame_t deltaTime);
	bool Crash(float left, float right, float y,bool Hero);
	void BulletEffect();
};

