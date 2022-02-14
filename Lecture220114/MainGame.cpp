#include "Stdafx.h"
#include "MainGame.h"

HRESULT MainGame::init(void) {
	GameNode::init(true);
	cout << "�ڰ���" << endl;
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
	TextOut(getMemDC(), 100, 100, "�ڰ��� git", strlen("�ڰ��� git"));
	TextOut(getMemDC(), 150, 150, "�ڰ��� git", strlen("�ڰ��� git"));
	TextOut(getMemDC(), 200, 200, "������ git", strlen("������ git"));
	TextOut(getMemDC(), 250, 250, "������ git", strlen("������ git"));
	TextOut(getMemDC(), 300, 300, "�谡�� git", strlen("�谡�� git"));
	TextOut(getMemDC(), 350, 350, "�ڰ��� git", strlen("�ڰ��� git"));


	TIMEMANAGER->render(getMemDC());
	
	this->getBackBuffer()->render(getHDC());
}
