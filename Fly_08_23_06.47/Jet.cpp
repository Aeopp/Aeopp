#pragma once
#include "Jet.h"

void gotoxy3(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}


Jet Jet::EnemyInstance()
{
	_exist = T;

	_Hero_or_Enemy = T;

	_y = (rand()%10); _x = (rand() % 100); _Char = _CharArr[rand() % 4]; 

	_left = (_x - (_Char.size() / 2));

	_right = (_x + (_Char.size() / 2));

	RharInstance();
	// X,Y좌표는 랜덤     캐릭 모양도 랜덤
	_speed = (rand() % 30);  // 스피드 랜덤 인스턴싱시 살려주기

	return *this;
}

void Jet::RharInstance()
{
	if (_exist == F) { return; }

	for (unsigned i = 0; i <= _Char.size(); ++i)
	{
		_Rhar.push_back(' ');
	}
}

void Jet::Init(float x, float y, float speed, bool exist, string Char)
{
	_exist = exist;

	_x = x, _y = y, _speed = speed, _Char = Char; RharInstance();

	_left = _x - (_Char.size() / 2);  _right = _x + (_Char.size() / 2);
}

Jet::Jet(float x, float y, float speed, bool exist, string Char)
{
	Init(x, y, speed, exist, Char);
}

void Jet::Render(bool reMove_Draw) const
{
	if (_exist == F) { return; }

	if (reMove_Draw == T) 
	{
		gotoxy3(_left,_y); cout << _Char;
	}
	else if (reMove_Draw == F) 
	{
		gotoxy3(_left,_y); cout << _Rhar;
	}
}

Key Jet::EnemyRandomMove()
{
	if (_exist == T) 
	{
		{
			Key E_Key = Key::None;

			int temp = rand() % 10;

			if (temp == 0) { E_Key = Key::Left; }
			if (temp == 1) { E_Key = Key::Right; }
			if (temp == 2) { E_Key = Key::UP; }
			if (temp == 3) { E_Key = Key::DOWN; }
			if (temp == 4) { E_Key = Key::Enemy_Fire; }

			return E_Key;
		}
	}
}

void Jet::Move(Key E_Key, Frame_t DeltaTime,vector<Bullet>& Bullet_vec)
{
	if ( (E_Key == Key::None) ||  (_exist == F) ) { return; }

	static int Bulletcount = 0;

	if (Bulletcount > 195) { Bulletcount = 0; }

	// 아무것도 누르지 않았다면 아무것도 하지않는다.
	// 이동속도 곱해서 처리해야함
	// 이동속도* 델타타임;

	float vector2 = _speed*DeltaTime;

	switch (E_Key)
	{// 건드려야할것 x,y랑 레프트 라이트
	case (Key::Left):
		Render(F);
		_x -= vector2; _left -= vector2; _right -= vector2;
		break;
	case (Key::Right):
		Render(F);
		_x += vector2; _left += vector2; _right += vector2;
		break;
	case (Key::UP):
		Render(F);
		_y -= (vector2 / 2.5f);          // 똑같이 연산을 때려도 Y좌표는 증감치가 너무 커서 나눠주는 조치를함
		break;
	case (Key::DOWN):
		Render(F);
		_y += (vector2 / 2.5f);
		break;
	case (Key::Fire):
		Bullet_vec[Bulletcount++].Init(_x, _y, Up, T, 60.0f, 15.0f, "*");
		Bullet_vec[Bulletcount++].Init(_x+1, _y, Up, T,60.0f, 15.0f, "*");
		Bullet_vec[Bulletcount++].Init(_x-1, _y, Up, T, 60.0f, 15.0f, "*");

		break;
	case (Key::Bomb):
		// 폭탄
		break;
	case (Key::Item):
		// 아이템
		break;
	case(Key::Enemy_Fire):
		Bullet_vec[Bulletcount++].Init(_x, _y, Down, T, (rand()%30)+30, (rand() % 15),_BulletArr[rand()%10]);
		break;
	}
}
