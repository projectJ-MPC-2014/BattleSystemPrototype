#include "Enemy.h"

Enemy::Enemy(CharaData data)
:Character(data)
{
	data_m.iff_m = Iff::FOE;
}


std::unique_ptr<Selector> Enemy::getSelector()
{
	return std::make_unique<RandomSelector>();
}
