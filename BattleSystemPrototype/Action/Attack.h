#pragma once

#include"Action.h"

/**
*物理攻撃の計算をするクラス
*/
class Attack :public Action
{
public:
	/**
	*物理攻撃をしてキャラクタのステータスを計算する
	* @param actor 物理攻撃をするキャラクタ
	* @param target 物理攻撃を受けるキャラクタ
	*/
	void doAction(Character *actor, Character *target)override;
};

