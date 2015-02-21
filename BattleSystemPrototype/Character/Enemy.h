#pragma once

#include"Character.h"
#include"../BattleCommands.h"
#include<random>
#include<list>
#include<algorithm>

/**
*敵キャラクタ
*/
class Enemy : public Character
{
public:
	/**コンストラクタ*/
	Enemy(std::string name, CharaData data, int id);
	/**デストラクタ*/
	~Enemy() = default;
public:
};
