#pragma once

using std::cout;
using std::endl;

enum class eUpdateState
{
	Run,
	Final,
};

enum class eKey
{
	None = -1,

	A,
	Left,
	W,
	Up,
	S,
	Right,
	D,
	Down,
	SPACE,
	Fire,

	Max,
};

enum class eInputState : short
{
	None	= 0b00,
	Down	= 0b11,
	Press	= 0b01,
	Up		= 0b10,
};

enum class eScene
{
	Intro,
	Game,
	GameOver,

	// ���̶��� ��������� ���� ���ϰ� ������ define ����� ��
	Scene_First = Intro,
};

enum class eObjectType
{
	None = 0,
	Wall,
	Box,
	Door,
	Item,
	Bomb,

	Monster,
	Player,
};

enum eGame
{
	MaxStage = 3,
};

#define SAFE_DELETE(x)		{ if((x) != nullptr ) { delete (x); (x) = nullptr; } }
#define SAFE_DELETE_ARR(x)	{ if((x) != nullptr ) { delete[] (x); (x) = nullptr; } }

void SetCursor(const COORD& a_stPos);
void SetCursor(int a_nPosX, int a_nPosY);

using fpTask = void(*)();
