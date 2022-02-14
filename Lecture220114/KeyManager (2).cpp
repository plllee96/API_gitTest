#include "Stdafx.h"
#include "KeyManager.h"

HRESULT KeyManager::init(void) {
	for (int i = 0; i < KEY_MAX; i++) {
		this->setKeyDown(i, false);
		this->setKeyUp(i, false);
	}
	return S_OK;
}

	/*
	GetAsyncKeyState : API 공용함수
	- 어떤 키가 입력된건지 체크, 프로그램에서 키를 입력받고 싶을 때 사용.
	- 메세지 큐에 있는 키의 정보를 확인한다.

	0x0000 : 이전에 누른적이 없음. 호출 시점에서 눌려있지 않음
	0x0001 : 이전에 누른적이 있음. 호출 시점에서 눌려있지 않음
	0x8000 : 이전에 누른적이 없음. 호출 시점에서 눌림
	0x8001 : 이전에 누른적이 있음. 호출 시점에서 눌림
	*/
bool KeyManager::isOnceKeyDown(int key) {
	if (GetAsyncKeyState(key) & 0x8000) {
		if (!this->getKeyDown()[key]) {
			this->setKeyDown(key, true);
			return true;
		}
	}
	else this->setKeyDown(key, false);
	return false;
}

bool KeyManager::isOnceKeyUp(int key) {
	if (GetAsyncKeyState(key) & 0x8000) {
		this->setKeyUp(key, true);
	}
	else {
		if (this->getKeyUp()[key]) {
			this->setKeyUp(key, false);
			return true;
		}
	}
	return false;
}

bool KeyManager::isStayKeyDown(int key) {
	if (GetAsyncKeyState(key) & 0x8000) return true;
	return false;
}

bool KeyManager::isTogglekey(int key) {
	if (GetKeyState(key) & 0x0001) return true;
	return false;
}
