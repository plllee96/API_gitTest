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

	mciSendString(str, NULL, 0, NULL); //���� ��ġ�� ��ɾ� ���� (��ɾ� ���ڿ�, ��ȯ��, ��ȯ�� ����, �ڵ� �ݹ�)
}

void TempSoundManager::addWaveFileWithKey(string key, string fileName) {
	string first = "open \"";
	string end = "\" type waveaudio alias ";
	string finalQuery = first + fileName + end + key;
	const char* str = finalQuery.c_str();

	mciSendString(str, NULL, 0, NULL);
}

void TempSoundManager::playEffectSoundWave(char* fileName) {
	//wave�� ����. �ڵ��� NULL��, ���ϸ� ���. sound �ɼ� | �ɼ� | �ɼ�
	//SND_ASYNC : ����ϸ鼭 ���� �ڵ� ����(�񵿱��� �÷���)
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
