#pragma once
#include "GameNode.h"

#define MAX_FRAME			9
#define FLAME_COUNT		20.0f
#define FIX_POSY				180

class Flame : public GameNode {
private:
	Image* _image;
	RECT _rc;
	float _width, _height;
	float* _x;
	float* _y;
	float _flameTick;
public:
	HRESULT init(const char* fileName, float* x, float* y);
	void release(void);
	void update(void);
	void render(void);

	void updateFrame();
	Flame() {}
	~Flame() {}
};

