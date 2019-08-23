#pragma once

class Application
{
public:
	Application();
	~Application();

	void Run();
	constexpr static float GetTargetFPS();

protected:

	eUpdateState Update(float a_fDelta);
	void Render();

private:
	clock_t m_nDeltaTick;
	clock_t m_nLastStamp = 0;
};
