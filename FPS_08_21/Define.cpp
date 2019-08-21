#include "pch.h"
#include "Define.h"

void SetCursor(const COORD& a_stPos)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), a_stPos);
}

void SetCursor(int a_nPosX, int a_nPosY)
{
	SetCursor(COORD{ (short)a_nPosX,(short)a_nPosY });
}

