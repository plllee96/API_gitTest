#pragma once
#include "GameNode.h"

class Effect : public GameNode {
protected:
	Image* _image;
	RECT _rc;
	int _currentFrameX;
	int _currentFrameY;
	float _x, _y;
	float _worldTimeCount;
	bool _show;
public:
	HRESULT init(void);
	HRESULT init(const char* imageName, POINT position);
	void release(void);
	void update(void);
	void render(void);

	void draw();
	void animation();
	void endAnimation();

	int getCurrentFrameX() { return _currentFrameX; }
	bool isShow() { return _show; }

	Effect();
	virtual ~Effect() {}
};

