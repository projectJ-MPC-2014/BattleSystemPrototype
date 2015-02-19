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
	std::string command_m;
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
public:
	CharaData data_m;
	std::string name_m;
	int id_m;
public:
	Character(std::string name, CharaData data, int id);
	virtual ~Character();
protected:
	void damage(int damage);
	void heal(int heal);
	

public:
	void magic( Character &target );
	void attack(Character &target);
	void care( Character &target );
	virtual std::string selectTarget( CharaList &characters, std::string skillName) = 0;
	virtual std::string selectCommand(CharaList &characters) = 0;
	Selection select( CharaList &characters );
	Iff getIff();
};

