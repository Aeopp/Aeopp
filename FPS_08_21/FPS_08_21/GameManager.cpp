#include "pch.h"
#include "GameManager.h"

#include "MapData.h"
#include "Object.h"
#include "Player.h"
#include "ObjectFactory.h"

GameManager::GameManager() {}
GameManager::~GameManager()
{
	for( auto* pObj : m_vcObj)
	{
		SAFE_DELETE(pObj);
	}
	
	SAFE_DELETE(m_pPlayer);
}

void GameManager::Init()
{
	MapData::Init();
}

void GameManager::GameInit()
{
	m_nNowLife = 3;
	m_nScore = 0;
	m_nNowStage = 0;
}

void GameManager::StageStart()
{
	++m_nNowStage;
	m_fGameTime = RoundTime;

	MapData::Get(m_nNowStage);
	assert(m_refMap != nullptr);

	// �� �Լ��� ���α����� ���� �߰���

	// 1. ClearObject()
	// �ܼ��� ���� �ν��Ͻ̵� ������Ʈ �����͸� ����ִ�
	// ���͸� û�����ִ� ����

	// �ݺ����� ���鼭 Player�� ��ǥ�� ã�´ٸ�
	// ��ǥ �����ϰ�  SetMap �Լ��� ȣ��

	// ������Ʈ���丮�� Make�Լ��� ȣ���ؼ�
	// �� ������ ���� �ް� �����ϸ�
	// �� ��ü�� �̸� �������� ���Ϳ� ������.


}

void GameManager::Update(float a_fDeltaTime)
{
	for (auto obj : m_vcObj)
	{
		obj->Update(a_fDeltaTime);
	}
		
	m_pPlayer->Update(a_fDeltaTime);
}

void GameManager::Render()
{
	for (auto obj : m_vcObj)
	{
		obj->Render();
	}

	m_pPlayer->Render();
}

//void GameManager::RemoveObject(class Object* a_pObj)
// �ڷ��� �߷� Ÿ���� ���ͷ����ʹ� std::find_if�� Ȱ���Ͽ�
// �ƱԸ�Ʈ�� ���� ������Ʈ ��ü�� 
// ����  ���Ұ� �����ϴٸ� �ش� ���Ҹ� ������Ų....�ٰ� �м�..?
// assert(itor != m_vcObj.end()); <- �������� ���ܻ�Ȳ
// ���� ������
// ���ٸ� Ȱ���ؼ� ���� ���غ��̰� ������ų������ ���ͷ����͸�
// ���� ��� �Ѵٴ°� ���� �����غ���

//void GameManager::ObtainItem(eItem a_eItem)
// �ƱԸ�Ʈ ���� �������� switch ���� Ȱ���Ͽ���
// �÷��̾��� ������ ������Ű�� �ܼ��� �Լ��� �߰�

//void GameManager::GetBombData(Bomb* a_refBomb) const
// �ܼ��� ��ź�� ���ӽð��� ���� ���� ����
// �÷��̾ �������ִ� ���������� ���Խ�Ű�� ����Ÿ
// ��ź�� ���߹������� �÷��̾ ������ (���������� ������Ű��)
// (������ �ؾ��ϴ�) ���� ���ӽð��� �÷��̾��� �����ͷ�
// �Ź� �ʱ�ȭ �����ִ°� ���� �������߿� ���ӽð��� ª�����ְų�
// �÷��ִ� �������� ������ �������ΰ� ����
