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

constexpr Frame_t TargetFrame = ((Frame_t)1 / 30) * CLOCKS_PER_SEC;

constexpr int EnmeySpawnDelayTime = 120;


//void delayFrame(Frame_t delayFrame) // �и�������� ����Ұ� !!
//{									// �����۵� Ȯ����
//	delayFrame += clock();
//	while (clock() < delayFrame) {}
//}

enum class Key { None, Left, Right, UP, DOWN, Fire, Bomb, Item,Enemy_Fire };

enum class MapState { M_Left=3, M_Right=73,M_Top=3,M_Bottom=50};

#define F false
#define T true

#define Up true
#define Down false

#define SAFE_DELETE (x) if((x)!=nullptr){delete (x);(x)=nullptr;}
#define SAFE_DELETE_ARR (x) if((x)!=nullptr){delete[] (x);(x)=nullptr;}

