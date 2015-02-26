#pragma once
#include "Action.h"

/**
*魔法攻撃の計算をするクラス
*/
class Magic :
	public Action
{
public:
	/**
	*魔法攻撃をしてキャラクタのステータスを計算する
	* @param actor 魔法攻撃をするキャラクタ
	* @param target 魔法攻撃を受けるキャラクタ
	*/
	void doAction(Character *actor, Character *target)override;
};

