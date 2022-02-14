#pragma once
/*
GetTickCount();
GetTickCount64();

Timer
- �ð��� �����ϴ� �Լ� : ������ ����, �⺻������ WINSOW�� ���۵� ����
  ���� �ð��� ms ������ ����

- timer�� ������ �� �˾Ƶ־� �ϴ� ���� : �ػ�, Ŭ��

- �ػ� : �پ��� �ð� �Լ����� �ð� ������ ���� Tick�� ������.
	�� 1�� ���� �󸶳� ���� ���������� ���� �� �ִ����� ����.
- 1�е��� �󸶳� ���� Tick���� ������ �ð��� ��Ȯ���� ���̴��Ŀ� ���� 
  ���ػ�, ���ػ󵵰� ����

- clock(������)
- Ÿ�̸ӿ��� ����ϴ� Ŭ�� : CPUŬ��
- Ŭ�� ��ü�� ������ ȸ���� ������ ������, Hz�� ǥ��
�� 1Hz : 1�ʿ� 1�� ��ȣ�� ��(bit����)

�� ���� Ÿ�̸��� ��� ���� ����Ű�� ���ؼ� Timer ��ø�� �ʿ��ϴ�.
�� (�� 900������ 1�ʱ��� ���� ����)
�� �⺻������ ������ ��� 100������ 1�ʱ��� ���� ����
*/
class Timer {
private:
	float _timeScale;				//����ð�
	float _timeElapsed;			//������ �ð��� ���� �ð��� �����
	bool _isHardware;				//���� Ÿ�̸� ���� ����

	__int64 _curTime;				//���� �ð�
	__int64 _lastTime;				//���� �ð�
	__int64 _periodFrequency;	//�ð� �ֱ�

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

