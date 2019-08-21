#pragma once

struct CharacterData
{
	float	fMoveSeepd;
	float	fBombTime;
	int		nBombPower;
	int		nBombCount;

	CharacterData();
};

class GameManager
{
#pragma region SINGLE_TON
private:
	static inline GameManager * m_pInstance = nullptr;
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
		m_pInstance->Release();
		SAFE_DELETE(m_pInstance);
	}

#pragma endregion

public:
	enum
	{
		MaxLife = 3,		// 플레이어 라이프 수
		RoundTime = 90,		// 90초

		MoveSpeed = 10,		// 이동 속도
		BombTime = 2,		// 2초
		BombBasePower = 2,	// 2칸
		BombBaseCount = 1,	// 최초 폭탄 설치 갯수
	};

	void Init();
	void Release();

	void GameInit();
	void StageStart();

	void Update(float a_fDeltaTime);
	void Render();

	void ClearObject();

	// 상호작용
	void RemoveObject(class Object* a_pObj);
	void DropItem(class Object* a_pObj);
	void GetBombData(class Bomb* a_refBomb) const;
	void ObtainItem(eItem a_eItem);

private:

	// 오브젝트
	std::vector<class Object*> m_vcObj[(int)eObjectType::LevelMax];
	// 기존 오브젝트 벡터가 레벨(3) 값이 추가됨

	class Player* m_pPlayer = nullptr;

	// 스테이지 정보
	int m_nNowStage = 0;
	float m_fGameTime = 0;	// 스테이지별 남은 시간
	class MapData* m_refMap = nullptr;
	char** m_pMap = nullptr;

	// 데이터
	int m_nNowLife = 0;		// 플레이어 라이프
	int m_nScore = 0;		// 점수

	// 폭발
	std::queue<class Bomb*> m_qBomb;

	// 현재 플레이어 데이터
	CharacterData m_stPlayerData;
};



#define InitGameMng()		{GameManager::CreateInstance(); }
#define GameMng()			(GameManager::GetInstance())
#define ReleaseGameMng()	(GameManager::ReleaseInstance())
