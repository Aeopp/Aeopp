#pragma once
#include "Object.h"

class Player : public Object
{
public:
	Player(int x, int y);
	virtual ~Player();

	// Object을(를) 통해 상속됨
	virtual eObjectType GetObjectType() const override;

	virtual Rect GetRendertRect() const override;
	void SetStat(struct CharacterData* a_pStat);
	// 포인터를 아규먼트로 받아 스탯을 셋업하는 함수 선언 추가
private:
	void Move(float a_fDeltaTime);
	void BombCheck();
	
protected:
	virtual bool _Update(float a_fDelta);

	RenderTile	m_Data;
	struct CharacterData* m_refStat;

public:
	int m_nPutBombCount = 0;
	// 현재 설치 되어있는 폭탄개수 체크하는 멤버변수
};

