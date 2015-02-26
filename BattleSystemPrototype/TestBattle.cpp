#include "TestBattle.h"


void TestBattle::testPrint( CharacterList &characters )
{
	auto printStatus = []( Character *character ){
		if( character->data_m.isAlive_m ) {
			std::cout << "\t"
				<< character->data_m.name_m << "\t"
				<< character->data_m.hp_m << "\t"
				<< character->data_m.attack_m << "\t"
				<< character->data_m.magic_m << "\t"
				<< character->data_m.agility_m << std::endl;
		}
	};

	//生きてるキャラクタのステイタスを表示
	std::for_each( characters.begin(), characters.end(), printStatus );
}

void TestBattle::testAttack(
	std::string actorName,
	std::string actionName,
	std::string targetName,
	CharacterList characters)
{
	auto searchActor = [actorName](Character* chara)
	{
		return chara->data_m.name_m == actorName;
	};
	auto searchTarget = [targetName](Character* chara)
	{
		return chara->data_m.name_m == targetName;
	};
	//スキルを適用する対象を見つける
	Character *actor = characters.findIf(searchActor);
	Character *target = characters.findIf(searchTarget);
	//行動ごとの処理
	auto action = ActionFactory::get(actionName);
	if(action == nullptr) { return; }

	action->doAction(actor, target);
}