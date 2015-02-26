#include<iostream>
#include "TestBattle.h"
#include "Character/Player.h"
#include "Character/Enemy.h"
#include "Selector/CUISelector.h"
#include "Selector/RandomSelector.h"

int main(){
	//-------------------------------------------��������������---------------
	TestBattle battle;
	CharacterList characters;

	//��X�f�[�^�x�[�X����̎擾�ɂȂ�
	characters.insert(new Player(CharaData{ 1, "hero", 100, 30, 30, 20, true, Iff::FRIEND, }));
	characters.insert(new Enemy(CharaData{ 2, "enemy1", 70, 15, 20, 30, true, Iff::FOE, }));
	characters.insert(new Enemy(CharaData{ 3, "enemy2", 150, 20, 15, 10, true, Iff::FOE, }));
	
	//-------------------------------------------�����������܂�---------------

	std::cout << "Buttle begins!\n\t���O\tHP\t�U\t��\t��" << std::endl;
	battle.testPrint(characters);

	auto heroIsAlive = [&characters]()
	{
		auto searchHero = [](Character* chara) { return chara->data_m.name_m == "hero"; };
		return characters.findIf(searchHero)->data_m.isAlive_m;
	};
	// ���C�����[�v
	//hero���������̓��[�v�𑱂���
	int turnCount = 0;
	while(heroIsAlive()) {
		characters.sort();
		//�e�L������,�s���I��-->�v�Z-->�\�����s��
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
