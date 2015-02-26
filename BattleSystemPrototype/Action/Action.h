#pragma once

#include"../Character/Character.h"

/**
*キャラクタの行動を表すインターフェース
*/
class Action
{
public:
	/**コンストラクタ*/
	Action() = default;
	/**デストラクタ*/
	virtual ~Action() = default;
public:
	/**
	*アクションを実行する
	* @param actor 行動をするキャラクタ
	* @param target 行動を受けるキャラクタ
	*/
	virtual void doAction(Character *actor, Character *target) = 0;
};

