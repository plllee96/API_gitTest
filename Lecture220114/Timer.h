#pragma once
/*
GetTickCount();
GetTickCount64();

Timer
- 시간을 측정하는 함수 : 굉장히 많고, 기본적으로 WINSOW가 시작된 이후
  지난 시간을 ms 단위로 측정

- timer를 구현할 때 알아둬야 하는 개념 : 해상도, 클럭

- 해상도 : 다양한 시간 함수들은 시간 측정을 위한 Tick이 존재함.
	ㄴ 1분 기준 얼마나 많은 프레임으로 나눌 수 있는지를 뜻함.
- 1분동안 얼마나 많은 Tick으로 나눠서 시간의 정확도를 높이느냐에 따라 
  고해상도, 저해상도가 나뉨

- clock(진동수)
- 타이머에서 얘기하는 클럭 : CPU클럭
- 클럭 자체는 디지털 회로의 전기적 진동수, Hz로 표현
ㄴ 1Hz : 1초에 1번 신호를 줌(bit단위)

※ 고성능 타이머의 경우 성능 향상시키기 위해서 Timer 중첩이 필요하다.
ㄴ (약 900만분의 1초까지 측정 가능)
ㄴ 기본값으로 셋팅할 경우 100만분의 1초까지 측정 가능
*/
class Timer {
private:
	float _timeScale;				//경과시간
	float _timeElapsed;			//마지막 시간과 현재 시간의 경과값
	bool _isHardware;				//고성능 타이머 지원 여부

	__int64 _curTime;				//현재 시간
	__int64 _lastTime;				//이전 시간
	__int64 _periodFrequency;	//시간 주기

	unsigned long _frameRate;
	unsigned long _FPSFramecount;
	float _FPSTimeElapsed;
	float _worldTime;

public:
	HRESULT init(void);
	void tick(float lockFPS = 0.0f);
	
	unsigned long getFrameRate(char* str = nullptr) const;
	inline float getElapsedTime(void) const { return _timeElapsed; }
	inline float getWorldTime(void) const { return _worldTime; }

	Timer() {}
	~Timer() {}
};

