#pragma once

#include <iostream>
#include <string>
#include "Selector.h"
#include"../BattleCommands.h"

/**
 * キャラクタの行動をCUIから選択するクラス
 */
class CUISelector : public Selector
{
public:
	/** コンストラクタ */
	CUISelector() = default;
	/** デストラクタ */
	~CUISelector() = default;
public:
	/**
	 * 指定されたキャラクターの行動をCUIで選択する
	 * @param attacker 攻撃者
	 * @param characters 全キャラクター
	 * @return 選択されたかどうか
	 *		選択されたら1
	 *		選択されなかったら0
	 */
	Selection select( Character *attacker, CharacterList characters )override;
};

