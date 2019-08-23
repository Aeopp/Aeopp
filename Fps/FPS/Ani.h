#pragma once

class Ani
{
public:
	Ani() = default;
	virtual ~Ani();

	void Resize(int a_nAniTypeCount);
	void Add(int a_nAniType, const RenderTile& tile);
	void Add(int a_nAniType, const std::initializer_list<RenderTile>& tiles);

	void SetState(int a_nAni, int a_nCut = 0);
	void NextCut();
	
	void Update(float a_fDeltaTime);
	RenderTile* Get();

	std::vector<std::vector<RenderTile>> m_vcAni;
	std::vector<RenderTile>* m_pCurrentAni = nullptr;

	int m_nAniType = 0;
	int m_nNowMaxCut = 0;
	int m_nCut = 0;
	float m_fNowTile = 0;
	
	inline static const float a_fCutTime = 0.2f;
};
