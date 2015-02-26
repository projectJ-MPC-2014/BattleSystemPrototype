#include "ConditionOfTarget.h"

bool IsNotAlly::satisfies(Character *chara)
{
	return actor_m->data_m.iff_m != chara->data_m.iff_m &&
		chara->data_m.isAlive_m;
}

bool IsAlly::satisfies(Character *chara)
{
	return actor_m->data_m.iff_m == chara->data_m.iff_m &&
		chara->data_m.isAlive_m;
}