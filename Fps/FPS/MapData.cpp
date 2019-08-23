#include "pch.h"
#include "MapData.h"

MapData MapData::m_arrData[eGame::MaxStage] = { {}, };

MapData* MapData::Get(int a_nStage)
{
	return &m_arrData[a_nStage-1];
}

void MapData::Init()
{
	// 1스테이지
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
