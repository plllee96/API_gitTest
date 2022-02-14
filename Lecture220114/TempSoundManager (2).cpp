#include "Stdafx.h"
#include "TempSoundManager.h"

HRESULT TempSoundManager::init() {	
	return S_OK;
}

void TempSoundManager::addMp3FileWithKey(string key, string fileName) {
	string first = "open \"";
	string end = "\" type mpegvideo alias ";
	string finalQuery = first + fileName + end + key;
	const char* str = finalQuery.c_str();

	mciSendString(str, NULL, 0, NULL); //현재 장치에 명령어 전송 (명령어 문자열, 반환값, 반환된 길이, 핸들 콜백)
}

void TempSoundManager::addWaveFileWithKey(string key, string fileName) {
	string first = "open \"";
	string end = "\" type waveaudio alias ";
	string finalQuery = first + fileName + end + key;
	const char* str = finalQuery.c_str();

	mciSendString(str, NULL, 0, NULL);
}

void TempSoundManager::playEffectSoundWave(char* fileName) {
	//wave만 가능. 핸들을 NULL로, 파일명만 사용. sound 옵션 | 옵션 | 옵션
	//SND_ASYNC : 재생하면서 다음 코드 실행(비동기적 플래그)
	PlaySound(fileName, NULL, SND_ASYNC);			
}

void TempSoundManager::playSoundWithKey(string key) {
	string first = "play ";
	string finalQuery = first + key;
	const char* str = finalQuery.c_str();
	mciSendString(str, NULL, 0, NULL);
}

void TempSoundManager::stopMp3WithKey(string key) {
	string first = "stop ";
	string finalQuery = "";
	finalQuery = first + key;
	const char* str = finalQuery.c_str();
	mciSendString(str, NULL, 0, NULL);
}
