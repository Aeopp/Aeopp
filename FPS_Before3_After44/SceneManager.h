#pragma once

class SceneManager
{
private:
	static inline SceneManager * m_pInstance = nullptr;
	SceneManager();
	~SceneManager();
	
	SceneManager operator=(SceneManager&) = delete;	
	SceneManager(SceneManager&&) = delete;
	SceneManager(const SceneManager&) = delete;
	
public:

	static void CreateInstance()
	{
		if (m_pInstance == nullptr)
		{
			m_pInstance = new SceneManager();
		}
	}

	static SceneManager * GetInstance()
	{
		return m_pInstance;
	}

	static void ReleaseInstance()
	{
		SAFE_DELETE(m_pInstance);
	}

public:
	
	void Init();
	void ChangeScene(eScene a_eScene);

	void Update(float a_fDeltaTime);
	void Render();

	eInputState GetKeyState(eKey a_eKey);

private:

	void KeyCheck();

private:
	class Scene *	m_pNowScene = nullptr;

	int				m_arrKeys[(int)eKey::Max];
	int				m_BeforeKeyState[(int)eKey::Max];
	eInputState		m_KeyState[(int)eKey::Max];
};

#define InitSceneMng()		{SceneManager::CreateInstance(); SceneManager::GetInstance()->Init();}
#define SceneMng()			(SceneManager::GetInstance())
#define ReleaseSceneMng()	(SceneManager::ReleaseInstance())
