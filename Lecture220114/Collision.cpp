#include "Stdafx.h"
#include "MainGame.h"

void MainGame::collision(void) {
	for (int i = 0; i < _rocket->getMissile()->getBullet().size(); i++) {
		for (int j = 0; j < _em->getMinion().size(); j++) {
			RECT rc;
			if (IntersectRect(&rc, &(_rocket->getMissile()->getBullet()[i].rc), &CollisionAreaResize(_em->getMinion()[j]->getRC(), 40, 30))) {
				_rocket->removeMissile(i);
				_em->removeMinion(j);
				_efm->addEffect("EffectE1", { rc.left, rc.top });
				break;
			}
		}
	}
	for (int i = 0; i < _rocket->getMissileM1()->getBullet().size(); i++) {
		for (int j = 0; j < _em->getMinion().size(); j++) {
			RECT rc;
			if (IntersectRect(&rc, &(_rocket->getMissileM1()->getBullet()[i].rc), &CollisionAreaResize(_em->getMinion()[j]->getRC(), 40, 30))) {
				_rocket->removeMissileM1(i);
				_em->removeMinion(j);
				_efm->addEffect("EffectE1", { rc.left, rc.top });
				break;
			}
		}
	}
	for (int i = 0; i < _rocket->getBeam()->getBullet().size(); i++) {
		for (int j = 0; j < _em->getMinion().size(); j++) {
			RECT rc;
			if (IntersectRect(&rc, &(_rocket->getBeam()->getBullet()[i].rc), &CollisionAreaResize(_em->getMinion()[j]->getRC(), 40, 30))) {
				_em->removeMinion(j);
				_efm->addEffect("EffectE2", { rc.left, rc.top });
				break;
			}
		}
	}
}
