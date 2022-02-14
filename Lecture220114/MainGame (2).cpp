#include "Stdafx.h"
#include "MainGame.h"
/*
°úÁ¦1. SVN or Git
- ÆÀ¿ø Çù¾÷ TextOut ´ëÈ­ XÀÚ ¸ð¾ÓÀ¸·Î


*/

HRESULT MainGame::init(void) {
	GameNode::init(true);
	IMAGEMANAGER->addImage("BACKGROUND", "Resources/Images/ShootingBG.bmp", WINSIZE_X, WINSIZE_Y, false, RGB(255, 0, 255));
	_rocket = new Rocket;
	_rocket->init();

	_em = new EnemyManager;
	_em->init();

	_efm = new EffectManager;
	_efm->init();

	return S_OK;
}

void MainGame::release(void) {
	GameNode::release();
	if(_rocket) _rocket->release();
	SAFE_DELETE(_rocket);
	if (_em) _em->release();
	SAFE_DELETE(_em);
	if (_efm) _efm->release();
	SAFE_DELETE(_efm);
}

void MainGame::update(void) {
	GameNode::update();
	_rocket->update();
	_em->update();
	_efm->update();
	collision();
	attack();
}

void MainGame::render() {
	PatBlt(getMemDC(), 0, 0, WINSIZE_X, WINSIZE_Y, WHITENESS);
	IMAGEMANAGER->findImage("BACKGROUND")->render(getMemDC());
	IMAGEMANAGER->render("BACKGROUND", getMemDC());
	_rocket->render();
	_em->render();
	_efm->render();

	TIMEMANAGER->render(getMemDC());
	
	this->getBackBuffer()->render(getHDC());
}
