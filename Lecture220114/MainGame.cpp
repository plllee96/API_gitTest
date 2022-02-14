#include "Stdafx.h"
#include "MainGame.h"

HRESULT MainGame::init(void) {
	GameNode::init(true);
	cout << "ë°•ê²½?? << endl;
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
<<<<<<< HEAD
	TextOut(getMemDC(), 100, 100, "¹Ú°æÀç git", strlen("¹Ú°æÀç git"));
	TextOut(getMemDC(), 150, 150, "¹Ú°æÀç git", strlen("¹Ú°æÀç git"));
	TextOut(getMemDC(), 200, 200, "¿ÀÀçÈÆ git", strlen("¿ÀÀçÈÆ git"));
	TextOut(getMemDC(), 250, 250, "ÀÌÇü¿ì git", strlen("ÀÌÇü¿ì git"));
	TextOut(getMemDC(), 300, 300, "±è°¡¿¬ git", strlen("±è°¡¿¬ git"));
	TextOut(getMemDC(), 350, 350, "¹Ú°æÀç git", strlen("¹Ú°æÀç git"));
	TextOut(getMemDC(), 400, 400, "¿ÀÀçÈÆ git", strlen("¿ÀÀçÈÆ git"));
	TextOut(getMemDC(), 450, 450, "ÀÌÇü¿ì git", strlen("ÀÌÇü¿ì git"));
	TextOut(getMemDC(), 500, 500, "±è°¡¿¬ git", strlen("±è°¡¿¬ git"));
	TextOut(getMemDC(), 550, 550, "¹Ú°æÀç git", strlen("¹Ú°æÀç git"));
	TextOut(getMemDC(), 600, 600, "¿ÀÀçÈÆ git", strlen("¿ÀÀçÈÆ git"));
	TextOut(getMemDC(), 600, 50, "ÀÌÇü¿ì git", strlen("ÀÌÇü¿ì git"));
	TextOut(getMemDC(), 550, 100, "±è°¡¿¬ git", strlen("±è°¡¿¬ git"));
	TextOut(getMemDC(), 500, 150, "¹Ú°æÀç git", strlen("¹Ú°æÀç git"));
	TextOut(getMemDC(), 450, 200, "¿ÀÀçÈÆ git", strlen("¿ÀÀçÈÆ git"));
	TextOut(getMemDC(), 400, 250, "ÀÌÇü¿ì git", strlen("ÀÌÇü¿ì git"));
	TextOut(getMemDC(), 350, 300, "±è°¡¿¬ git", strlen("±è°¡¿¬ git"));
	TextOut(getMemDC(), 300, 250, "¹Ú°æÀç git", strlen("¹Ú°æÀç git"));
	TextOut(getMemDC(), 100, 100, "ë°•ê²½??git", strlen("ë°•ê²½??git"));
	TextOut(getMemDC(), 150, 150, "ë°•ê²½??git", strlen("ë°•ê²½??git"));
	TextOut(getMemDC(), 200, 200, "?¤ìž¬??git", strlen("?¤ìž¬??git"));
	TextOut(getMemDC(), 250, 250, "?´í˜•??git", strlen("?´í˜•??git"));
	TextOut(getMemDC(), 300, 300, "ê¹€ê°€??git", strlen("ê¹€ê°€??git"));
	TextOut(getMemDC(), 350, 350, "ë°•ê²½??git", strlen("ë°•ê²½??git"));
	TextOut(getMemDC(), 400, 400, "?¤ìž¬??git", strlen("?¤ìž¬??git"));
	TextOut(getMemDC(), 450, 450, "?´í˜•??git", strlen("?´í˜•??git"));
	TextOut(getMemDC(), 500, 500, "ê¹€ê°€??git", strlen("ê¹€ê°€??git"));
	TextOut(getMemDC(), 550, 550, "ë°•ê²½??git", strlen("ë°•ê²½??git"));
	TextOut(getMemDC(), 600, 600, "?¤ìž¬??git", strlen("?¤ìž¬??git"));
	TextOut(getMemDC(), 600, 50, "?´í˜•??git", strlen("?´í˜•??git"));
	TextOut(getMemDC(), 550, 100, "ê¹€ê°€??git", strlen("ê¹€ê°€??git"));
	TextOut(getMemDC(), 500, 150, "ë°•ê²½??git", strlen("ë°•ê²½??git"));
	TextOut(getMemDC(), 450, 200, "?¤ìž¬??git", strlen("?¤ìž¬??git"));
	TextOut(getMemDC(), 400, 250, "?´í˜•??git", strlen("?´í˜•??git"));
	TextOut(getMemDC(), 350, 300, "ê¹€ê°€??git", strlen("ê¹€ê°€??git"));
	TextOut(getMemDC(), 300, 350, "ë°•ê²½??git", strlen("ë°•ê²½??git"));
	TextOut(getMemDC(), 250, 400, "?¤ìž¬??git", strlen("?¤ìž¬??git"));
	TextOut(getMemDC(), 200, 450, "?´í˜•??git", strlen("?´í˜•??git"));

	


	TIMEMANAGER->render(getMemDC());
	
	this->getBackBuffer()->render(getHDC());
}
