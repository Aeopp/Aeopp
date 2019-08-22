#include "Define.h"

Key IsKeyDown()  // 테스트완료
{                                             
	if ((GetAsyncKeyState(VK_LEFT) & 0x8000)) {  return Key::Left; }
	if ((GetAsyncKeyState(VK_RIGHT) & 0x8000)) {  return Key::Right; }
	if ((GetAsyncKeyState(VK_UP) & 0x8000)) { return Key::Up;}
	if ((GetAsyncKeyState(VK_DOWN) & 0x8000)) { return Key::Down;}
	if ((GetAsyncKeyState(VK_SPACE) & 0x8000)) { return Key::Fire; }
	if ((GetAsyncKeyState(VK_LSHIFT) & 0x8000)) {  return Key::Bomb; }
	if ((GetAsyncKeyState(VK_TAB) & 0x8000)) { return Key::Item; }

	return Key::None; // 키를 누르지 않았다면 None 반환 if문에서 필터가 안됐으므로
}

// 충돌 인터페이스
// (총알(좌표필요),검사할캐릭터)

class Bullet
{
public:
	float _x, _y,_disTance=30.0f,_speed = 5.0f;string _Char = "│"; 

	bool _UpDown = F, _exist = F; //  좌표 스피드 모양 UpDown F이면 아래로 T이면 위로 발사되는 총알
								// 스피드와 최대거리는 알아서 조절하기.

	Bullet(float x, float y, bool UpDown)
	{
		Init(x, y, UpDown);
	}

	void Init(float x, float y, bool UpDown)
	{
		_UpDown = UpDown;

		_x = x; _UpDown ? _y = y - 1 : _y = y + 1;

	}
	void Render(Frame_t deltaTime)const
	{
		if (_exist==false) { return; }

		gotoxy(_x,_y); cout << _Char;
	}
	void Update(Frame_t deltaTime)
	{
		if (_exist==false) { return; }

		gotoxy(_x,_y); cout << ' ';

		--_disTance < 0 ? _exist = 0 : _exist;

		float vector2 = _speed * deltaTime;

		_UpDown ? _y-- : _y++;
	}
};

vector<Bullet> TestBullet(100, Bullet(0.0f,0.0f, T));

class Jet
{
public:
	float _x, _y, _left, _right;
	bool _exist = F;
	float _speed; // 스피드는 1프레임당 이동속도임

	std::string _Char = "oOAOo";        // 만약 물체를 그려야 한다면 _Left 값으로 그리는것을 고려해보자.

	string _CharArr[4] = { "vVWVv","qpHqp","yoYoy","ozZzo" };

	Jet(){};

	Jet EnemyInstance()
	{
		_y = 3; _x = rand() % 100; _Char = _CharArr[rand() % 4]; // y좌표는 일단 고정
		// X좌표는 랜덤     캐릭 모양도 랜덤
		_speed = rand() % 30; _exist = T;  // 스피도 랜덤 인스턴싱시 살려주기

		return *this;
	}
	void Init(float x, float y, float speed, string Char)
	{
		_x = x, _y = (y), _speed = (speed), _Char = (Char);
		_left = x - 2, _right = x + 2;
	};

	Jet(float x, float y, float speed, string Char)
	{
		Init(x, y, speed, Char);
	}

