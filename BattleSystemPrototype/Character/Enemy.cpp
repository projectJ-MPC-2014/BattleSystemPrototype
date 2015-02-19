#include "Enemy.h"

//const int Enemy::NUMBER_OF_COMMANDS = 3;
//const std::string Enemy::COMMANDS[NUMBER_OF_COMMANDS] = { "attack", "magic", "care" };

Enemy::Enemy(std::string name, CharaData data, int id)
:Character(name, data, id)
{
	iff_m = Iff::FOE;
}

