#include "Stdafx.h"
#include "EnemyManager.h"

HRESULT EnemyManager::init(void) {
	IMAGEMANAGER->addFrameImage("Jellyfish", "Resources/Images/JellyFish.bmp", 0.0f, 0.0f, 1140, 47, 19, 1, true, RGB(255, 0, 255));
	setMinion();

	return S_OK;
}

void EnemyManager::release(void) {
	for (_viMinion = _vMinion.begin(); _viMinion != _vMinion.end(); ++_viMinion) {
		(*_viMinion)->release();
		SAFE_DELETE(*_viMinion);
	}
}

void EnemyManager::update(void) {
	_viMinion = _vMinion.begin();
	for (; _viMinion != _vMinion.end(); ++_viMinion) {
		(*_viMinion)->update();
	}
}

void EnemyManager::render(void) {
	_viMinion = _vMinion.begin();
	for (; _viMinion != _vMinion.end(); ++_viMinion) {
		(*_viMinion)->render();
	}
}

void EnemyManager::removeMinion(int arrNum) {
	SAFE_DELETE(_vMinion[arrNum]);
	_vMinion.erase(_vMinion.begin() + arrNum);
}

void EnemyManager::setMinion(void) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			Enemy* jellyFish;
			jellyFish = new Minion;
			jellyFish->init("Jellyfish", PointMake(250 + j * 100, 150 + i * 50));
			_vMinion.push_back(jellyFish);
		}
	}
	float tempAngle = 0.0f;
	for (int i = 0; i < 10; i++) {
		Enemy* jellyFish;
		jellyFish = new MinionM1(tempAngle);
		jellyFish->init("Jellyfish", PointMake(CENTER_X + 200 * cos(tempAngle * PI / 180), CENTER_Y - 150 + 200 * sin(tempAngle * PI / 180)));
		_vMinion.push_back(jellyFish);
		tempAngle += 36.0f;
	}
	for (int i = 0; i < 10; i++) {
		Enemy* jellyFish;
		jellyFish = new MinionM2();
		jellyFish->init("Jellyfish", PointMake(RND->getInt(WINSIZE_X), RND->getInt(WINSIZE_Y)));
		_vMinion.push_back(jellyFish);
	}
}
