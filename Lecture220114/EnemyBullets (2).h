#pragma once
#include "GameNode.h"

struct tagEnemyBullet {
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

class EnemyBullet : public GameNode {
private:
	vector<tagEnemyBullet> _vBullet;
	vector<tagEnemyBullet>::iterator _viBullet;

	float _range;
	int _bulletMax;

public:
	HRESULT init(int bulletMax, float range);
	void release(void);
	void update(void);
	void render(void);

	void fire(float x, float y, float angle);
	void draw(void);
	void move(void);

	vector<tagEnemyBullet> getBullet(void) { return _vBullet; }
	void removeBullet(int arrNum);

	EnemyBullet() {}
	~EnemyBullet() {}
};

