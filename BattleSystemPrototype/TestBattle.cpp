#include "TestBattle.h"


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

	//生きてるキャラクタのステイタスを表示
	std::for_each( characters.begin(), characters.end(), printStatus );
}



void TestBattle::testAttack( Character* attacker, CharaList &characters )
{
	std::string skillName = attacker->getSelection().skillName_m;

	auto searchName = [attacker]( Character* character1 ) {
		return character1->name_m == attacker->getSelection().target_m;
	};

	//スキルを適用する対象を見つける
	Character &target = **std::find_if( characters.begin(), characters.end(), searchName );

	//行動ごとの処理
	if( skillName == "attack" ) {
		attacker->attack( target );
	}
	else if( skillName == "magic" ) {
		attacker->magic( target );
	}
	else if( skillName == "care" ) {
		attacker->care( target );
	}
	else {}
}