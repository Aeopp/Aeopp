#pragma once

class MapData
{
public:

	MapData() = default;
	static MapData* Get(int a_nStage);
	static void Init();

	// static void Release();
	// �� ������ �迭�� ��ȸ�ϸ� �����ϴ� ����

private:
	static MapData m_arrData[eGame::MaxStage];

	// ���� �Ҵ��� 2���� �迭 �� �����Ϳ� �����ϱ�����
	// char** pMap ���������ͷ� �����ν� �迭��
	// ��� �� ��� �������� �����Ҽ� ����

	// void Render() �ܼ��� ������Ʈ�� �� �迭�� �ѷ��ִ� �Լ�

	// void MakeMap(); Y��������ŭ ������ �迭�� �����
	// �� �����͵鸶�� 1���� �迭�� �����Ҵ� �����ν�
	// 2���� �迭�� ���� ����
	//

	int x;
	int y;
	std::string map;
};

