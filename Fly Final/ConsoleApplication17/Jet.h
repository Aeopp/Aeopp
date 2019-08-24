#pragma once
#include "Define.h"
#include "Bullet.h"

class Jet
{
public:
	float _x, _y, _left, _right, _speed;

	bool _exist = F;

	bool _Hero_or_Enemy = T; // F일시 에너미 T일시 히어로; // 총알발사시 검사용

	bool _dir = rand() % 2; // 일단은 에너미 Left or Right 움직임 상태 변수

	int Default_dircount = (rand() % 30)+40;

	int  _dircount = Default_dircount;

	string _Char;
	string _Rhar;

	string _CharArr[4] = { "vVWVv","qpHqp","yoYoy","ozZzo" }; // 적비행기;
	string _BulletArr[10] = { "V","↓","↓","▼","@","▼","*","●","＊","●" };

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
	void Move(Key E_Key, Frame_t DeltaTime, vector<Bullet>& Bullet_vec, vector<Jet>& Jet_vec); // 키입력,델타,총알벡터(총알발사),비행기벡터(비행기충돌검사용)

	bool IsCross( Jet& Jet_vec);
};

