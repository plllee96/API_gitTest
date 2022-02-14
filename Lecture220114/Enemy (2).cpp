#include "Stdafx.h"
#include "Enemy.h"

HRESULT Enemy::init(void) {
	//Do Nothing
	return S_OK;
}

HRESULT Enemy::init(const char * imageName, POINT position) {
	_worldTimeCount = GetTickCount();
	_rndTimeCount = RND->getFromFloatTo(50, 150);
	_worldAttackTimeCount = TIMEMANAGER->getWorldTime();
	_rndAttackDelay = RND->getFromFloatTo(2.0f, 3.0f);
	
	_image = IMAGEMANAGER->findImage(imageName);
	_hpImage = IMAGEMANAGER->addFrameImage("Health", "Resources/Images/Health.bmp", 50, 50, 1, 5, true, RGB(255, 0, 255));
	_rc = RectMakeCenter(position.x, position.y, _image->getFrameWidth(), _image->getFrameHeight());
	_hp = 5;

	_bullet = new EnemyBullet;
	_bullet->init(3, 1000);

	return S_OK;
}

void Enemy::release(void) {
	if (_bullet) _bullet->release();
	SAFE_DELETE(_bullet);
}

void Enemy::update(void) {
	_bullet->update();
	move();
	RECT temprect;
}

void Enemy::render(void) {
	_bullet->render();
	draw();
	animation();
}

void Enemy::move() {
}

void Enemy::draw() {
	_image->frameRender(getMemDC(), _rc.left, _rc.top, _currentFrameX, _currentFrameY);
	_hpImage->frameRender(getMemDC(), _rc.left + 5, _rc.top - 10, 1, (5 -_hp));
	//Rectangle(getMemDC(), _rc.left, _rc.top - 10, _rc.left + (_hp / 10) * 60, _rc.top);
}

void Enemy::animation() {
	if (_rndTimeCount + _worldTimeCount <= GetTickCount()) {
		_worldTimeCount = GetTickCount();
		_currentFrameX++;
		if (_image->getMaxFrameX() < _currentFrameX) {
			_currentFrameX = 0;
		}
	}
}

Enemy::Enemy() : _rc(RectMake(0, 0, 0, 0)),
					   _currentFrameX(0), _currentFrameY(0),
					   _x(0.0f), _y(0.0f),
					   _rndTimeCount(0.0f), _worldTimeCount(0.0f), _worldAttackTimeCount(0.0f) {
}
