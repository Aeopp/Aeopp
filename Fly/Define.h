#pragma once
#include <iostream>
#include <array>
#include <functional>
#include <algorithm>
#include <vector>
#include <Windows.h>
#include <ctime>
#include <string>
#include <ctime>
using namespace std;

using Frame_t = float;

constexpr Frame_t TargetFrame = ((Frame_t)1 / 40) * CLOCKS_PER_SEC;
constexpr int EnmeySpawnDelayTime = 5;

void gotoxy(int x, int y)
{

	COORD Pos = { x - 1, y - 1 };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);

}
void CursorView(char show)//Ŀ�������
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void delayFrame(Frame_t delayFrame) // �и�������� ����Ұ� !!
{									// �����۵� Ȯ����
	delayFrame += clock();
	while (clock() < delayFrame) {}
}

enum class Key {None,Left, Right, Up, Down,Fire,Bomb,Item};

#define F false
#define T true

#define SAFE_DELETE (x) if((x)!=nullptr){delete (x);(x)=nullptr;}
#define SAFE_DELETE_ARR (x) if((x)!=nullptr){delete[] (x);(x)=nullptr;}

