#pragma once

#include"Iff.h"

/**
*キャラクタの数値データをまとめた構造体
*/
struct CharaData
{
	/**キャラクタID*/
	int id_m;
	/**キャラクタ名*/
	std::string name_m;
	/**体力*/
	int hp_m;
	/**攻撃力*/
	int attack_m;
	/**魔力*/
	int magic_m;
	/**敏捷性*/
	int agility_m;
	/**
	*生存フラグ
	*hpが0より大きい時に真
	*/
	bool isAlive_m;
	/**プレイヤにとって敵か味方か*/
	Iff iff_m;
	};

