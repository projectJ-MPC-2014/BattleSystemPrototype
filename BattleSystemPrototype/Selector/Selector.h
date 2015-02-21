#pragma once

#include "../Character/Character.h"

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
	 *		選択されたら1
	 *		選択されなかったら0
	 */
	virtual int select( Character *attacker, CharaList characters ) = 0;
};

