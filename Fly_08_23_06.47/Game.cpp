#pragma once
#include "Game.h"

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
	static int EnemySpawnDelay = 0;        // 스폰주기

	static int Enemy_vec_count = 0;         // 벡터 배열 인덱스

	if (Enemy_vec_count > 95) { Enemy_vec_count = 0; }

	if (EnemySpawnDelay++==EnmeySpawnDelayTime)       //  1 프레임당 1감소임
	{
		if (Enemy_vec[Enemy_vec_count]._exist == F)
		{

			Enemy_vec[Enemy_vec_count].EnemyInstance();       // Init 안하면 여기서 무조건 터짐

			Enemy_vec_count++;

			EnemySpawnDelay = 0;
		}
	}

	Hero.Move(IsKeyDown(),DeltaTime,Bullet_vec); // 히어로 움직이기

	for (auto& elem : Enemy_vec)
	{
		elem.Move(elem.EnemyRandomMove(),DeltaTime,Bullet_vec);
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

	for (const auto& elem : Bullet_vec)
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

		std::cout << "Test Frame Rate : " << TargetFrame << " M/S" << endl;

		Frame_t Last_Stamp = 0, Swatch = 0;

		while (1)
		{
			Frame_t curr_Time = clock(); // 현재시간

			Frame_t Frame_Time = TargetFrame + Last_Stamp + Swatch;
			// Last Update Time + Frame Time + 짜투리시간
			if (curr_Time > Frame_Time) // 현재시간이 curr_Time 을 추월한상태임
			{
				Frame_t delta_Time = (curr_Time - Last_Stamp) / static_cast<Frame_t>CLOCKS_PER_SEC;
				// 밀리세컨드 단위를 세컨드단위로 작업하기 편하게 변환하자

				// 델타타임은 현재시간에서 마지막 업데이트된 시간의 차이임 (정상작동 확인)
				// 컴퓨터가 성능이 보장되서 무조건 프레임간격사이에 모든연산을 다할수있다면
				// delta_Time == Frame_Time 이다.

				Swatch = abs(curr_Time - Frame_Time); // 짜투리 시간 저장 curr_Time 에 저장해야함  (정상작동확인)
				// 하드웨어의 성능이 보장된다면 Swatch == epsilon

				MainUpdate(delta_Time);
				MainRender(delta_Time);

				Last_Stamp = clock();
			}
		}
	}
}
