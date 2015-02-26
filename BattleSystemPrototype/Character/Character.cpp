#include "Character.h"

Character::Character(CharaData data)
	:data_m(data)
{
	assert(data_m.hp_m > 0 &&
		data_m.attack_m > 0 &&
		data_m.isAlive_m);
}

Selection Character::getSelection()
{
	return selection_m;
}
