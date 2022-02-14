#include "Stdafx.h"
#include "Bullets.h"

#pragma region MISSILE
HRESULT Missile::init(int bulletMax, float range) {
	_range = range;
	for (int i = 0; i < bulletMax; i++) {
		tagBullet bullet;
		ZeroMemory(&bullet, sizeof(tagBullet));
		bullet.img = new Image;
		bullet.img->init("Resources/Images/Missile.bmp", 0.0f, 0.0f, 416, 64, 13, 1, true, RGB(255, 0, 255));
		bullet.fire = false;
		bullet.speed = 5.0f;
		bullet.bulletTick = 0;
		_vBullet.push_back(bullet);
	}
	return S_OK;
}

void Missile::release(void) {
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet) {
		SAFE_DELETE(_viBullet->img);
	}
	_vBullet.clear();
	vector<tagBullet>().swap(_vBullet);
}

void Missile::update(void) {
	move();
	
}

void Missile::render(void) {
	draw();
}

void Missile::fire(float x, float y) {
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet) {
		if (_viBullet->fire) continue;
		_viBullet->fire = true;
		_viBullet->x = _viBullet->fireX = x + FIX_POSX;
		_viBullet->y = _viBullet->fireY = y + FIX_POSY;
		_viBullet->rc = RectMakeCenter(_viBullet->x, _viBullet->y, _viBullet->img->getFrameWidth(), _viBullet->img->getFrameHeight());
		break;
	}
}

void Missile::draw(void) {
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet) {
		if (!_viBullet->fire) continue;
		_viBullet->img->frameRender(getMemDC(), _viBullet->x, _viBullet->y, _viBullet->img->getFrameX(), _viBullet->img->getFrameY());

		_viBullet->count++;
		if (_viBullet->count % 5 == 0) {
			_viBullet->img->setFrameX(_viBullet->img->getFrameX() + 1);
			if (_viBullet->img->getFrameX() >= _viBullet->img->getMaxFrameX()) {
				_viBullet->img->setFrameX(0);
			}
			_viBullet->count = 0;
		}
	}
}

void Missile::move(void) {
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet) {
		if (!_viBullet->fire) continue;
		if(_range < getDistance(_viBullet->fireX, _viBullet->fireY, _viBullet->x, _viBullet->y)) _viBullet->fire = false;
		_viBullet->y -= _viBullet->speed;
		_viBullet->rc = RectMakeCenter(_viBullet->x, _viBullet->y, _viBullet->img->getFrameWidth(), _viBullet->img->getFrameHeight());
	}
}

void Missile::removeBullet(int arrNum) {
	_vBullet[arrNum].fire = false;
	_vBullet[arrNum].rc = { 0,0,0,0 };
}

void Missile::updateFrame(void) {
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet) {
		if (!_viBullet->fire) continue;
		if (MISSILE_COUNT + _viBullet->bulletTick <= GetTickCount()) {
			_viBullet->bulletTick = GetTickCount();
			_viBullet->img->setFrameX(_viBullet->img->getFrameX() + 1);
			if (_viBullet->img->getFrameX() >= _viBullet->img->getMaxFrameX()) {
				_viBullet->img->setFrameX(0);
			}
		}
	}
}
#pragma endregion

#pragma region MISSILEM1
HRESULT MissileM1::init(int bulletMax, float range) {
	_range = range;
	_bulletMax = bulletMax;

	return S_OK;
}

void MissileM1::release(void) {
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet) {
		SAFE_DELETE(_viBullet->img);
	}

	_vBullet.clear();
}

void MissileM1::update(void) {
	move();
}

void MissileM1::render(void) {
	draw();
}

void MissileM1::fire(float x, float y) {
	if (_bulletMax <= _vBullet.size()) return;

	tagBullet bullet;
	ZeroMemory(&bullet, sizeof(tagBullet));

	bullet.img = new Image;
	bullet.img->init("Resources/Images/Missile.bmp", 0.0f, 0.0f, 416, 64, 13, 1, true, RGB(255, 0, 255));
	bullet.fire = false;
	bullet.speed = 2.0f;
	bullet.x = bullet.fireX = x;
	bullet.y = bullet.fireY = y;
	bullet.rc = RectMakeCenter(bullet.x, bullet.y, bullet.img->getFrameWidth(), bullet.img->getFrameHeight());

	_vBullet.push_back(bullet);
}

