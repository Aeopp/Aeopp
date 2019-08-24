#pragma once
#include "Game.h"
#include "Define.h"


void gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

Key Game::IsKeyDown()
{
	{
		if ((GetAsyncKeyState(VK_LEFT) & 0x8000)) { return Key::Left; }
		if ((GetAsyncKeyState(VK_RIGHT) & 0x8000)) { return Key::Right; }
		if ((GetAsyncKeyState(VK_UP) & 0x8000)) { return Key::UP; }
		if ((GetAsyncKeyState(VK_DOWN) & 0x8000)) { return Key::DOWN; }
		if ((GetAsyncKeyState(VK_SPACE) & 0x8000)) { return Key::Fire; }
		if ((GetAsyncKeyState(VK_LSHIFT) & 0x8000)) { return Key::Bomb; }
		if ((GetAsyncKeyState(VK_TAB) & 0x8000)) { return Key::Item; }

		return Key::None; // Ű�� ������ �ʾҴٸ� None ��ȯ if������ ���Ͱ� �ȵ����Ƿ�
	}
}
void Game::Init()
{
	_Map.Init();  // <- �� �¾�

	Bullet_vec.reserve(200);

	for (int i = 0; i < 199; ++i)
	{
		Bullet_vec.push_back(Bullet());
	}

	Enemy_vec.reserve(100);

	for (int i = 0; i < 99; ++i)
	{
		Enemy_vec.push_back(Jet());
	}

	Hero.Init(30.0f, 30.0f, 50.0f, T, string("oOAOo"));
}

void Game::MainUpdate(Frame_t DeltaTime)
{
	if (player_Hp<=10) 
	{
		system("cls"); gotoxy(25, 25); cout << "Game over Continue Input N \n\n\n\n\n\n\n\n\n\n"; 
		char Input = 0;
		cin >> Input;
		if (Input == 'N' || Input == 'n') { 
			player_Hp = Default_Hp;
			Run(); }
		else exit(0);
	}

	static int EnemySpawnDelay = 0;        // �����ֱ�

	static int Enemy_vec_count = 0;         // ���� �迭 �ε���

	if (Enemy_vec_count > 95) { Enemy_vec_count = 0; }

	if (EnemySpawnDelay++ == EnmeySpawnDelayTime)       //   1�����Ӵ� 1
	{
		if (Enemy_vec[Enemy_vec_count]._exist == F)
		{
			Enemy_vec[Enemy_vec_count].EnemyInstance();       // Init �� ������ ���ߴٸ� ���⼭ ������ ���� ������ ����

			Enemy_vec_count++;

			EnemySpawnDelay = 0;
		}
	}

	Hero.Move(IsKeyDown(),DeltaTime,Bullet_vec,Enemy_vec); // ����� �����̱�

	for (auto& Bullet_elem : Bullet_vec)
	{
		if (Bullet_elem.Crash(Hero._left, Hero._right, Hero._y,T) == Die)
		{
			player_Hp -= 10;
		}
	}

	for (auto& Enemy_elem : Enemy_vec)
	{
		Enemy_elem.Move(Enemy_elem.EnemyRandomMove(), DeltaTime, Bullet_vec, Enemy_vec);

		for (auto& Bullet_elem : Bullet_vec)
		{

		if(	Bullet_elem.Crash(Enemy_elem._left, Enemy_elem._right,Enemy_elem._y,F)==Die)
			{
				Enemy_elem._exist = F;
				Enemy_elem._left = 100;
				Enemy_elem._y = 100;
				Enemy_elem._x = 100;
				break;
			}
		}
	} 

	for (auto& elem : Bullet_vec)
	{
		elem.Update(DeltaTime);
	}

	// �̵�ó���� �ڽ���ǥ �����ְ� ��ǥ���� �ֽŰ����ؼ� ��������
	// ĳ���ͱ׸����ϱ�
}

void Game::MainRender(Frame_t DeltaTime)
{
	Hero.Render(T);

	for ( auto& elem : Bullet_vec)
	{
		elem.Render(DeltaTime);
	}

	for (const auto& elem : Enemy_vec)
	{
		elem.Render(DeltaTime);
	}

	// ������Ʈ���� ��ǥ������ ��ӵȰ��̴�
	// ���⼭�� �Ű澲������ ��ǥ���� �޾Ƽ� �׸��⸸ �ϱ�
}

void Game::Run()
{
	{
		Init();

		Frame_t delta_Time = 0;

		Frame_t Last_Stamp = 0, Swatch = 0;

		cout << endl << endl;

		cout << "			Frame : " << Frame << endl << endl;

		std::cout << "			Test Frame : " << TargetFrame << " M/S" << endl << endl;

		while (1)
		{
			Frame_t curr_Time = clock(); // ����ð�

			Frame_t Frame_Time = TargetFrame + Last_Stamp + Swatch;
			// Last Update Time + Frame Time + ¥�����ð�
			if (curr_Time > Frame_Time) // ����ð��� curr_Time �� �߿��ѻ�����
			{
				delta_Time = (curr_Time - Last_Stamp) / static_cast<Frame_t>CLOCKS_PER_SEC;

				gotoxy(25,60);
				std::cout << "Curr Delta Time : " << delta_Time << endl << endl;
				cout << "			Player_HP : " << player_Hp << endl << endl;
				// �и������� ������ ����������� �۾��ϱ� ���ϰ� ��ȯ����

				// ��ŸŸ���� ����ð����� ������ ������Ʈ�� �ð��� ������ (�۵� Ȯ��)
				// ��ǻ�Ͱ� ������ ����Ǽ� ������ �����Ӱ��ݻ��̿� ��翬���� ���Ҽ��ִٸ�
				// delta_Time == Frame_Time �̴�.

				Swatch = abs(curr_Time - Frame_Time); // ¥���� �ð� ���� curr_Time �� �����ؾ���  (�۵�Ȯ��)
				cout << "			Swatch : " << Swatch << endl << endl;
				// �ϵ������ ������ ����ȴٸ� Swatch == epsilon

				MainUpdate(delta_Time);
				MainRender(delta_Time);

				Last_Stamp = clock();
			}
		}
	}
}
