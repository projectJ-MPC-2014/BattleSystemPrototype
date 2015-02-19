#pragma once
#include <iostream>
#include<cassert>
#include<string>
#include<list>
#include<algorithm>
#include"CharaData.h"

enum class Iff:int	//Identify friend or foe
{
	UNKNOWN,
	FRIEND,
	FOE
};

class Character;

struct Selection
{
	std::string skillName_m;
	std::string target_m;
};

typedef std::list<Character*> CharaList;

CharaList getAvailableTargets(
	Character*attacker,
	CharaList &characters,
	std::string skillName );

class Character
{
protected:
	Iff iff_m;
	Selection selection_m;
public:
	CharaData data_m;
	std::string name_m;
	int id_m;
public:
	Character(std::string name, CharaData data, int id);
	virtual ~Character() = default;
protected:
	void damage(int damage);
	void heal(int heal);
public:
	void magic( Character &target );
	void attack(Character &target);
	void care( Character &target );
	Selection getSelection();
	void Character::select( Selection const &selection );
	Iff getIff();
};

