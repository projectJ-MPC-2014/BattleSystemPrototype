#include<iostream>
#include "TestBattle.h"
#include "Character/Player.h"
#include "Character/Enemy.h"
#include "Selector/CUISelector.h"
#include "Selector/RandomSelector.h"

int main(){
	//-------------------------------------------初期化ここから---------------
	TestBattle battle;
	CharacterList characters;

	//後々データベースからの取得になる
	characters.insert(new Player(CharaData{ 1, "hero", 100, 30, 30, 20, true, Iff::FRIEND, }));
	characters.insert(new Enemy(CharaData{ 2, "enemy1", 70, 15, 20, 30, true, Iff::FOE, }));
	characters.insert(new Enemy(CharaData{ 3, "enemy2", 150, 20, 15, 10, true, Iff::FOE, }));
	
	//-------------------------------------------初期化ここまで---------------

	std::cout << "Buttle begins!\n\t名前\tHP\t攻\t魔\t速" << std::endl;
	battle.testPrint(characters);

	auto heroIsAlive = [&characters]()
	{
		auto searchHero = [](Character* chara) { return chara->data_m.name_m == "hero"; };
		return characters.findIf(searchHero)->data_m.isAlive_m;
	};
	// メインループ
	//heroが存命中はループを続ける
	int turnCount = 0;
	while(heroIsAlive()) {
		characters.sort();
		//各キャラで,行動選択-->計算-->表示を行う
		auto doActorsTurn = [&battle, &characters](Character *actor)
		{
			if(actor->data_m.isAlive_m) {
				std::cout << actor->data_m.name_m + "\'s turn." << std::endl;
				auto selector = actor->getSelector();
				Selection selection;
				do {
					selection = selector->select(actor, characters);
				} while(selection == Selection::nullSelection());

				battle.testAttack(actor->data_m.name_m, selection.action_m, selection.target_m, characters);
				battle.testPrint(characters);
			}
		};
		std::for_each(characters.begin(), characters.end(), doActorsTurn);
	}
}
