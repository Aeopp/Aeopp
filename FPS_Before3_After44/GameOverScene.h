#pragma once
#include "Scene.h"

class GameOverScene : public Scene
{
public:
	GameOverScene(class SceneManager* a_pParent);
	virtual ~GameOverScene();

	// Scene을(를) 통해 상속됨
	virtual eScene GetScene() const override;

	virtual void Update(float a_fDeltaTime) override;
	virtual void Render() override;
};
