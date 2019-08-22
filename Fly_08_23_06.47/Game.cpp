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
	static int EnemySpawnDelay = 0;        // �����ֱ�

	static int Enemy_vec_count = 0;         // ���� �迭 �ε���

	if (Enemy_vec_count > 95) { Enemy_vec_count = 0; }

	if (EnemySpawnDelay++==EnmeySpawnDelayTime)       //  1 �����Ӵ� 1������
	{
		if (Enemy_vec[Enemy_vec_count]._exist == F)
		{

			Enemy_vec[Enemy_vec_count].EnemyInstance();       // Init ���ϸ� ���⼭ ������ ����

			Enemy_vec_count++;

			EnemySpawnDelay = 0;
		}
	}

	Hero.Move(IsKeyDown(),DeltaTime,Bullet_vec); // ����� �����̱�

	for (auto& elem : Enemy_vec)
	{
		elem.Move(elem.EnemyRandomMove(),DeltaTime,Bullet_vec);
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

	for (const auto& elem : Bullet_vec)
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

		std::cout << "Test Frame Rate : " << TargetFrame << " M/S" << endl;

		Frame_t Last_Stamp = 0, Swatch = 0;

		while (1)
		{
			Frame_t curr_Time = clock(); // ����ð�

			Frame_t Frame_Time = TargetFrame + Last_Stamp + Swatch;
			// Last Update Time + Frame Time + ¥�����ð�
			if (curr_Time > Frame_Time) // ����ð��� curr_Time �� �߿��ѻ�����
			{
				Frame_t delta_Time = (curr_Time - Last_Stamp) / static_cast<Frame_t>CLOCKS_PER_SEC;
				// �и������� ������ ����������� �۾��ϱ� ���ϰ� ��ȯ����

				// ��ŸŸ���� ����ð����� ������ ������Ʈ�� �ð��� ������ (�����۵� Ȯ��)
				// ��ǻ�Ͱ� ������ ����Ǽ� ������ �����Ӱ��ݻ��̿� ��翬���� ���Ҽ��ִٸ�
				// delta_Time == Frame_Time �̴�.

				Swatch = abs(curr_Time - Frame_Time); // ¥���� �ð� ���� curr_Time �� �����ؾ���  (�����۵�Ȯ��)
				// �ϵ������ ������ ����ȴٸ� Swatch == epsilon

				MainUpdate(delta_Time);
				MainRender(delta_Time);

				Last_Stamp = clock();
			}
		}
	}
}
