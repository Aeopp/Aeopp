#pragma once

class Ani
{
public:
	Ani();
	virtual ~Ani();

	void Resize(int a_nAniTypeCount);
	void Add(int a_nAniType, RenderTile* tile);
	void SetState(int a_nAni, int a_nFrame = 0);
	RenderTile* Get();

	std::vector<std::vector<RenderTile*>> m_vcAni;
	std::vector<RenderTile*>* m_pCurrentAni = nullptr;

	int m_nAniType = 0;
	int m_nNowMaxCut = 0;
	int m_nCut = 0;
};

