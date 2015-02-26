#pragma once

#include "../Character/Character.h"
#include "../CharacterList.h"

class Character;
class CharacterList;

/**
 * コマンドを選択するインターフェイス
 */
class Selector
{
public:
	/** コンストラクタ */
	Selector() = default;
	/** デストラクタ */
	virtual ~Selector() = default;
public:
	/**
	 * 指定されたキャラクターの行動を選択する
	 * @param attacker 攻撃者
	 * @param characters 全キャラクター
	 * @return 選択されたかどうか
	 *		選択されたら 選択された選択
	 *		選択されなかったら Selection::nullSelection()
	 */
	virtual Selection select(Character *actor, CharacterList characters) = 0;
};


