#pragma once
#include "Define.h"
#include "Jet.h"
#include "Bullet.h"
#include "Map.h"

class Game         // 점수판 출력하기 
					// 또한 플레이어 hp와 이속 , 점수등을 관리
				// + 총알상태관리
				// 적군 총알을 생성할때 정하게하기
				// 적군 총알 유도기능 추가
			// 적군 움직임 수정하기
{
public:
	Game()
	{
		Init();
	}

	Map _Map;

	Key IsKeyDown();
	void MainUpdate(Frame_t DeltaTime);
	void MainRender(Frame_t DeltaTime);

	void Run();
	void Init(); // 게임 시작준비

	vector<Bullet> Bullet_vec;
	vector<Jet> Enemy_vec;
	Jet Hero;
};

