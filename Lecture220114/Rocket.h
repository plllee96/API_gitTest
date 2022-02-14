#pragma once
#include "GameNode.h"
#include "Flame.h"
#include "Bullets.h"
#include "Shield.h"
#include "ProgressBar.h"

#define ROCKET_SPEED		3.0f

enum EWeapon {MISSILE, BEAM};
class Rocket : public GameNode {
private:
	Image* _image;
	Flame* _flame;
	Missile* _missile;
	MissileM1* _missileM1;
	Laser* _laser;
	Shield* _shield;
	Beam* _beam;
	ProgressBar* _hpBar;

	RECT _rc;

	EWeapon _setWeapon;
	float _x, _y;
	float _currentHp, _maxHp;
	bool _beamIrradiation;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	void checkKeyInput(void);

	void removeMissile(int arrNum);
	void removeMissileM1(int arrNum);

	Missile* getMissile() { return _missile; }
	MissileM1* getMissileM1() { return _missileM1; }
	Beam* getBeam() { return _beam; }
	RECT getRect(void) { return _rc; }

	inline void hitDamage(float damage) {
		if (_currentHp <= damage) {
			_currentHp = 0;
		}
		else {
			_currentHp -= damage;
		}
		
	}

	Rocket() {}
	~Rocket() {}
};

