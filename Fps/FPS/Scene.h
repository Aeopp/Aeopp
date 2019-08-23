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

   // # Up Down 키 상태 키 체크  해주던 함수들이 삭제됨

public:

	class SceneManager * m_refParent = nullptr;
};

 // 키 체크해주던 함수 삭제로 인해 KeySate 매크로도 사용할 필요가 없어져 삭제
