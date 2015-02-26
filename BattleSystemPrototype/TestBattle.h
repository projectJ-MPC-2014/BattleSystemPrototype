#pragma once

#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include"Action\ActionFactory.h"
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
	void testPrint(CharacterList &characters);
	/**
	*attackerの行動を選択し,行動ごとの処理をする
	*@param actorName 行動者名
	*@param actionName 行動名
	*@param targetName 対象の名前
	*@oaram characters 全キャラクタのリスト
	*/
	void testAttack(
		std::string actorName,
		std::string actionName,
		std::string targetName,
		CharacterList characters);
};
