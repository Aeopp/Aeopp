#pragma once
#include <iostream>
#include <array>
#include <functional>
#include <algorithm>
#include <vector>
#include <Windows.h>
#include <ctime>
#include <string>

using namespace std;

using Frame_t = float;

const size_t Frame = 30;

constexpr Frame_t TargetFrame = ((Frame_t)1 / Frame) * CLOCKS_PER_SEC;

constexpr int EnmeySpawnDelayTime = 30;

constexpr float DefaultEffectCount = 5.0f;

constexpr size_t NaN = 100;

//void delayFrame(Frame_t delayFrame) // 밀리세컨드로 사용할것 !!
//{									// 정상작동 확인함
//	delayFrame += clock();
//	while (clock() < delayFrame) {}
//}

enum class Key { None, Left, Right, UP, DOWN, Fire, Bomb, Item, Enemy_Fire };

enum class MapState { M_Left = 3, M_Right = 73, M_Top = 3, M_Bottom = 50 };

#define F false
#define T true

#define Up true
#define Down false

#define LEFT false
#define RIGHT true

#define Die false
#define Survive true

#define SAFE_DELETE (x) if((x)!=nullptr){delete (x);(x)=nullptr;}
#define SAFE_DELETE_ARR (x) if((x)!=nullptr){delete[] (x);(x)=nullptr;}

