#pragma once
#include <iostream>
#include "Bullet.h"

Bullet::Bullet()
{
	_exist = F;
}

void gotoxy2(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

Bullet::Bullet(float x, float y, bool UpDown, bool exist, float disTance, float speed, string Char)
{
	Init(x, y, UpDown, exist, disTance, speed, Char);
}

void Bullet::Init(float x, float y, bool UpDown, bool exist, float disTance, float speed, string Char)
{
	_exist = exist;

	_UpDown = UpDown;

	_x = x;

	_UpDown == Up ? _y = y - 1 : _y = y + 1;

	_disTance = disTance, _speed = speed, _Char = Char;
}

void Bullet::Render(Frame_t deltaTime) 
{
	BulletEffect();
	
	if (_exist == F) { return; }

	gotoxy2(_x, _y); cout << _Char;
}

void Bullet::Update(Frame_t deltaTime)
{
	if (_exist == F) { return; }
	
	if ((_y <= 3) || (_y >= 49))
	{
		_exist = F;
	}

	gotoxy2(_x,_y); cout << ' ';

	if (--_disTance <= 0)
	{
		_exist = F;
	}

	float vector2 = (_speed * deltaTime);

	_UpDown == Up ? _y -= vector2 : _y += vector2;
}

bool Bullet::Crash(float left, float right, float y,bool Hero=F)
{
	if (_UpDown == Down&&Hero==F) {return Survive;}

	if (_exist == F) { return Survive; }

	int abs_y = _y - y;

	abs_y=std::abs(abs_y);

	if ( (abs_y==0)&& (_x >= left) && (_x <= right))
	{
		// ³Í ÃÑ¾ËÀ» ¸Â¾Ò´Ù
		_exist = F;

		gotoxy2(_x, _y); cout << ' ';

		EffectCount = DefaultEffectCount;       // ÀÌÆåÆ® Ä«¿îÆ® ÃÊ±âÈ­

		Effect_Left = left;

		Effect_y = y;

		BulletEffect();          // ÀÌÆåÆ® ÁÂÇ¥ ¼Â¾÷

		return Die;
	}

	else
		return Survive;
}

void Bullet::BulletEffect()
{
	if (_exist == T)
	{
		return;
	}
	if (EffectCount > 0.1f)
	{
		EffectCount--;
		gotoxy2(Effect_Left, _y); cout << "#####";
		gotoxy2(Effect_Left, _y); cout << "     ";
	}
	if (EffectCount < 0.0f)
	{
		
	}
	/*if (EffectCount < 1.5f)
	{
		gotoxy2(Effect_Left, _y); cout << "     ";
		EffectCount = 0.0f;
	}*/
	/*if (--EffectCount < 0.3f)
	{
		gotoxy2(Effect_Left, _y); cout << "     ";
	}*/
}
