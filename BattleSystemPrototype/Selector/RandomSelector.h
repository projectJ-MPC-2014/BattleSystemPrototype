#pragma once

#include <random>
#include "Selector.h"
#include "../BattleCommands.h"

class RandomSelector :public Selector
{
public:
	typedef std::uniform_int_distribution<> Dist;

	std::random_device seed_m;
	std::mt19937 engine_m;
	Dist random_m;
public:
	RandomSelector();
	~RandomSelector() = default;
public:
	int select( Character *attacker, CharaList characters );
};

