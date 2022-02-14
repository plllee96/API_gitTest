#include "Stdafx.h"
#include "Shield.h"

HRESULT Shield::init(float * x, float * y) {
	_image = IMAGEMANAGER->addFrameImage("SHIELD", "Resources/Images/Shield.bmp", 0.0f, 0.0f, 640, 80, 8, 1, true, RGB(255, 0, 255));
	_x = x;
	_y = y;
	_rc = RectMakeCenter((int)_x, (int)_y, _image->getFrameWidth(), _image->getFrameHeight());
	_shieldTick = 0.0f;
	_activate = false;
	return S_OK;
}

void Shield::release(void) {
}

void Shield::update(void) {
	_rc = RectMakeCenter((int)*_x, (int)*_y, _image->getFrameWidth(), _image->getFrameHeight());
}

void Shield::render(void) {
	if(_activate) _image->frameRender(getMemDC(), _rc.left, _rc.top, _image->getFrameX(), _image->getFrameY());
	if (SHIELD_COUNT + _shieldTick <= GetTickCount()) {
		_shieldTick = GetTickCount();
		_image->setFrameX(_image->getFrameX() + 1);
		if (_image->getFrameX() >= _image->getMaxFrameX()) {
			_image->setFrameX(0);
		}
	}
}

void Shield::toggleShield(void) {
	_activate = !_activate;
}
