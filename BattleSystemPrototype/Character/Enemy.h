#pragma once

#include"Character.h"
#include"../BattleCommands.h"
#include<random>
#include<list>
#include<algorithm>

/**
*�G�L�����N�^
*/
class Enemy : public Character
{
public:
	/**�R���X�g���N�^*/
	Enemy(std::string name, CharaData data, int id);
	/**�f�X�g���N�^*/
	~Enemy() = default;
public:
};