void MissileM1::draw(void) {
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet) {
		_viBullet->img->frameRender(getMemDC(), _viBullet->rc.left, _viBullet->rc.top);

		_viBullet->count++;
		if (_viBullet->count % 3 == 0) {
			_viBullet->img->setFrameX(_viBullet->img->getFrameX() + 1);
			if (_viBullet->img->getFrameX() >= _viBullet->img->getMaxFrameX()) {
				_viBullet->img->setFrameX(0);
			}
			_viBullet->count = 0;
		}
	}
}

void MissileM1::move(void) {
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end();) {
		_viBullet->y -= _viBullet->speed;
		_viBullet->rc = RectMakeCenter(_viBullet->x, _viBullet->y,
			_viBullet->img->getFrameWidth(), _viBullet->img->getFrameHeight());

		if (_range < getDistance(_viBullet->fireX, _viBullet->fireY, _viBullet->x, _viBullet->y + 100)) {
			SAFE_DELETE(_viBullet->img);
			_viBullet = _vBullet.erase(_viBullet);
		}
		else ++_viBullet;
	}
}

void MissileM1::removeBullet(int arrNum) {
	SAFE_DELETE(_vBullet[arrNum].img);
	_vBullet.erase(_vBullet.begin() + arrNum);
}
#pragma endregion

#pragma region MISSILE_SHOTGUN
/*
HRESULT MissileM1::init(int bulletMax, float range) {
	_range = range;
	_bulletMax = bulletMax;
	return S_OK;
}

void MissileM1::release(void) {
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet) {
		SAFE_DELETE(_viBullet->img);
	}
	_vBullet.clear();
	vector<tagBullet>().swap(_vBullet);
}

void MissileM1::update(void) {
	move();
}

void MissileM1::render(void) {
	draw();
}

void MissileM1::fire(float x, float y) {
	if (_bulletMax - 2 <= _vBullet.size()) return;
	for (int i = 0; i < 3; i++) {
		tagBullet bullet;
		ZeroMemory(&bullet, sizeof(tagBullet));
		bullet.img = new Image;
		bullet.img->init("Resources/Images/Bullet.bmp", 30, 30, true, RGB(255, 0, 255));
		bullet.speed = 4.0f;
		bullet.x = bullet.fireX = x + FIX_POSX;
		bullet.y = bullet.fireY = y + FIX_POSY;
		bullet.angle = 60.0f + 30.0f * (i % 3);
		bullet.bulletTick = 0;
		bullet.rc = RectMakeCenter(bullet.x, bullet.y, bullet.img->getFrameWidth(), bullet.img->getFrameHeight());
		_vBullet.push_back(bullet);
	}
}

void MissileM1::draw(void) {
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet) {
		_viBullet->img->render(getMemDC(), _viBullet->x, _viBullet->y);
	}
}

void MissileM1::move(void) {
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet) {
		float tempDistance = getDistance(_viBullet->fireX, _viBullet->fireY, _viBullet->x, _viBullet->y);
		if (_range / 3 > tempDistance) {
			_viBullet->rc = RectMakeCenter(_viBullet->x, _viBullet->y, _viBullet->img->getFrameWidth(), _viBullet->img->getFrameHeight());
			_viBullet->y -= _viBullet->speed;
		}
		else if (_range / 3 <= tempDistance) {
			_viBullet->rc = RectMakeCenter(_viBullet->x, _viBullet->y, _viBullet->img->getFrameWidth(), _viBullet->img->getFrameHeight());
			_viBullet->y -= _viBullet->speed * sin(_viBullet->angle * PI / 180);
			_viBullet->x += _viBullet->speed * cos(_viBullet->angle * PI / 180);
		}
		if (_range < tempDistance) {
			SAFE_DELETE(_viBullet->img);
			_vBullet.erase(_viBullet);
			break;
		}
	}
}
*/
#pragma endregion

