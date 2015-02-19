#include "TestBattle.h"





TestBattle::TestBattle()
{
}


TestBattle::~TestBattle()
{
}

void TestBattle::testPrint( CharaList &characters )
{
	auto printStatus = []( Character *character ){
		if( character->data_m.isAlive_m ) {
			std::cout
				<< character->name_m << "\t"
				<< character->data_m.hp_m << "\t"
				<< character->data_m.attack_m << "\t"
				<< character->data_m.magic_m << "\t"
				<< character->data_m.agility_m <<
				std::endl;
		}
	};

	std::for_each( characters.begin(), characters.end(), printStatus );
}

void TestBattle::testScan( Character* attacker, CharaList &characters )
{

	Selection selection = attacker->select( characters );

	command_m = selection.command_m;
	target_m = selection.target_m;
}

void TestBattle::testAttack( Character* attacker, CharaList &characters )
{
	auto searchName = [this]( Character* character1 ) {
		return character1->name_m == target_m;
	};

	Character &target = **std::find_if( characters.begin(), characters.end(), searchName );

	if( command_m == "attack" ) {
		attacker->attack( target );
	}
	else if( command_m == "magic" ) {
		attacker->magic( target );
	}
	else if( command_m == "care" ) {
		attacker->care( target );
	}
	else {}
}