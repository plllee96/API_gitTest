#pragma once
#include "GameNode.h"
#include "Enemy.h"
#include "Minion.h"

class EnemyManager : public GameNode {
private:
	typedef vector<Enemy*> vEnemy;
	typedef vector<Enemy*>::iterator viEnemy;

private:
	vEnemy _vMinion;
	viEnemy _viMinion;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);
	
	vector<Enemy*> getMinion(void) { return _vMinion; }
	void removeMinion(int arrNum);

	void setMinion(void);

	EnemyManager() {}
	~EnemyManager() {}
};

