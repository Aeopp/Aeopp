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
	//void IntroScene::Update(float a_fDeltaTime)
	// 단순히 키 입력 받아서 ChangeScene 를 호출하는
	// 내부 구현의 추가
}

void IntroScene::Render()
{
	cout << "Intro Scene" << endl;
	cout << "Press Any Key" << endl;
}
