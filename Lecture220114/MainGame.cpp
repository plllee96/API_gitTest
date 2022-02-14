#include "Stdafx.h"
#include "MainGame.h"

HRESULT MainGame::init(void) {
	GameNode::init(true);
	cout << "박경재" << endl;
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
	TextOut(getMemDC(), 100, 100, "박경재 git", strlen("박경재 git"));
	TextOut(getMemDC(), 150, 150, "박경재 git", strlen("박경재 git"));
	TextOut(getMemDC(), 200, 200, "오재훈 git", strlen("오재훈 git"));
	TextOut(getMemDC(), 250, 250, "이형우 git", strlen("이형우 git"));
	TextOut(getMemDC(), 300, 300, "김가연 git", strlen("김가연 git"));
	TextOut(getMemDC(), 350, 350, "박경재 git", strlen("박경재 git"));
	TextOut(getMemDC(), 400, 400, "오재훈 git", strlen("오재훈 git"));
	TextOut(getMemDC(), 450, 450, "이형우 git", strlen("이형우 git"));
	TextOut(getMemDC(), 500, 500, "김가연 git", strlen("김가연 git"));
	TextOut(getMemDC(), 550, 550, "박경재 git", strlen("박경재 git"));
	TextOut(getMemDC(), 600, 600, "오재훈 git", strlen("오재훈 git"));
	TextOut(getMemDC(), 600, 50, "이형우 git", strlen("이형우 git"));
	TextOut(getMemDC(), 550, 100, "김가연 git", strlen("김가연 git"));
	TextOut(getMemDC(), 500, 150, "박경재 git", strlen("박경재 git"));
	TextOut(getMemDC(), 450, 200, "오재훈 git", strlen("오재훈 git"));
	TextOut(getMemDC(), 400, 250, "이형우 git", strlen("이형우 git"));
	TextOut(getMemDC(), 350, 300, "김가연 git", strlen("김가연 git"));
	TextOut(getMemDC(), 300, 350, "박경재 git", strlen("박경재 git"));
	TextOut(getMemDC(), 250, 400, "오재훈 git", strlen("오재훈 git"));
	TextOut(getMemDC(), 200, 450, "이형우 git", strlen("이형우 git"));
	//




	TIMEMANAGER->render(getMemDC());

	this->getBackBuffer()->render(getHDC());
}