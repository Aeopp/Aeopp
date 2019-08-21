#include "pch.h"
#include <iostream>

#include "Application.h"
 // 이름만 바뀜
// FPS보단 붐버맨이 어울리니
int main()
{
	Application* pApp = new Application();
	pApp->Run();
	SAFE_DELETE(pApp);

	return 0;
}
