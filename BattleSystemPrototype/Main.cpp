#include<iostream>
#include "TestBattle.h"
#include "Character/Player.h"
#include "Character/Enemy.h"
#include "Selector/CUISelector.h"
#include "Selector\RandomSelector.h"

int main(){
	//-------------------------------------------初期化ここから---------------
	auto isFriend = [](Character* character) { return character->getIff() == Iff::FRIEND; };
	auto isFoe = []( Character* character ){ return character->getIff() == Iff::FOE; };
	
	TestBattle battle;
	CharaList characters = {
		new Player("hero", { 100, 30, 30, 20, true }, 1),
		new Enemy("enemy1", { 20, 20, 20, 10, true }, 2),
		new Enemy("enemy2", { 30, 20, 30, 30, true }, 3),
	};
	
	Selector *cuiSelector = new CUISelector();
	Selector *randomSelector = new RandomSelector();
	auto compareAgility = []( Character *chara1, Character *chara2 ){
		return chara1->data_m.agility_m > chara2->data_m.agility_m;
	};
	auto charaAttack = [randomSelector, cuiSelector, &characters, &battle]( Character* attacker ){
		//キャラが生きていたら行動を選択して計算して表示する.この時,キャラクタごとに選択方法を変える
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

	[](){
		std::cout
			<< "名前" << "\t"
			<< "HP" << "\t"
			<< "攻" << "\t"
			<< "魔" << "\t"
			<< "速" <<
			std::endl; 
	}( );
	//-------------------------------------------初期化ここまで---------------

	battle.testPrint( characters );

	auto isHero = [](CharaList::value_type const &chara) { return chara->name_m == "hero"; };
	// メインループ
	//heroが存命中はループを続ける
	for(int i = 0; (*std::find_if(characters.begin(), characters.end(), isHero))->data_m.isAlive_m; ++i)
	{
		std::cout << std::endl;
		std::cout << "ターン:" << i + 1 << std::endl;
		characters.sort( compareAgility );

		//各キャラで,行動選択-->計算-->表示を行う
		std::for_each( characters.begin(), characters.end(), charaAttack );
	}
}
