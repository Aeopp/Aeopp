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

	//  좌표 스피드 모양 UpDown F이면 아래로 T이면 위로 발사되는 총알

	// 스피드와 최대거리는 알아서 조절하기.
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

