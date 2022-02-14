#pragma once
#include "Enemy.h"
class Minion : public Enemy{
private:
	float _speed;
	bool _isLeft;
public:
	void move();

	Minion();
	~Minion() {}
};

class MinionM1 : public Enemy {
private:
	float _angle;
public:
	void move();

	MinionM1(float angle);
	~MinionM1() {}
};

class MinionM2 : public Enemy {
private:
	float _angle;
	float _speed;
	int _count;

public:
	void move();

	MinionM2();
	~MinionM2() {}
};
