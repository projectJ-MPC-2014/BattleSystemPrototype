#pragma once

#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include "Character.h"


class TestBattle
{
private:
	std::string command_m;
	std::string target_m;
public:
	TestBattle();
	~TestBattle();
public:
	void testPrint( CharaList &characters );
	void testScan( Character* attacker, CharaList &characters );
	void testAttack( Character* attacker, CharaList &characters );
};

