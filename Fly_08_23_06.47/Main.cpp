#pragma once
#include "Game.h"

void CursorView(char show)//Ä¿¼­¼û±â±â
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

int main()
{
	srand(time(NULL));
	CursorView(F);

	Game App;
	App.Run();
}