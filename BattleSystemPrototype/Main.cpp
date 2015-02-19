#include<iostream>
#include<cstdio>
#include <list>
#include <algorithm>
#include <string>
#include "Character/Character.h"
#include "TestBattle.h"
#include "Character/Player.h"
#include "Character/Enemy.h"
#include "Selector/CUISelector.h"
#include "Selector\RandomSelector.h"

int main(){
	auto isFriend = []( Character* character ){ return character->getIff() == Iff::FRIEND; };
	auto isFoe = []( Character* character ){ return character->getIff() == Iff::FOE; };
	
	TestBattle battle;

	CharaList characters;
	
	Character *hero = new Player( "hero", { 100, 30, 30, 20, true }, 1 );
	Character *enemy1 = new Enemy( "enemy1", { 20, 20, 20, 10, true }, 1 );
	Character *enemy2 = new Enemy( "enemy2", { 30, 20, 30, 30, true }, 1 );
	
	Selector *cuiSelector = new CUISelector();
	Selector *randomSelector = new RandomSelector();
	auto compareAgility = []( Character *chara1, Character *chara2 ){
		return chara1->data_m.agility_m > chara2->data_m.agility_m;
	};
	auto charaAttack = [randomSelector, cuiSelector, &characters, &battle]( Character* attacker ){
		if( attacker->data_m.isAlive_m ) {
			if( attacker->name_m == "hero" ) {
				cuiSelector->select( attacker, characters );
			}
			else {
				randomSelector->select( attacker, characters );
			}
			battle.testAttack( attacker, characters );
			battle.testPrint( characters );
		}
	};
	
	characters.emplace_back( hero );
	characters.emplace_back( enemy1 );
	characters.emplace_back( enemy2 );

	[](){
		std::cout
			<< "名前" << "\t"
			<< "HP" << "\t"
			<< "攻" << "\t"
			<< "魔" << "\t"
			<< "速" <<
			std::endl; 
	}( );

	battle.testPrint( characters );

	// メインループ
	for( int i = 0; hero->data_m.isAlive_m; ++i ) {
		std::cout << std::endl;
		std::cout << "ターン:" << i + 1 << std::endl;
		characters.sort( compareAgility );
		std::for_each( characters.begin(), characters.end(), charaAttack );
	}
}