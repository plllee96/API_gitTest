#pragma once
#include "GameNode.h"

#define MISSILE_COUNT		20.0f
#define SLOW_MISSILE_COUNT		50.0f
#define FIX_POSX				-16
#define FIX_POSY				-50

struct tagBullet {
	Image* img;
	RECT rc;
	int radius;
	int count;
	float x, y;
	float fireX, fireY;
	float angle;
	float speed;
	float bulletTick;
	bool fire;
};

class Missile : public GameNode {
private:
	vector<tagBullet> _vBullet;
	vector<tagBullet>::iterator _viBullet;

	float _range;
	int _bulletMax;

public:
	HRESULT init(int bulletMax, float range);
	void release(void);
	void update(void);
	void render(void);

	void fire(float x, float y);
	void draw(void);
	void move(void);

	vector<tagBullet> getBullet(void) { return _vBullet; }
	void removeBullet(int arrNum);

	void updateFrame(void);

	Missile() {}
	~Missile() {}
};

class MissileM1 : public GameNode {
private:
	vector<tagBullet> _vBullet;
	vector<tagBullet>::iterator _viBullet;

	float _range;
	int _bulletMax;
public:
	HRESULT init(int bulletMax, float range);
	void release(void);
	void update(void);
	void render(void);

	void fire(float x, float y);
	void draw(void);
	void move(void);

	vector<tagBullet> getBullet(void) { return _vBullet; }
	void removeBullet(int arrNum);

	MissileM1() {}
	~MissileM1() {}
};

class Laser : public GameNode {
private:
	tagBullet _bullet;
	int _laserCount;

	float* _x;
	float* _y;
public:
	HRESULT init(float* x, float* y);
	void release(void);
	void update(void);
	void render(void);

	void fire(float x, float y);
	void draw(void);

	Laser() {}
	~Laser() {}
};

class Beam : public GameNode {
private:
	typedef vector<tagBullet> vBullet;
	typedef vector<tagBullet>::iterator viBullet;
	
	vBullet _vBullet;
	viBullet _viBullet;
	;
	int _bulletMax;
	float _range;

public:
	HRESULT init(int bulletMax, float range);
	void release(void);
	void update(void);
	void render(void);

	void fire(float x, float y);
	void draw(void);
	void move(void);

	vector<tagBullet> getBullet(void) { return _vBullet; }

	Beam() {}
	~Beam() {}
};