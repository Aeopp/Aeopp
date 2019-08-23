#include "pch.h"
#include "IntroScene.h"

#include "SceneManager.h"

IntroScene::IntroScene(class SceneManager* a_pParent) : Scene(a_pParent)
{

}

IntroScene::~IntroScene() {}

eScene IntroScene::GetScene() const
{
	return eScene::Intro;
}

void IntroScene::Update(float a_fDeltaTime)
{
	if( IsKeyDown(eKey::A) == true )
	{
		m_refParent->ChangeScene(eScene::Game);
	}
}

void IntroScene::Render()
{
	SetCursor(0, 0);
	cout << "Intro Scene" << endl;
	cout << "Press Any Key" << endl;
}
