#include "pch.h"
#include "SceneFactory.h"

#include "IntroScene.h"
#include "GameScene.h"
#include "GameOverScene.h"

Scene* SceneFactory::Make(class SceneManager* a_pParent, eScene a_eScene)
{
	Scene* pMakedScene = nullptr;
	switch (a_eScene)
	{
	case eScene::Intro:
		pMakedScene = new IntroScene(a_pParent);
		break;
	case eScene::Game:
		pMakedScene = new GameScene(a_pParent);
		break;
	case eScene::GameOver:
		pMakedScene = new GameOverScene(a_pParent);
		break;
	default:
		assert(false && "arg error");
		break;
	}

	return pMakedScene;
}


