#include "Magic.h"

void Magic::doAction(Character *actor, Character *target)
{
	if((target->data_m.hp_m -= actor->data_m.magic_m) <= 0) {
		target->data_m.hp_m = 0;
		target->data_m.isAlive_m = false;
	}
}
