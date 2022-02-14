#include "Stdafx.h"
#include "EffectManager.h"

HRESULT EffectManager::init(void) {
	IMAGEMANAGER->addFrameImage("EffectE1", "Resources/Images/hit.bmp", 0.0f, 0.0f, 960, 160, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("EffectE2", "Resources/Images/explode.bmp", 0.0f, 0.0f, 915, 58, 15, 1, true, RGB(255, 0, 255));

	return S_OK;
}
void EffectManager::release(void) {
	for (_viEffect = _vEffect.begin(); _viEffect != _vEffect.end(); ++_viEffect) {
		(*_viEffect)->release();
		SAFE_DELETE(*_viEffect);
	}
}

void EffectManager::update(void) {
	for (int i = 0; i < _vEffect.size(); i++) {
		_vEffect[i]->update();
		if (!_vEffect[i]->isShow()) {
			removeEffect(i);
			break;
		}
	}
}

void EffectManager::render(void) {
	_viEffect = _vEffect.begin();
	for (; _viEffect != _vEffect.end(); ++_viEffect) {
		(*_viEffect)->render();
	}
}

void EffectManager::addEffect(const char* imageName, POINT pt) {
	_viEffect = _vEffect.begin();
	Effect* effect = new Effect;
	effect->init(imageName, pt);
	_vEffect.push_back(effect);
}

void EffectManager::removeEffect(int arrNum) {
	_vEffect.erase(_vEffect.begin() + arrNum);
}
