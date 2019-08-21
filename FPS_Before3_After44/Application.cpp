#include "pch.h"
#include "Application.h"
#include <ctime>
#include <cstdlib>

#include "SceneManager.h"
#include "GameManager.h"

constexpr float Application::GetTargetFPS()  
{
	constexpr float nTargetFPS = 60;
	return (1 / nTargetFPS) * 1000;
}

Application::Application()
{
	SetConsoleSize(1400, 1200);
	// 콘솔사이즈를 1400,1200 으로 설정

	SetCursorType(CURSOR_TYPE::NOCURSOR);
	// 커서를 숨겨주는 함수 사용

	srand(time(0));
	// 시드 설정하며 rand 함수를 사용할 준비
	InitSceneMng();
	InitGameMng();
}

Application::~Application()
{
	ReleaseGameMng();
	ReleaseSceneMng();
}

void Application::Run()
{
	while (true)
	{
		clock_t now = clock();   
		clock_t term = now - m_nLastStamp;

		if (term > GetTargetFPS())
		{
			m_nDeltaTick = term;
			m_nLastStamp = now;

			float fDeltaTime = m_nDeltaTick / (float)1000;

			if (Update(fDeltaTime) == eUpdateState::Final) { break; }

			Render();
		}
	}
}

eUpdateState Application::Update(float a_fDelta)
{
	if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
	{
		return eUpdateState::Final;
	}

	SceneMng()->Update(a_fDelta);

	return eUpdateState::Run;
}

void Application::Render()
{
	SceneMng()->Render();
}
