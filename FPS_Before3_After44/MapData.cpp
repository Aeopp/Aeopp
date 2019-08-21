#include "pch.h"
#include "MapData.h"

MapData MapData::m_arrData[eGame::MaxStage] = { {}, };

MapData* MapData::Get(int a_nStage)
{
	return &m_arrData[a_nStage-1];
}

void MapData::Init()
{
	// 숫자에 해당하는 문자에서 알파벳으로 바꾸었는데
	// 실수할 확률이 줄어들고 알파벳이든 숫자든
	// eObjectType MapData::DataToObjectType(char c)
	// 함수가 알아서 enum 타입 값으로 바꾸어서 반환해줌
	m_arrData[0].x = 10;
	m_arrData[0].y = 10;
	m_arrData[0].mapOriginData =
		"WWWWWWWWWW"
		"W      B W"
		"W B   B  W"
		"W  B     W"
		"W  B     W"
		"W  B     W"
		"W  B  M  W"
		"W  B     W"
		"W PIIIII W"
		"WWWWWWWWWW";
	m_arrData[0].MakeMapBuffer();

	// 2스테이지
	m_arrData[1].x = 10;
	m_arrData[1].y = 10;
	m_arrData[1].mapOriginData =
		"WWWWWWWWWW"
		"W  I   B W"
		"W B   B  W"
		"W  B     W"
		"W  B     W"
		"W  B     W"
		"W  B  M  W"
		"W  B     W"
		"W P      W"
		"WWWWWWWWWW";
	m_arrData[1].MakeMapBuffer();

	// 3스테이지
	m_arrData[2].x = 10;
	m_arrData[2].y = 10;
	m_arrData[2].mapOriginData =
		"WWWWWWWWWW"
		"W      B W"
		"W B   B  W"
		"W  B     W"
		"W  B  I  W"
		"W  B     W"
		"W  B  M  W"
		"W  B     W"
		"W P      W"
		"WWWWWWWWWW";
	m_arrData[2].MakeMapBuffer();

	cout << "map ok" << endl;
}
void MapData::Release()
{
	for (auto& mapData : m_arrData)
	{
		mapData.ReleaseData();
	}
}
// 인자값을 바탕으로 해당 값에 맞는 enum 타입 값으로
// 바꾸어서 반환하는 역할
eObjectType MapData::DataToObjectType(char c)
{
	eObjectType eReturn = eObjectType::None;

	switch (c)
	{
		case ' ': { return eObjectType::None; } break;
		case 'W': { eReturn = eObjectType::Wall; } break;
		case 'B': { eReturn = eObjectType::Box; } break;
		case 'D': { eReturn = eObjectType::Door; } break;
		
		case 'I': { eReturn = eObjectType::Item; } break;
		// case 'O': { eReturn = eObjectType::Bomb; } break;
		case 'M': { eReturn = eObjectType::Monster; } break;
		case 'P': { eReturn = eObjectType::Player; } break;
	}
	assert(eReturn != eObjectType::None);
	return eReturn;
}

void MapData::MakeMapBuffer()
{
	int nX = x * TileSize;
	int nY = y * TileSize;

	pMap = new char*[nY];

	for( int i=0; i<nY; ++i )
	{
		pMap[i] = new char[nX + 1];

		memset(pMap[i], ' ', sizeof(char)*(nX + 1));
		// 본래 new 로 동적할당 하던 방식이였음
		// 이번에는 memset 로 한꺼번에 공백으로 채워주는 모습

		pMap[i][nX] = 0;
	}
}

void MapData::ReleaseData()
{
	int nY = y * TileSize;

	for (int i = 0; i < nY; ++i)
	{
		SAFE_DELETE_ARR(pMap[i])
	}

	SAFE_DELETE_ARR(pMap);
}

void MapData::Render()
{
	SetCursor(0, 0);

	int nY = y * TileSize;

	for (int i = 0; i < nY; ++i)
	{
		cout << pMap[i] << endl;
	}
}
