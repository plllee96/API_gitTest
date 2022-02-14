#include "Stdafx.h"
#include "Effect.h"

HRESULT Effect::init(void) {
	return S_OK;
}

HRESULT Effect::init(const char * imageName, POINT position) {
	_worldTimeCount = TIMEMANAGER->getWorldTime();
	_image = IMAGEMANAGER->findImage(imageName);
	_rc = RectMakeCenter(position.x, position.y, _image->getFrameWidth(), _image->getFrameHeight());
	return S_OK;
}

void Effect::release(void) {
}

void Effect::update(void) {
	endAnimation();
}

void Effect::render(void) {
	draw();
	animation();
}

void Effect::draw() {
	_image->frameRender(getMemDC(), _rc.left, _rc.top, _currentFrameX, _currentFrameY);
}

void Effect::animation() {
	if (_worldTimeCount <= TIMEMANAGER->getWorldTime()) {
		_worldTimeCount = TIMEMANAGER->getWorldTime();
		_currentFrameX++;
	}
}

void Effect::endAnimation() {
	if (_currentFrameX > _image->getMaxFrameX()) {
		_show = false;
	}
}

Effect::Effect() : _rc(RectMake(0, 0, 0, 0)), _currentFrameX(0), _currentFrameY(0),
_x(0.0f), _y(0.0f), _worldTimeCount(0.0f), _show(true) {
}
