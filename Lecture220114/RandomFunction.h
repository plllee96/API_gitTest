#pragma once
#include "SingletonBase.h"

//싱글톤 기법으로으로 사용할 클래스는  부모 클래스가 SingletonBase가 되도록 선언해주면 된다.
class RandomFunction : public SingletonBase <RandomFunction> {
public:
	RandomFunction() {
		srand(GetTickCount());
	}
	~RandomFunction() {}

	HRESULT init() { return S_OK; }

	inline int getInt(int num) {
		return rand() % num;
	}

	inline int getFromIntTo(int fromNum, int toNum) {
		return rand() % (toNum - fromNum + 1) + fromNum;
	}

	float getFloat(void) {
		return rand() / (float)RAND_MAX;
	}

	float getFloat(float num) {
		return (float)rand() / (float)RAND_MAX * num;
	}

	float getFromFloatTo(float fromNum, float toNum) {
		float rnd = (float)rand() / (float)RAND_MAX;
		return (rnd * (toNum - fromNum) + fromNum);
	}
};
