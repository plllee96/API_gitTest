#pragma once
#include "GameNode.h"
#include "Rocket.h"
#include "EnemyManager.h"
#include "EffectManager.h"

class MainGame : public GameNode {
private:
	Rocket* _rocket;
	EnemyManager* _em;
	EffectManager* _efm;
public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	virtual void collision(void);
	virtual void attack(void);

	MainGame() {}
	~MainGame() {}
};

