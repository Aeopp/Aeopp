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

	_Hero_or_Enemy = F;

	_y = ((rand() % 10)+3); _x = ((rand() % 76)+5); _Char = _CharArr[rand() % 4];

	if (_x >= 78) { _x = 77; };

	_left = (_x - (_Char.size() / 2));

	_right = (_x + (_Char.size() / 2));

	RharInstance();
	// X,Y��ǥ�� ����     ĳ�� ��絵 ����
	_speed = (rand() % 45)+45;  // ���ǵ� ���� �ν��Ͻ̽� ����ֱ�

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
		gotoxy3(_left, _y); cout << _Char;
	}

	else if (reMove_Draw == F)
	{
		gotoxy3(_left, _y); cout << _Rhar;
	}

}

Key Jet::EnemyRandomMove()
{
	if (_exist == T)
	{
		{
			Key E_Key = Key::None;
			int temp = rand() % 5;
		

			if (--_dircount == 0)
			{
				_dir = !_dir;
				_dircount = Default_dircount;
			}

			if (_dir == LEFT) { E_Key = Key::Left; }
			if (_dir == RIGHT) { E_Key = Key::Right; }
			/*
			if (temp==0) { E_Key = Key::Left; }
			if (temp==1) { E_Key = Key::Right; }*/
			if (_left < 3) { _dir = RIGHT; E_Key = Key::Right; return E_Key; }
			if (_right > 79) { _dir=LEFT; E_Key = Key::Left; return E_Key;}

		
			if (temp == 4) { E_Key = Key::Enemy_Fire; }
	/*		if (temp == 2) { E_Key = Key::UP; return E_Key; }
			if (temp == 3) { E_Key = Key::DOWN; return E_Key; }*/
			return E_Key;
		}
	}
}

void Jet::Move(Key E_Key, Frame_t DeltaTime, vector<Bullet>& Bullet_vec,vector<Jet>& Jet_vec)
{
	if ((E_Key == Key::None) || (_exist == F)) { return; }

	static int Bulletcount = 0;

	if (Bulletcount > 195) { Bulletcount = 0; }

	// �ƹ��͵� ������ �ʾҴٸ� �ƹ��͵� �����ʴ´�.
	// �̵��ӵ� ���ؼ� ó���ؾ���
	// �̵��ӵ�* ��ŸŸ��;

	float vector2 = _speed * DeltaTime;

	bool move = T;                                 // �̵����ɻ��°˻�

	switch (E_Key)
	{                               // �ǵ�����Ұ� x,y�� ����Ʈ ����Ʈ
	case (Key::Left):

		_x -= vector2; _left -= vector2; _right -= vector2; // ��ǥ����

		for (auto& elem : Jet_vec)
		{
			move = IsCross(elem);
			if (move == F) { break; }
		}
		if (move == F)  // �浹�������
		{
			_x += vector2; _left += vector2; _right += vector2; // ��ǥ �ٽ� �ǵ�����
			return;
		}
		else if(move==T)               // �浹 �ƴ�
		{
			_x += vector2; _left += vector2; _right += vector2;
			Render(F);
			_x -= vector2; _left -= vector2; _right -= vector2;
		}
		break;
	case (Key::Right):
		_x += vector2; _left += vector2; _right += vector2;



		for ( auto& elem : Jet_vec)
		{
			move = IsCross(elem);
			if (move == F) { break; }
		}

		if (move == F)  // �浹�������
		{
			_x -= vector2; _left -= vector2; _right -= vector2; // ��ǥ �ٽ� �ǵ�����
			return;
		}
		else  if (move == T)                // �浹 �ƴ�
		{
			_x -= vector2; _left -= vector2; _right -= vector2;
			Render(F);
			_x += vector2; _left += vector2; _right += vector2;
		}
		break;
	case (Key::UP):                            
		_y -= (vector2 / 2.5f);        // �Ȱ��� ������ ������ Y��ǥ�� ����ġ�� ��������� ũ�� 2.5f ������ �����ϱ�

		for ( auto& elem : Jet_vec)
		{
			move = IsCross(elem);
			if (move == F) { break; }
		}

		if (move == F)  // �浹�������
		{
			_y += (vector2 / 2.5f);  // ��ǥ �ٽ� �ǵ�����
			return;
		}
		else if (move == T)                 // �浹 �ƴ�
		{
			_y += (vector2 / 2.5f);
			Render(F);
			_y -= (vector2 / 2.5f);
		}
		break;
	case (Key::DOWN):
		_y += (vector2 / 2.5f);       // �Ȱ��� ������ ������ Y��ǥ�� ����ġ�� ��������� ũ�� 2.5f ������ �����ϱ�

		for (auto& elem : Jet_vec)
		{
			move = IsCross(elem);
			if (move == F) { break; }
		}

		if (move == F)  // �浹�������
		{
			_y -= (vector2 / 2.5f);  // ��ǥ �ٽ� �ǵ�����
			return;
		}
		else  if (move == T)                // �浹 �ƴ�
		{
			_y -= (vector2 / 2.5f);
			Render(F);
			_y += (vector2 / 2.5f);
		}
		break;
	case (Key::Fire):
		Bullet_vec[Bulletcount++].Init(_x, _y, Up, T, 120.0f, 30.0f, "��");
		Bullet_vec[Bulletcount++].Init(_x + 2, _y, Up, T, 120.0f, 30.0f, "��");
		Bullet_vec[Bulletcount++].Init(_x - 2, _y, Up, T, 120.0f, 30.0f, "��");
		break;
	case (Key::Bomb):
		// ��ź
		break;
	case (Key::Item):
		// ������
		break;
	case(Key::Enemy_Fire):
		Bullet_vec[Bulletcount++].Init(_x, _y, Down, T, (rand() % 120) + 60, (rand() % 30)+15, _BulletArr[rand() % 10]);
		break;
	}
}

bool Jet::IsCross( Jet& rhs)
{    
	if (&rhs == this) { return T; }

	if ((_left < 3) ||(_right>79))
	{
		_dir = !_dir;
		return F;
	}

	if (!(_y >= 3 && _y <= 50))
	{
		return F;
	}

	auto abs_y = _y - rhs._y;

	abs_y = +abs_y;

	/*if ((_y == rhs._y) && (_x >= rhs._left) && (_x <= rhs._right))
	{
		return F;
	}
*/
	if ( (_left<rhs._right) &&
		 (_right>rhs._left) &&(_y==rhs._y))
		
	{
		_dir = !_dir;
		return F;
	}
	return T;


	//if (      ((_y == rhs._y) && (rhs._left <= _right) )
	//	||( ((_y == rhs._y) && rhs._right >= _left) )  )
	//{
	//	return F; // �浹�������
	//}
	//return T; // �浹�ƴ�
}