#pragma region MISSILE_LASER
HRESULT Laser::init(float* x, float* y) {
	ZeroMemory(&_bullet, sizeof(tagBullet));
	_bullet.img = new Image;
	_bullet.img->init("Resources/Images/Laser.bmp", 0.0f, 0.0f, 488, 800, 4, 1, true, RGB(255, 0, 255));
	_bullet.fire = false;
	_x = x;
	_y = y;
	_bullet.bulletTick = 0;
	_laserCount = 0;
	return S_OK;
}

void Laser::release(void) {
}

void Laser::update(void) {
	if (_bullet.fire) _laserCount++;
	if (_laserCount > 50) {
		_bullet.fire = false;
		_laserCount = 0;
	}
	_bullet.rc = RectMakeCenter((int)*_x - 3, (int)*_y - 380, _bullet.img->getFrameWidth(), _bullet.img->getFrameHeight());
}

void Laser::render(void) {
	if (_bullet.fire) draw();
}

void Laser::fire(float x, float y) {
	_bullet.fire = true;
}

void Laser::draw(void) {
	_bullet.img->frameRender(getMemDC(), _bullet.rc.left, _bullet.rc.top, _bullet.img->getFrameX(), _bullet.img->getFrameY());
	if (SLOW_MISSILE_COUNT + _bullet.bulletTick <= GetTickCount()) {
		_bullet.bulletTick = GetTickCount();
		_bullet.img->setFrameX(_bullet.img->getFrameX() + 1);
		if (_bullet.img->getFrameX() >= _bullet.img->getMaxFrameX()) {
			_bullet.img->setFrameX(0);
		}
	}
}
#pragma endregion

#pragma region MISSILE_BEAM
HRESULT Beam::init(int bulletMax, float range) {
	_range = range;
	_bulletMax = bulletMax;
	return S_OK;
}

void Beam::release(void) {
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet) {
		SAFE_DELETE(_viBullet->img);
	}
	_vBullet.clear();
}

void Beam::update(void) {
	move();
}

void Beam::render(void) {
	draw();
}

void Beam::fire(float x, float y) {
	if (_bulletMax <= _vBullet.size())return;

	tagBullet bullet;
	ZeroMemory(&bullet, sizeof(tagBullet));

	bullet.img = new Image;
	bullet.img->init("Resources/Images/Beam.bmp", 0.0f, 0.0f, 412, 801, 4, 1, true, RGB(255, 0, 255));
	bullet.speed = 0.1f;
	bullet.x = bullet.fireX = x;
	bullet.y = bullet.fireY = y;
	bullet.rc = RectMakeCenter(bullet.x, bullet.y, bullet.img->getFrameWidth(), bullet.img->getFrameHeight());
	_vBullet.push_back(bullet);

}

void Beam::draw(void) {
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet) {
		_viBullet->img->frameRender(getMemDC(), _viBullet->rc.left, _viBullet->rc.top);

		_viBullet->count++;
		if (_viBullet->count % 3 == 0) {
			_viBullet->img->setFrameX(_viBullet->img->getFrameX() + 1);
			if (_viBullet->img->getFrameX() >= _viBullet->img->getMaxFrameX()) {
				_viBullet->img->setFrameX(0);
			}
			_viBullet->count = 0;
		}
	}
}

void Beam::move(void) {
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end();) {
		_viBullet->y -= _viBullet->speed;
		_viBullet->rc = RectMakeCenter(_viBullet->x, _viBullet->y,
			_viBullet->img->getFrameWidth(), _viBullet->img->getFrameHeight());

		if (_range < getDistance(_viBullet->fireX, _viBullet->fireY, _viBullet->x, _viBullet->y)) {
			SAFE_DELETE(_viBullet->img);
			_viBullet = _vBullet.erase(_viBullet);
		}
		else ++_viBullet;
	}
}
#pragma endregion