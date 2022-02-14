#include "Stdafx.h"
#include "Rocket.h"

HRESULT Rocket::init(void) {
	_image = IMAGEMANAGER->addImage("ROCKET", "Resources/Images/Rocket.bmp", 52 , 64 , true, RGB(255, 0, 255));
	_x = CENTER_X;
	_y = WINSIZE_Y - 100;
	_rc = RectMakeCenter(_x, _y, _image->getWidth(), _image->getHeight());
	_flame = new Flame;
	_flame->init("Flame.bmp", &_x, &_y);

	_shield = new Shield;
	_shield->init(&_x, &_y);

	_missile = new Missile;
	_missile->init(10, 700);

	_missileM1 = new MissileM1;
	_missileM1->init(30, 700);

	_laser = new Laser;
	_laser->init(&_x, &_y);

	_beam = new Beam;
	_beam->init(1, 0.5);
	_beamIrradiation = false;

	_hpBar = new ProgressBar;
	_hpBar->init(_x, _y, 52, 4);

	_setWeapon = MISSILE;
	_currentHp = 10;
	_maxHp = 10;

	return S_OK;
}

void Rocket::release(void) {
	if(_flame) _flame->release();
	SAFE_DELETE(_flame);

	if (_missile) _missile->release();
	SAFE_DELETE(_missile);

	if (_missileM1) _missileM1->release();
	SAFE_DELETE(_missileM1);

	if (_shield) _shield->release();
	SAFE_DELETE(_shield);

	if (_laser) _laser->release();
	SAFE_DELETE(_laser);

	if (_beam) _beam->release();
	SAFE_DELETE(_beam);

	if (_hpBar) _hpBar->release();
	SAFE_DELETE(_hpBar);
}

void Rocket::update(void) {
	checkKeyInput();
	_rc = RectMakeCenter(_x, _y, _image->getWidth(), _image->getHeight());
	_flame->update();
	_missile->update();
	_missileM1->update();
	_shield->update();
	_laser->update();
	_beam->update();

	_hpBar->setX(_x - (_rc.right - _rc.left) / 2);
	_hpBar->setY(_y - 10 -  (_rc.bottom - _rc.top) / 2);
	_hpBar->update();
	_hpBar->setGauge(_currentHp, _maxHp);
}

void Rocket::render(void) {
	_missile->render();
	_missileM1->render();
	_flame->render();
	_image->render(getMemDC(), _rc.left, _rc.top);
	_shield->render();
	_laser->render();
	_beam->render();
	_hpBar->render();
}

void Rocket::checkKeyInput(void) {
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && _rc.right < WINSIZE_X && !_beamIrradiation) {
		_x += ROCKET_SPEED;
	}
	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && _rc.left > 0 && !_beamIrradiation) {
		_x -= ROCKET_SPEED;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN) && _rc.bottom < WINSIZE_Y) {
		_y += ROCKET_SPEED;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP) && _rc.top > 0) {
		_y -= ROCKET_SPEED;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE)) {
		switch (_setWeapon) {
		case MISSILE: _missile->fire(_x, _y); break;
		case BEAM: _beam->fire(_x - 5, _y - 430); break;
		}
	}
	if (KEYMANAGER->isOnceKeyDown('Z')) {
		_missileM1->fire(_x, _y);
	}
	if (KEYMANAGER->isOnceKeyDown('X')) {
		_shield->toggleShield();
	}
	if (KEYMANAGER->isOnceKeyDown('C')) {
		_laser->fire(_x, _y);
	}
	if (KEYMANAGER->isOnceKeyDown('A')) {
		_setWeapon = MISSILE;
	}
	if (KEYMANAGER->isOnceKeyDown('S')) {
		_setWeapon = BEAM;
	}
	if (KEYMANAGER->isOnceKeyDown('D')) {
		//fire black hole
	}

	if (KEYMANAGER->isOnceKeyDown('1')) hitDamage(1.0f);
	if (KEYMANAGER->isOnceKeyDown('2')) hitDamage(-1.0f);
}

void Rocket::removeMissile(int arrNum) {
	_missile->removeBullet(arrNum);
}

void Rocket::removeMissileM1(int arrNum) {
	_missileM1->removeBullet(arrNum);
}
