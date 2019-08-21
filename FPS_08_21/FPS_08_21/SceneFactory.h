#pragma once

class SceneFactory
{
public:
	static class Scene* Make(class SceneManager* a_pParent, eScene a_eScene);
};
