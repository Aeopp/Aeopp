#pragma once

class MapData
{
public:

	MapData() = default;
	static MapData* Get(int a_nStage);
	static void Init();

	// static void Release();
	// 맵 데이터 배열을 순회하며 삭제하는 역할

private:
	static MapData m_arrData[eGame::MaxStage];

	// 동적 할당한 2차원 배열 맵 데이터에 접근하기위한
	// char** pMap 더블포인터로 함으로써 배열의
	// 행과 열 모두 동적으로 결정할수 있음

	// void Render() 단순히 업데이트된 맵 배열을 뿌려주는 함수

	// void MakeMap(); Y변수값만큼 포인터 배열을 만들고
	// 각 포인터들마다 1차원 배열을 동적할당 함으로써
	// 2차원 배열로 맵을 구현
	//

	int x;
	int y;
	std::string map;
};

