#include "Stdafx.h"
#include "Minion.h"

void Minion::move() {
	(_isLeft) ? _speed = -4.0f : _speed = 4.0f;
	if (_rc.left < 0) _isLeft = false;
	else if (_rc.right > WINSIZE_X) _isLeft = true;
	_rc.left += _speed;
	_rc.right += _speed;
}

Minion::Minion() :  _speed(0.0f), _isLeft(false) {
}

void MinionM1::move() {
	_x = CENTER_X + 200 * cos(_angle * PI / 180);
	_y = CENTER_Y - 150 + 200 * sin(_angle * PI / 180);
	_rc = RectMakeCenter(_x, _y, _image->getFrameWidth(), _image->getFrameHeight());
	_angle+= 1.0f;
}

MinionM1::MinionM1(float angle) {
	_angle = angle;
}

void MinionM2::move() {
	if (_speed <= 0.0f) _count++;

	if (_count > 10) {
		_angle = RND->getFloat(360.0f);
		_speed = 7.0f;
		_count = 0;
	}
	else {
		_rc.left += _speed * cos(_angle * PI / 180);
		_rc.right += _speed * cos(_angle * PI / 180);
		_rc.top += _speed * sin(_angle * PI / 180);
		_rc.bottom += _speed * sin(_angle * PI / 180);
		_speed -= 0.3f;
	}
	if (_rc.left > WINSIZE_X) {
		_rc.right = 0;
		_rc.left = _rc.right - _image->getFrameWidth();
	}
	else if (_rc.right < 0) {
		_rc.left = WINSIZE_X;
		_rc.right = _rc.left + _image->getFrameWidth();
	}
	if (_rc.top > WINSIZE_Y) {
		_rc.bottom = 0;
		_rc.top = _rc.bottom - _image->getFrameHeight();
	}
	else if (_rc.bottom < 0) {
		_rc.top = WINSIZE_Y;
		_rc.bottom = _rc.top + _image->getFrameHeight();
	}
}

MinionM2::MinionM2() : _angle(RND->getFloat(360.0f)), _speed(0.0f), _count(0) {
	
}
