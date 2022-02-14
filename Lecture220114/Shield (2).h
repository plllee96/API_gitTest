#pragma once
#include "GameNode.h"

#define SHIELD_COUNT		20.0f

class Shield : public GameNode {
private:
	Image* _image;
	RECT _rc;
	float* _x;
	float* _y;
	float _shieldTick;
	bool _activate;
public:
	HRESULT init(float* x, float* y);
	void release(void);
	void update(void);
	void render(void);

	void toggleShield(void);

	Shield() {}
	~Shield() {}
};