	void Render(bool reMove_Draw)const // 캐릭터를 렌더한다면 T , 캐릭터를 지우고 싶다면 F
	{
		if(reMove_Draw)
		gotoxy(_left,_y), cout << _Char;
		else
			gotoxy(_left, _y), cout << "     ";
	}
	/*void posSet(Key E_Key)
	{
		if(E_Key==Key::Left){}
	}*/
	static Key EnemyRandomMove()
	{
		Key E_Key;
		int temp = rand() % 4;
		if (temp == 0) { E_Key = Key::Left; }
		if (temp == 1) { E_Key = Key::Right; }
		if (temp == 2) { E_Key = Key::Up; }
		if (temp == 3) { E_Key = Key::Down; }
		return E_Key;
	}
	void Move(Key E_Key,Frame_t DeltaTime)
	{
		static int Bulletcount = 0;
		if (Bulletcount > 95) { Bulletcount = 0; }
		if (E_Key == Key::None)return; // 아무것도 누르지 않았다면 아무것도 하지않는다.
		// 이동속도 곱해서 처리해야함
		// 이동속도* 델타타임;

		float vector2 = _speed* DeltaTime;

		switch (E_Key)
		{// 건드려야할것 x,y랑 레프트 라이트
		case (Key::Left):
			Render(F);
			_x-= vector2,_left -= vector2, _right -= vector2;
		break;
		case (Key::Right):
			Render(F);
			_x += vector2, _left += vector2, _right += vector2;
			break;
		case (Key::Up):Render(F);
			_y -= vector2/2.5;          // 똑같이 연산을 때려도 Y좌표는 증감치가 너무 커서 나눠주는 조치를함
			break;
		case (Key::Down):Render(F);
			_y += vector2/2.5;
			break;
		case (Key::Fire):
			TestBullet[Bulletcount].Init(_x,_y,T);
			TestBullet[Bulletcount]._exist = T;
			TestBullet[Bulletcount]._disTance = 30.0f;
			Bulletcount++;
			break;
		case (Key::Bomb):
			// 폭탄
			break;
		case (Key::Item):
			// 아이템
			break;
		}
	}
}; 

Jet TestJet(30.0f,30.0f,30.0f,"oOAOo");
vector<Jet> Enemy;

void MainUpdate(Frame_t DeltaTime)
{   
	static int EnemySpawnDelay = 0;

	if (++EnemySpawnDelay % EnmeySpawnDelayTime == 0)
	{
		Enemy.push_back(Jet().EnemyInstance());  // 에너미 벡터에 하나 만들어서 넣어주고 인스턴싱하기
	}

	TestJet.Move(IsKeyDown(),DeltaTime);

	for (auto& elem : TestBullet)
	{
		elem.Update(DeltaTime);
	}

	for (auto& elem : Enemy)
	{
		if (elem._exist)
		elem.Move(elem.EnemyRandomMove(), DeltaTime);
	}

	// 이동처리시 자신좌표 지워주고 좌표값만 최신갱신해서 렌더에서
	// 캐릭터그리게하기
}
void MainRender(Frame_t DeltaTime)
{
	TestJet.Render(T);
	for (const auto& elem : TestBullet)
	{
		elem.Render(DeltaTime);
	}
	for (const auto& elem : Enemy)
	{
		if(elem._exist)
		elem.Render(DeltaTime);
	}
	// 업데이트에서 좌표갱신은 약속된것이니
	// 여기서는 신경쓰지말고 좌표값만 받아서 그리기만 하기
}
int main()
{
	srand(time(NULL));
	CursorView(F);

	std::cout << "Test Frame Rate : " << TargetFrame <<" M/S"<< endl;

	Frame_t Last_Stamp = 0;

	Frame_t Swatch = 0;
	
	while (1)
	{
		Frame_t curr_Time = clock(); // 현재시간

		Frame_t Frame_Time = TargetFrame + Last_Stamp + Swatch;
		// 마지막 업데이트가 된 시간 + 프레임타임 + 짜투리시간
		if (curr_Time > Frame_Time) // 현재시간이 curr_Time 을 추월한상태임
		{
			Frame_t delta_Time = (curr_Time - Last_Stamp)/static_cast<Frame_t>CLOCKS_PER_SEC;

			//  델타타임은 현재시간에서 마지막 업데이트된 시간의 차이임 (정상작동 확인)
			// 컴퓨터가 성능이 보장되서 무조건 프레임간격사이동안 모든연산을 다할수있다면
			// delta_Time == Frame_Time 이다.
			// 밀리세컨드 단위를 세컨드단위로 작업하기 편하게 변환하자

			Swatch = abs(curr_Time-Frame_Time); // 짜투리 시간 저장 curr_Time 에 저장해야함  (정상작동확인)
			// 짜투리 시간은 하드웨어의 성능이 보장되는 환경일수록 0에 매우 가깝게 수렴.

			MainUpdate(delta_Time);
			MainRender(delta_Time);

			Last_Stamp = clock();
		}
	}

}




