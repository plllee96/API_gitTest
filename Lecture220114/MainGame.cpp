#include "Stdafx.h"
#include "MainGame.h"

HRESULT MainGame::init(void) {
	GameNode::init(true);

	return S_OK;
}

void MainGame::release(void) {
	GameNode::release();
	
}

void MainGame::update(void) {
	GameNode::update();

}

void MainGame::render() {
	PatBlt(getMemDC(), 0, 0, WINSIZE_X, WINSIZE_Y, WHITENESS);

	SetTextColor(getMemDC(), RGB(0, 0, 0));
	
	TextOut(getMemDC(), 50, 50, "LHW_GitTest", strlen("LHW_GitTest"));

	TIMEMANAGER->render(getMemDC());
	
	this->getBackBuffer()->render(getHDC());
}
