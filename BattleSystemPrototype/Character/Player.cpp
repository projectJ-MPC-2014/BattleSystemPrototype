#include "Player.h"


Player::Player(std::string name, CharaData data, int id)
	:Character(name, data, id)
{
	iff_m = Iff::FRIEND;
}

