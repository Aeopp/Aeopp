#include "Define.h"

bool IsKeyDown()  // 테스트완료
{                                             
	if ((GetAsyncKeyState(VK_LEFT) & 0x8000)) { cout << "press is LEFT"; }
	if ((GetAsyncKeyState(VK_RIGHT) & 0x8000)) { cout << "press is RIGHT"; }
	if ((GetAsyncKeyState(VK_UP) & 0x8000)) { cout << "press is UP"; }
	if ((GetAsyncKeyState(VK_DOWN) & 0x8000)) { cout << "press is DOWN"; }
	if ((GetAsyncKeyState(VK_SPACE) & 0x8000)) { cout << "press is space"; }
	return 0;
}
// 총알은 큐로구현할까???

// 충돌 인터페이스
// (총알(좌표필요),검사할캐릭터)

void Render()
{
	// 업데이트에서 좌표갱신은 약속된것이니
	// 여기서는 신경쓰지말고 좌표값만 받아서 그리기만 하기
	// Only Draw
}
int main()
{
	std::cout << "Test Frame Rate : " << TargetFrame << endl;

	clock_t Last_Stamp = 0;

	clock_t Swatch = 0;

	while (1)
	{
		clock_t curr_Time = clock(); // 현재시간

		clock_t Frame_Time = TargetFrame + Last_Stamp + Swatch; // 마지막 업데이트가 된 시간 + 프레임타임 + 짜투리시간

		if (curr_Time > Frame_Time) // 현재시간이 curr_Time 을 추월한상태임
		{
			clock_t delta_Time = curr_Time - Last_Stamp;  //  델타타임은 현재시간에서 마지막 업데이트된 시간의 차이임 (정상작동 확인)
			// 컴퓨터가 성능이 보장되서 무조건 프레임간격사이동안 모든연산을 다할수있다면
			// delta_Time == Frame_Time 임.

			Swatch = abs(curr_Time-Frame_Time); // 짜투리 시간 저장 curr_Time 에 저장해야함  (정상작동확인)
			// 짜투리 시간도 하드웨어의 성능이 보장되는 환경에서는 별로 의미는 없음

			Update(delta_Time);
			Render();

			Last_Stamp = clock();
		}
	}

}

