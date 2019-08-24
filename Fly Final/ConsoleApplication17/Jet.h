#pragma once
#include "Define.h"
#include "Bullet.h"

class Jet
{
public:
	float _x, _y, _left, _right, _speed;

	bool _exist = F;

	bool _Hero_or_Enemy = T; // F�Ͻ� ���ʹ� T�Ͻ� �����; // �Ѿ˹߻�� �˻��

	bool _dir = rand() % 2; // �ϴ��� ���ʹ� Left or Right ������ ���� ����

	int Default_dircount = (rand() % 30)+40;

	int  _dircount = Default_dircount;

	string _Char;
	string _Rhar;

	string _CharArr[4] = { "vVWVv","qpHqp","yoYoy","ozZzo" }; // �������;
	string _BulletArr[10] = { "V","��","��","��","@","��","*","��","��","��" };

	Jet()
	{
		_x = 0; _y = 0; _left = 0; _right = 0; _speed = 0; _exist = F;
	};

	Jet EnemyInstance();
	void RharInstance();
	void Init(float x, float y, float speed, bool exist, string Char);
	Jet(float x, float y, float speed, bool exist, string Char);

	void Render(bool reMove_Draw)const;

	Key EnemyRandomMove();
	void Move(Key E_Key, Frame_t DeltaTime, vector<Bullet>& Bullet_vec, vector<Jet>& Jet_vec); // Ű�Է�,��Ÿ,�Ѿ˺���(�Ѿ˹߻�),����⺤��(������浹�˻��)

	bool IsCross( Jet& Jet_vec);
};

