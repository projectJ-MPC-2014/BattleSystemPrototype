#pragma once

#include <random>
#include<iostream>
#include "Selector.h"
#include "../BattleCommands.h"


/**
*乱数でキャラクタの行動を決定するクラス
*/
class RandomSelector :public Selector
{
public:
	/**一様分布の型*/
	typedef std::uniform_int_distribution<> Dist;
	/**連数生成のエンジン*/
	std::mt19937 engine_m;
	/**一様分布の乱数*/
	Dist random_m;
public:
	/**
	*コンストラクタ
	*連数エンジンのシードを設定する
	*/
	RandomSelector();
	/**デストラクタ*/
	~RandomSelector() = default;
public:
	/**
	 * 指定されたキャラクターの行動を乱数で選択する
	 * @param attacker 攻撃者
	 * @param characters 全キャラクター
	 * @return 選択されたかどうか
	 *		選択されたら1
	 *		選択されなかったら0
	 */
	Selection select( Character *attacker, CharacterList characters )override;
};

