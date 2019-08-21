#pragma once
#include "Scene.h"

class IntroScene : public Scene
{
public:
	IntroScene(class SceneManager* a_pParent);
	virtual ~IntroScene();

	// Scene을(를) 통해 상속됨
	virtual eScene GetScene() const override;

	virtual void Update(float a_fDeltaTime) override;
	virtual void Render() override;
};
