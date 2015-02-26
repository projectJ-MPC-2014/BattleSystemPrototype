#include "Player.h"


Player::Player(CharaData data)
	:Character(data)
{
	data_m.iff_m = Iff::FRIEND;
}

std::unique_ptr<Selector> Player::getSelector()
{
	return std::make_unique<CUISelector>();
}
