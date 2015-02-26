#pragma once

#include"../Character/Character.h"

class Character;

/**
*行動選択者が選択した行動のターゲットの条件の抽象クラス
*/
class ConditionOfTarget
{
protected:
	/**行動選択キャラクタのポインタ*/
	Character *actor_m;
public:
	/**行動選択者を設定する引数付きコンストラクタ*/
	ConditionOfTarget(Character *actor) :actor_m(actor) {}
	/**コピーコンストラクタ*/
	ConditionOfTarget(ConditionOfTarget const &) = default;
	/**デストラクタ*/
	virtual~ConditionOfTarget() = default;
protected:
	/**
	*条件を渡されたキャラクタが条件を満たす時真を返す
	* @param chara 判定すべきキャラクタ
	* @return charaが条件を満たす時true,そうでない時false
	*/
	virtual bool satisfies(Character *chara) = 0;
public:
	/**
	*派生クラスに()演算子を提供する
	*条件を渡されたキャラクタが条件を満たす時真を返す
	* @param chara 判定すべきキャラクタ
	* @return charaが条件を満たす時true,そうでない時false
	*/
	bool operator()(Character *chara)
	{
		return satisfies(chara);
	}
};

/**
*そのキャラクタが行動選択者の味方でないという条件を表すクラス
*/
class IsNotAlly : public ConditionOfTarget
{
public:
	/**行動選択者を設定する引数付きコンストラクタ*/
	IsNotAlly(Character *actor):ConditionOfTarget(actor) {}
	/**コピーコンストラクタ*/
	IsNotAlly(IsNotAlly const &) = default;
	/**デストラクタ*/
	virtual~IsNotAlly() = default;
protected:
	/**
	*そのキャラクタが行動選択者の味方でない時真を返す
	* @param chara 判定すべきキャラクタ
	* @return 味方でない時true,味方である時false
	*/
	bool satisfies(Character *chara)override;
};

/**
*そのキャラクタが行動選択者の味方であるという条件を表すクラス
*/
class IsAlly : public ConditionOfTarget
{
public:
	/**行動選択者を設定する引数付きコンストラクタ*/
	IsAlly(Character *actor) :ConditionOfTarget(actor) {}
	/**コピーコンストラクタ*/
	IsAlly(IsAlly const &) = default;
	/**デストラクタ*/
	virtual~IsAlly() = default;
protected:
	/**
	*そのキャラクタが行動選択者の味方である時真を返す
	* @param chara 判定すべきキャラクタ
	* @return 味方の時true,味方でない時false
	*/
	bool satisfies(Character *chara)override;
};
