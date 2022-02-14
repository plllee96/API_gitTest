#include "Stdafx.h"
#include "Timer.h"

HRESULT Timer::init(void) {
	//QueryPerformanceFrequency : 1초당 진동수 체크/ 고성능 타이머 지원여부 반환
	//_periodFrequency에 시간 삽입. ms계산 가능시 1000이 들어감.
	if (QueryPerformanceFrequency((LARGE_INTEGER*)&_periodFrequency)) {
		_isHardware = true;
		QueryPerformanceCounter((LARGE_INTEGER*)&_lastTime); //진동수 체크
		_timeScale = 1.0f / _periodFrequency;
	}
	else {
		_isHardware = false;
		_lastTime = timeGetTime();
		_timeScale = 0.001f;
	}
	_frameRate = 0;
	_FPSFramecount = 0;
	_FPSTimeElapsed = 0.0f;
	_worldTime = 0.0f;

	return S_OK;
}

void Timer::tick(float lockFPS) {
	if (_isHardware) {
		QueryPerformanceCounter((LARGE_INTEGER*)&_curTime);
	}
	else {
		_curTime = timeGetTime();
	}
	//마지막 시간과 현재 시간의 경과량 측정
	_timeElapsed = (_curTime - _lastTime) * _timeScale;
	if (lockFPS > 0.0f) {
		while (_timeElapsed < (1.0f / lockFPS)) {
			if (_isHardware) {
				QueryPerformanceCounter((LARGE_INTEGER*)&_curTime);
			}
			else {
				_curTime = timeGetTime();
			}
			_timeElapsed = (_curTime - _lastTime) * _timeScale;
		}
	}
	_lastTime = _curTime;
	_FPSFramecount++;
	_FPSTimeElapsed += _timeElapsed;
	_worldTime += _timeElapsed;

	if (_FPSTimeElapsed > 1.0f) {
		_frameRate = _FPSFramecount;
		_FPSFramecount = 0;
		_FPSTimeElapsed = 0.0f;
	}
}

unsigned long Timer::getFrameRate(char * str) const {
	if (str != nullptr) {
		wsprintf(str, "FPS : %d", _frameRate);
	}
	return _frameRate;
}
