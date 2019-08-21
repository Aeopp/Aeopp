#include "pch.h"
#include "Ani.h"

Ani::Ani()
{
}

Ani::~Ani()
{
}

void Ani::Resize(int a_nAniTypeCount)
{
	m_vcAni.resize(a_nAniTypeCount);
}

void Ani::Add(int a_nAni, RenderTile* tile)
{
	m_vcAni[a_nAni].push_back(tile);
}

void Ani::SetState(int a_nAni, int a_nFrame /*= 0*/)
{
	m_pCurrentAni = &m_vcAni[a_nAni];

	m_nAniType = a_nAni;
	m_nCut = a_nFrame;
	m_nNowMaxCut = (int)m_pCurrentAni->size();
}

RenderTile* Ani::Get()
{
	RenderTile* r = (*m_pCurrentAni)[m_nCut++];
	m_nCut %= m_nNowMaxCut;
	return r;
}
