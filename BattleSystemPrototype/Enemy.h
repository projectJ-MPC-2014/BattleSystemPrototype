#pragma once

#include"Character.h"
#include"BattleCommands.h"
#include<random>
#include<list>
#include<algorithm>

class Enemy : public Character
{
private:
	typedef std::uniform_int_distribution<> Dist;
	//static const int NUMBER_OF_COMMANDS = 3;
	std::random_device seed_m;
	std::mt19937 engine_m;
	Dist random_m;
	//static const std::string COMMANDS[NUMBER_OF_COMMANDS];
public:
	Enemy(std::string name, CharaData data, int id);
	~Enemy();
public:
	std::string selectCommand(CharaList &characters);
	std::string selectTarget( CharaList &characters, std::string skillName );
};