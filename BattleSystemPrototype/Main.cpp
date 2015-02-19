#include<iostream>
#include<cstdio>
#include <list>
#include <algorithm>
#include <string>
#include"Character.h"
#include "Parameter.h"
#include "TestBattle.h"
#include "Player.h"
#include "Enemy.h"


int main(){
	auto isFriend = []( Character* character ){ return character->getIff() == Iff::FRIEND; };
	auto isFoe = []( Character* character ){ return character->getIff() == Iff::FOE; };
	
	TestBattle battle;

	CharaList characters;
	
	Character *hero = new Player( "hero", { 100, 20, 20, 20, true }, 1 );
	Character *enemy1 = new Enemy( "enemy1", { 20, 20, 20, 10, true }, 1 );
	Character *enemy2 = new Enemy( "enemy2", { 30, 20, 30, 30, true }, 1 );
	
	auto compareAgility = []( Character *chara1, Character *chara2 ){
		return chara1->data_m.agility_m > chara2->data_m.agility_m;
	};
	auto charaAttack = [&characters, &battle]( Character* chara ){
		if( chara->data_m.isAlive_m ) {
			battle.testScan( chara, characters );
			battle.testAttack( chara, characters );
			battle.testPrint( characters );
		}
	};
	
	characters.emplace_back( hero );
	characters.emplace_back( enemy1 );
	characters.emplace_back( enemy2 );

	std::cout
		<< "–¼‘O" << "\t"
		<< "HP" << "\t"
		<< "U" <<"\t"
		<< "–‚" << "\t"
		<< "‘¬" <<
		std::endl;

	battle.testPrint( characters );

	for( int i = 0; hero->data_m.isAlive_m; ++i ) {
		std::cout << std::endl;
		std::cout << "ƒ^[ƒ“:" << i + 1 << std::endl;
		characters.sort( compareAgility );
		std::for_each( characters.begin(), characters.end(), charaAttack );
	}
	
}