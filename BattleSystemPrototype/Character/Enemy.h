#pragma once

#include"Character.h"
#include"../BattleCommands.h"
#include<random>
#include<list>
#include<algorithm>

class Enemy : public Character
{
private:
	
public:
	Enemy(std::string name, CharaData data, int id);
	~Enemy() = default;
public:
};
