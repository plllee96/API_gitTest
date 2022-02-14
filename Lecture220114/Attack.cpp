#include "Stdafx.h"
#include "MainGame.h"

void MainGame::attack(void) {
	for (int i = 0; i < _em->getMinion().size(); i++) {
		if ( _em->getMinion()[i]->getRndAttackDelay() <
			TIMEMANAGER->getWorldTime() - _em->getMinion()[i]->getWorldAttackTimeCount()) {

			float x = _em->getMinion()[i]->getRC().left + (_em->getMinion()[i]->getRC().right - _em->getMinion()[i]->getRC().left) / 2;
			float y = _em->getMinion()[i]->getRC().top + (_em->getMinion()[i]->getRC().bottom - _em->getMinion()[i]->getRC().top) / 2;
			float angle = MY_UTIL::getAngle(x, y, 
				_rocket->getRect().left + (_rocket->getRect().right - _rocket->getRect().left) / 2,
				_rocket->getRect().top + +(_rocket->getRect().bottom - _rocket->getRect().top) / 2);

			_em->getMinion()[i]->getEnemyBullet()->fire(x, y, angle);
			_em->getMinion()[i]->setWorldAttackTimeCount(TIMEMANAGER->getWorldTime());
		}
	}
}
