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

		return Key::None; // 키를 누르지 않았다면 None 반환 if문에서 필터가 안됐으므로
	}
}
void Game::Init()
{
	_Map.Init();  // <- 맵 셋업

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

	static int EnemySpawnDelay = 0;        // 스폰주기

	static int Enemy_vec_count = 0;         // 벡터 배열 인덱스

	if (Enemy_vec_count > 95) { Enemy_vec_count = 0; }

	if (EnemySpawnDelay++ == EnmeySpawnDelayTime)       //   1프레임당 1
	{
		if (Enemy_vec[Enemy_vec_count]._exist == F)
		{
			Enemy_vec[Enemy_vec_count].EnemyInstance();       // Init 을 이전에 안했다면 여기서 무조건 터짐 순서에 유의

			Enemy_vec_count++;

			EnemySpawnDelay = 0;
		}
	}

	Hero.Move(IsKeyDown(),DeltaTime,Bullet_vec,Enemy_vec); // 히어로 움직이기

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

	// 이동처리시 자신좌표 지워주고 좌표값만 최신갱신해서 렌더에서
	// 캐릭터그리게하기
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

	// 업데이트에서 좌표갱신은 약속된것이니
	// 여기서는 신경쓰지말고 좌표값만 받아서 그리기만 하기
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
			Frame_t curr_Time = clock(); // 현재시간

			Frame_t Frame_Time = TargetFrame + Last_Stamp + Swatch;
			// Last Update Time + Frame Time + 짜투리시간
			if (curr_Time > Frame_Time) // 현재시간이 curr_Time 을 추월한상태임
			{
				delta_Time = (curr_Time - Last_Stamp) / static_cast<Frame_t>CLOCKS_PER_SEC;

				gotoxy(25,60);
				std::cout << "Curr Delta Time : " << delta_Time << endl << endl;
				cout << "			Player_HP : " << player_Hp << endl << endl;
				// 밀리세컨드 단위를 세컨드단위로 작업하기 편하게 변환하자

				// 델타타임은 현재시간에서 마지막 업데이트된 시간의 차이임 (작동 확인)
				// 컴퓨터가 성능이 보장되서 무조건 프레임간격사이에 모든연산을 다할수있다면
				// delta_Time == Frame_Time 이다.

				Swatch = abs(curr_Time - Frame_Time); // 짜투리 시간 저장 curr_Time 에 저장해야함  (작동확인)
				cout << "			Swatch : " << Swatch << endl << endl;
				// 하드웨어의 성능이 보장된다면 Swatch == epsilon

				MainUpdate(delta_Time);
				MainRender(delta_Time);

				Last_Stamp = clock();
			}
		}
	}
}
