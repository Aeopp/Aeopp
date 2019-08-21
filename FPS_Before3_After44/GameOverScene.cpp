#include "pch.h"
#include "GameOverScene.h"


GameOverScene::GameOverScene(class SceneManager* a_pParent) : Scene(a_pParent)
{
}

GameOverScene::~GameOverScene()
{
}

eScene GameOverScene::GetScene() const
{
	return eScene::GameOver;
}

void GameOverScene::Update(float a_fDeltaTime)
{
}

void GameOverScene::Render()
{
}