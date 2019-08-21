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
	// �ܼ��� Ű �Է� �޾Ƽ� ChangeScene �� ȣ���ϴ�
	// ���� ������ �߰�
}

void IntroScene::Render()
{
	cout << "Intro Scene" << endl;
	cout << "Press Any Key" << endl;
}
