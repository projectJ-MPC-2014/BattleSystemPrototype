#include<iostream>
#include "TestBattle.h"
#include "Character/Player.h"
#include "Character/Enemy.h"
#include "Selector/CUISelector.h"
#include "Selector\RandomSelector.h"

int main(){
	//-------------------------------------------��������������---------------
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
		//�L�����������Ă�����s����I�����Čv�Z���ĕ\������.���̎�,�L�����N�^���ƂɑI����@��ς���
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
			<< "���O" << "\t"
			<< "HP" << "\t"
			<< "�U" << "\t"
			<< "��" << "\t"
			<< "��" <<
			std::endl; 
	}( );
	//-------------------------------------------�����������܂�---------------

	battle.testPrint( characters );

	auto isHero = [](CharaList::value_type const &chara) { return chara->name_m == "hero"; };
	// ���C�����[�v
	//hero���������̓��[�v�𑱂���
	for(int i = 0; (*std::find_if(characters.begin(), characters.end(), isHero))->data_m.isAlive_m; ++i)
	{
		std::cout << std::endl;
		std::cout << "�^�[��:" << i + 1 << std::endl;
		characters.sort( compareAgility );

		//�e�L������,�s���I��-->�v�Z-->�\�����s��
		std::for_each( characters.begin(), characters.end(), charaAttack );
	}
}
