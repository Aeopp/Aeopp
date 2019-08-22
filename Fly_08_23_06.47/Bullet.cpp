#pragma once
#include "Bullet.h"

void gotoxy2(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

Bullet::Bullet(float x, float y, bool UpDown,bool exist, float disTance, float speed, string Char)
{
	Init(x, y, UpDown,exist, disTance, speed, Char);
}

void Bullet::Init(float x, float y, bool UpDown,bool exist, float disTance, float speed, string Char)
{
	_exist = exist;

	_UpDown = UpDown;

	_x = x; 
	
	_UpDown == Up ? _y = y - 1 : _y = y + 1;

	_disTance = disTance, _speed = speed, _Char = Char;
}

void Bullet::Render(Frame_t deltaTime) const
{
	if (_exist == F) { return; }

	gotoxy2(_x,_y); cout << _Char;
}

void Bullet::Update(Frame_t deltaTime)
{
	if (_exist == F) { return; }

	gotoxy2(_x,_y); cout <<' ';

	if (--_disTance <= 0)
	{
		_exist = F;
	}

	float vector2 = (_speed * deltaTime);

	_UpDown == Up ? _y -= vector2 : _y += vector2;
}