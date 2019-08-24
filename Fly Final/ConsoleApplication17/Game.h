#pragma once
#include "Define.h"
#include "Jet.h"
#include "Bullet.h"
#include "Map.h"

class Game      // ������ ����ϱ� 
				// ���� �÷��̾� hp�� �̼� , �������� ����
				// + �Ѿ˻��°���
				// ���� �Ѿ��� �����Ҷ� ���ϰ��ϱ�
				// ���� �Ѿ� ������� �߰�
				// ���� ������ �����ϱ�
{
public:

	const size_t Default_Hp = 150; 

	Game()
	{
		Init();
	}
	
	int player_Hp = Default_Hp;

	Map _Map;

	Key IsKeyDown();
	void MainUpdate(Frame_t DeltaTime);
	void MainRender(Frame_t DeltaTime);

	void Run();
	void Init(); // ���� �����غ�

	vector<Bullet> Bullet_vec;
	vector<Jet> Enemy_vec;
	Jet Hero;
};

