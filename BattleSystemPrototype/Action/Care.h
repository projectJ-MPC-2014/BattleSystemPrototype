#pragma once
#include "Action.h"

/**
*回復魔法の計算をするクラス
*/
class Care : public Action
{
public:
	/**
	*回復魔法を適用してキャラクタのステータスを計算する
	* @param actor 回復魔法を発動するキャラクタ
	* @param target 回復魔法を受けるキャラクタ
	*/
	void doAction(Character *actor, Character *target)override;
};

