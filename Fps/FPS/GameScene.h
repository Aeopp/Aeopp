#pragma once
#include "Scene.h"

class GameScene : public Scene
{
public:
	GameScene(class SceneManager* a_pParent);
	virtual ~GameScene();

	// Scene��(��) ���� ��ӵ�
	virtual eScene GetScene() const override;

	virtual void Init() override;
	virtual void Update(float a_fDeltaTime) override;
	virtual void Render() override;
};
