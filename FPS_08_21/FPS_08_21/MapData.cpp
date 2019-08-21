#include "pch.h"
#include "MapData.h"

MapData* MapData::Get(int a_nStage)
{
	return &m_arrData[a_nStage];
}

void MapData::Init()
{
	// 1스테이지
	m_arrData[0].x = 10;
	m_arrData[0].y = 10;
	m_arrData[0].map =
		"1111111111"
		"1000000601"
		"1020007001"
		"1000000001"
		"1000300001"
		"1000000001"
		"1000004001"
		"1000000001"
		"1050000001"
		"1111111111";

	// 2스테이지
	m_arrData[1].x = 10;
	m_arrData[1].y = 10;
	m_arrData[1].map =
		"1111111111"
		"1000000601"
		"1020007001"
		"1000000001"
		"1000300001"
		"1000000001"
		"1000004001"
		"1000000001"
		"1050000001"
		"1111111111";

	// 3스테이지
	m_arrData[2].x = 10;
	m_arrData[2].y = 10;
	m_arrData[2].map =
		"1111111111"
		"1000000601"
		"1020007001"
		"1000000001"
		"1000300001"
		"1000000001"
		"1000004001"
		"1000000001"
		"1050000001"
		"1111111111";
}
