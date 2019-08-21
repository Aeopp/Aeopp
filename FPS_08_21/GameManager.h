#pragma once

struct CharacterData
{
	float	fMoveSeepd;
	float	fBombTime;
	int		nBasePower;
	int		nBombCount;

	//CharacterData();
	// ���α������� �Լ�ȣ�� �κ��� �߰��Ǿ��µ�
	// ������ �׳� �ܼ��� �̸� �����ص� enum class
	// �� ĳ���� ���ǵ�� ��ź Ÿ�̸�, ��ź �Ŀ���������
	// �������� �ٲ��ִ� ���� Init �� ����
};

class GameManager
{
#pragma region SINGLE_TON
private:
	static inline GameManager* m_pInstance = nullptr;
	GameManager();
	~GameManager();

	GameManager operator=(GameManager&) = delete;
	GameManager(GameManager&&) = delete;
	GameManager(const GameManager&) = delete;

public:

	static void CreateInstance()
	{
		if (m_pInstance == nullptr)
		{
			m_pInstance = new GameManager();
			m_pInstance->Init();
		}
	}

	static GameManager * GetInstance()
	{
		return m_pInstance;
	}

	static void ReleaseInstance()
	{
		// m_pInstance->Release();
		// ������ �����߿� �����Ͱ� ����Ű�� 
		// ��ü�� Release() �Լ��� �˸°� ȣ��ȴ�.
		SAFE_DELETE(m_pInstance);
	}

#pragma endregion

	enum
	{
		MaxLife = 3,		// �÷��̾� ������ ��
		RoundTime = 90,		// 90��

		MoveSpeed = 10,		// �̵� �ӵ�
		BombTime = 3,		// 3��
		BombBasePower = 2,	// 2ĭ
		BombBaseCount = 1,	// ���� ��ź ��ġ ����
	};

	void Init();
	void GameInit();
	void StageStart();

	void Update(float a_fDeltaTime);
	void Render();

	// ������Ʈ
	std::vector<class Object*> m_vcObj;
	class Player* m_pPlayer = nullptr;

	// �������� ����
	int m_nNowStage = 0;
	float m_fGameTime = 0;	// ���������� ���� �ð�
	MapData *m_refMap = nullptr;

	// ������
	int m_nNowLife = 0;		// �÷��̾� ������
	int m_nScore = 0;		// ����

	// std::queue<class Bomb*> m_qBomb;
	// ��ź ��ü�� �����ϴ� �ڷᱸ���� queue �� �����Ͽ�����
	// �˼�����

};

#define InitGameMng()		{GameManager::CreateInstance(); }
#define GameMng()			(GameManager::GetInstance())
#define ReleaseGameMng()	(GameManager::ReleaseInstance())
