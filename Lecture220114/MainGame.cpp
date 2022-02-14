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
	SetBkMode(getMemDC(), TRANSPARENT);

	TextOut(getMemDC(), 50, 50, "LHW_GitTest", strlen("LHW_GitTest"));
	TextOut(getMemDC(), 100, 100, "�ڰ��� git", strlen("�ڰ��� git"));
	TextOut(getMemDC(), 150, 150, "�ڰ��� git", strlen("�ڰ��� git"));
	TextOut(getMemDC(), 200, 200, "������ git", strlen("������ git"));
	TextOut(getMemDC(), 250, 250, "������ git", strlen("������ git"));
	TextOut(getMemDC(), 300, 300, "�谡�� git", strlen("�谡�� git"));
	TextOut(getMemDC(), 350, 350, "�ڰ��� git", strlen("�ڰ��� git"));
	TextOut(getMemDC(), 400, 400, "������ git", strlen("������ git"));
	TextOut(getMemDC(), 450, 450, "������ git", strlen("������ git"));
	TextOut(getMemDC(), 500, 500, "�谡�� git", strlen("�谡�� git"));
	TextOut(getMemDC(), 550, 550, "�ڰ��� git", strlen("�ڰ��� git"));
	TextOut(getMemDC(), 600, 600, "������ git", strlen("������ git"));
	TextOut(getMemDC(), 600, 50, "������ git", strlen("������ git"));
	TextOut(getMemDC(), 550, 100, "�谡�� git", strlen("�谡�� git"));
	TextOut(getMemDC(), 500, 150, "�ڰ��� git", strlen("�ڰ��� git"));
	TextOut(getMemDC(), 450, 200, "������ git", strlen("������ git"));
	TextOut(getMemDC(), 400, 250, "������ git", strlen("������ git"));
	TextOut(getMemDC(), 350, 300, "�谡�� git", strlen("�谡�� git"));
	TextOut(getMemDC(), 300, 350, "�ڰ��� git", strlen("�ڰ��� git"));
	TextOut(getMemDC(), 250, 400, "������ git", strlen("������ git"));
	TextOut(getMemDC(), 200, 450, "������ git", strlen("������ git"));
	//




	TIMEMANAGER->render(getMemDC());

	this->getBackBuffer()->render(getHDC());
}