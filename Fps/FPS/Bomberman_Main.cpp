#include "pch.h"
#include <iostream>

#include "Application.h"

int main()
{
	Application* pApp = new Application();
	pApp->Run();
	SAFE_DELETE(pApp);

	return 0;
}
