#pragma once
#include "GameNode.h"
#include "Effect.h"

class EffectManager {
private:
	typedef vector<Effect*> vEffect;
	typedef vector<Effect*>::iterator viEffect;

	vEffect _vEffect;
	viEffect _viEffect;
public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	vector<Effect*> getEffect(void) { return _vEffect; }
	
	void addEffect(const char* imageName, POINT pt);
	void removeEffect(int arrNum);

	EffectManager() {}
	~EffectManager() {}
};

