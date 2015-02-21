#pragma once

/**
*キャラクタの数値データをまとめた構造体
*/
struct CharaData
{
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
};

