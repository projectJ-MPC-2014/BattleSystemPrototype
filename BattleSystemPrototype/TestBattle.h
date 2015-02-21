#pragma once

#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include "Character/Character.h"

/**
*テスト用のバトルシステム
*/
class TestBattle
{
public:
	/**コンストラクタ*/
	TestBattle() = default;
	/**デストラクタ*/
	~TestBattle() = default;
public:
	/**全キャラクタのステータスを表示*/
	void testPrint(CharaList &characters);
	/**
	*attackerの行動を選択し,行動ごとの処理をする
	*@param attacker 行動者
	*@oaram characters 全キャラクタのリスト
	*/
	void testAttack(Character* attacker, CharaList &characters);
};

