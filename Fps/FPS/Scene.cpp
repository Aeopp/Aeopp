#include "pch.h"

#include "Scene.h"
#include <cassert>

Scene::Scene(SceneManager * a_pParent)
{
	assert(a_pParent != nullptr);
	m_refParent = a_pParent;
}

Scene::~Scene()
{
	m_refParent = nullptr;
}

void Scene::Init() { }
void Scene::Update(float a_fDeltaTime) { }
void Scene::Render() { }
