#include "Stdafx.h"
#include "EnemyBullets.h"

HRESULT EnemyBullet::init(int bulletMax, float range) {
	_range = range;
	_bulletMax = bulletMax;
	return S_OK;
}

void EnemyBullet::release(void) {
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet) {
		SAFE_DELETE(_viBullet->img);
	}
}

void EnemyBullet::update(void) {
	move();
}

void EnemyBullet::render(void) {
	draw();
}

void EnemyBullet::fire(float x, float y, float angle) {
	if (_bulletMax <= _vBullet.size()) return;

	tagEnemyBullet bullet;
	ZeroMemory(&bullet, sizeof(tagEnemyBullet));

	bullet.img = new Image;
	bullet.img->init("Resources/Images/Bullet.bmp", 0.0f, 0.0f, 30, 30, true, RGB(255, 0, 255));
	bullet.fire = false;
	bullet.speed = 5.0f;
	bullet.x = bullet.fireX = x;
	bullet.y = bullet.fireY = y;
	bullet.angle = angle;
	bullet.rc = RectMakeCenter(bullet.x, bullet.y, bullet.img->getFrameWidth(), bullet.img->getFrameHeight());

	_vBullet.push_back(bullet);
}

void EnemyBullet::draw(void) {
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet) {
		_viBullet->img->render(getMemDC(), _viBullet->rc.left, _viBullet->rc.top);
	}
}

void EnemyBullet::move(void) {
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end();) {
		_viBullet->x += _viBullet->speed * cos(_viBullet->angle);
		_viBullet->y += - _viBullet->speed * sin(_viBullet->angle);
		_viBullet->rc = RectMakeCenter(_viBullet->x, _viBullet->y, _viBullet->img->getWidth(), _viBullet->img->getHeight());

		if (_range < getDistance(_viBullet->fireX, _viBullet->fireY, _viBullet->x, _viBullet->y)) {
			SAFE_DELETE(_viBullet->img);
			_viBullet = _vBullet.erase(_viBullet);
		}
		else ++_viBullet;
	}
}

void EnemyBullet::removeBullet(int arrNum) {
	SAFE_DELETE(_vBullet[arrNum].img);
	_vBullet.erase(_vBullet.begin() + arrNum);
}
