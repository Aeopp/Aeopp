#pragma once



class MapData
{
public:

	MapData() = default;
	static MapData* Get(int a_nStage);
	static void Init();
	static void Release();
	static eObjectType DataToObjectType(char c);

private:
	static MapData m_arrData[eGame::MaxStage];

private:

	void MakeMapBuffer();
	void ReleaseData();

public:
	void Render();

public:
	int x;
	int y;
	const char* mapOriginData;
	char** pMap = nullptr;
};

