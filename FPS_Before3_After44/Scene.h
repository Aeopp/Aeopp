#pragma once

#include "SceneManager.h"

class Scene
{
public:

	Scene(SceneManager * a_pParent);
	virtual ~Scene();

	virtual eScene GetScene() const = 0;

	virtual void Init();
	virtual void Update(float a_fDeltaTime);
	virtual void Render();

protected:

	inline bool IsKeyDown(eKey a_eKey) const
	{
		return m_refParent->GetKeyState(a_eKey) == eInputState::Down;
	}

	inline bool IsKeyUp(eKey a_eKey) const
	{
		return m_refParent->GetKeyState(a_eKey) == eInputState::Up;
	}

public:

	class SceneManager * m_refParent = nullptr;
};

#define KeyState(x) (m_refParent->GetKeyState(x))
