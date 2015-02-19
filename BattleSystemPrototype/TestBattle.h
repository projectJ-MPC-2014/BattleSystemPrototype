#pragma once

#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include "Character/Character.h"


class TestBattle
{
public:
	TestBattle() = default;
	~TestBattle() = default;
public:
	void testPrint( CharaList &characters );
	void testAttack( Character* attacker, CharaList &characters );
};

