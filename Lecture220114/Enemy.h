#pragma once
#include "GameNode.h"
#include "EnemyBullets.h"

class Enemy : public GameNode {
protected:
	Image* _image;
	Image* _hpImage;
	EnemyBullet* _bullet;
	
	RECT _rc;
	int _currentFrameX;
	int _currentFrameY;
	float _x, _y;
	float _rndTimeCount;
	float _worldTimeCount;
	
	float _hp;
	float _worldAttackTimeCount;
	float _rndAttackDelay;

public:
	HRESULT init(void);
	HRESULT init(const char* imageName, POINT position);
	void release(void);
	void update(void);
	void render(void);

	virtual void move();
	void draw();
	void animation();

	RECT getRC() { return _rc; }
	EnemyBullet* getEnemyBullet() { return _bullet; }
	float getWorldAttackTimeCount() { return _worldAttackTimeCount; }
	void setWorldAttackTimeCount(float watc) { _worldAttackTimeCount = watc; }
	float getRndAttackDelay() { return _rndAttackDelay; }

	Enemy();
	virtual ~Enemy() {}
};

