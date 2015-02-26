#include "Care.h"

void Care::doAction(Character *actor, Character *target)
{
	if(target->data_m.isAlive_m) {
		target->data_m.hp_m += actor->data_m.magic_m;
	}
}
