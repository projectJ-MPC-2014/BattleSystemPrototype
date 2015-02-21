#include "Character.h"

CharaList getAvailableTargets(
	Character*attacker,
	CharaList &characters,
	std::string skillName )
{
	CharaList targets;

	//コマンドごとに選択可能な攻撃相手を抽出したリストを返す
	if( skillName == "attack" ) {
		auto isEnemy = [attacker]( Character* enemy ){
			return attacker->getIff() != enemy->getIff() &&
					enemy->data_m.isAlive_m;
		};
		targets.resize( std::count_if( characters.begin(), characters.end(), isEnemy ) );
		std::copy_if( characters.begin(), characters.end(), targets.begin(), isEnemy );
	}
	else if( skillName == "magic" ) {
		auto isEnemy = [attacker]( Character* enemy ){
			return attacker->getIff() != enemy->getIff() &&
				enemy->data_m.isAlive_m;
		};
		targets.resize( std::count_if( characters.begin(), characters.end(), isEnemy ) );
		std::copy_if( characters.begin(), characters.end(), targets.begin(), isEnemy );
	}
	else if( skillName == "care" ) {
		auto isAlly = [attacker]( Character* ally ){
			return attacker->getIff() == ally->getIff() &&
				ally->data_m.isAlive_m;
		};
		targets.resize( std::count_if( characters.begin(), characters.end(), isAlly ) );
		std::copy_if( characters.begin(), characters.end(), targets.begin(), isAlly );

	}

	return targets;
}


void Character::attack(Character &target)
{
	target.damage(data_m.attack_m);
}

void Character::magic( Character &target )
{
	target.damage( data_m.magic_m );
}

void Character::care( Character &target )
{
	target.heal( data_m.magic_m );
}

void Character::damage(int damage)
{
	if ((data_m.hp_m -= damage) <= 0){
		data_m.hp_m = 0;
		data_m.isAlive_m = false;
		std::cout << name_m << "は しんだ！\a\a\a" << std::endl;
	}
}

void Character::heal( int heal )
{
	if( data_m.isAlive_m ) {
		data_m.hp_m += heal;
	}
}

Iff Character::getIff()
{
	return iff_m;
}

void Character::select( Selection const &selection )
{
	selection_m = selection;
}



Character::Character(std::string name, CharaData data, int id)
:name_m(name), data_m(data), id_m(id)
{
	assert(data.isAlive_m == true &&
		data_m.hp_m > 0 &&
		data_m.attack_m > 0 &&
		data_m.isAlive_m == true);
}

Selection Character::getSelection()
{
	return selection_m;
}
