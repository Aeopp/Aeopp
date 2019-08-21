#pragma once

struct CharacterData
{
	float	fMoveSeepd;
	float	fBombTime;
	int		nBasePower;
	int		nBombCount;

	//CharacterData();
	// 내부구현에서 함수호출 부분이 추가되었는데
	// 내용은 그냥 단순히 미리 정의해둔 enum class
	// 의 캐릭터 스피드와 폭탄 타이머, 폭탄 파워스탯으로
	// 변수값을 바꿔주는 역할 Init 의 역할
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
		// 게임이 실행중에 포인터가 가리키는 
		// 객체의 Release() 함수가 알맞게 호출된다.
		SAFE_DELETE(m_pInstance);
	}

#pragma endregion

	enum
	{
		MaxLife = 3,		// 플레이어 라이프 수
		RoundTime = 90,		// 90초

		MoveSpeed = 10,		// 이동 속도
		BombTime = 3,		// 3초
		BombBasePower = 2,	// 2칸
		BombBaseCount = 1,	// 최초 폭탄 설치 갯수
	};

	void Init();
	void GameInit();
	void StageStart();

	void Update(float a_fDeltaTime);
	void Render();

	// 오브젝트
	std::vector<class Object*> m_vcObj;
	class Player* m_pPlayer = nullptr;

	// 스테이지 정보
	int m_nNowStage = 0;
	float m_fGameTime = 0;	// 스테이지별 남은 시간
	MapData *m_refMap = nullptr;

	// 데이터
	int m_nNowLife = 0;		// 플레이어 라이프
	int m_nScore = 0;		// 점수

	// std::queue<class Bomb*> m_qBomb;
	// 폭탄 객체를 저장하는 자료구조로 queue 를 선택하였음을
	// 알수있음

};

#define InitGameMng()		{GameManager::CreateInstance(); }
#define GameMng()			(GameManager::GetInstance())
#define ReleaseGameMng()	(GameManager::ReleaseInstance())
