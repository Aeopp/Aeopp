#pragma once
#include "Define.h"

class Bullet
{
public:
	float _x, _y, _disTance, _speed; string _Char;
	bool _UpDown,_exist = F; 

	//  좌표 스피드 모양 UpDown F이면 아래로 T이면 위로 발사되는 총알
	// 스피드와 최대거리는 알아서 조절하기.
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

