#include "Stdafx.h"
#include "Flame.h"

HRESULT Flame::init(const char * fileName, float * x, float * y) {
	_image = IMAGEMANAGER->addFrameImage("FLAME", "Resources/Images/Flame.bmp", 0.0f, 0.0f, 432, 297, MAX_FRAME, 1, true, RGB(255, 0, 255));
	_x = x;
	_y = y;
	_rc = RectMakeCenter((int)_x, (int)_y, _image->getFrameWidth(), _image->getFrameHeight());
	_flameTick = 0.0f;
	return S_OK;
}

void Flame::release(void) {
}

void Flame::update(void) {
	_rc = RectMakeCenter(*_x, *_y + FIX_POSY, _image->getFrameWidth(), _image->getFrameHeight());
}

void Flame::render(void) {
	_image->frameRender(getMemDC(), _rc.left, _rc.top, _image->getFrameX(), _image->getFrameY());
	updateFrame();
}

void Flame::updateFrame() {
	if (FLAME_COUNT + _flameTick <= GetTickCount()) {
		_flameTick = GetTickCount();
		_image->setFrameX(_image->getFrameX() + 1);
		if (_image->getFrameX() >= _image->getMaxFrameX()) {
			_image->setFrameX(0);
		}
	}
}

