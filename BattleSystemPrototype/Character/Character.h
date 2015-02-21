#pragma once
#include <iostream>
#include<cassert>
#include<string>
#include<list>
#include<algorithm>
#include"CharaData.h"

/**
*敵味方識別の列挙体
*/
enum class Iff:int	//Identify friend or foe
{
	/**敵味方不明*/
	UNKNOWN,
	/**プレイヤの味方*/
	FRIEND,
	/**プレイヤの敵*/
	FOE
};


class Character;
/**
*プレイヤの行動を表す構造体
*スキル名とその対象を持つ
*/
struct Selection
{
	/**スキル名*/
	std::string skillName_m;
	/**対象の名前*/
	std::string target_m;
};


/**キャラクタのリスト*/
typedef std::list<Character*> CharaList;

/**
*選択可能な対象(スキルを適用できる)のリストを得る関数
*@param attacker 行動するキャラクタ
*@param characters 全キャラクタのリスト
*@param skillName attackerが選択したスキルの名前
*@return スキルを適用できるキャラクタのリスト
*/
CharaList getAvailableTargets(
	Character*attacker,
	CharaList &characters,
	std::string skillName );


/**
*キャラクタの情報がまとめられている
*スキルごとに計算をするメソッドを持つ
*リファクタリングが必要
*/
class Character
{
protected:
	/**プレイヤにとって敵か味方か*/
	Iff iff_m;
	/**選択された行動*/
	Selection selection_m;
public:
	/**キャラクタのデータ*/
	CharaData data_m;
	/**キャラクタ名*/
	std::string name_m;
	/**キャラクタID*/
	int id_m;
public:
	/**
	*コンストラクタ
	*キャラクタの情報を設定する
	*@param name キャラクタ名
	*@param data キャラクタの数値データ
	*@param id キャラクタID
	*/
	Character(std::string name, CharaData data, int id);
	/**デストラクタ*/
	virtual ~Character() = default;
protected:
	/**
	*ダメージを受ける関数
	*@param damage 受けるダメージ(体力から引く量)
	*/
	void damage(int damage);
	/**
	*自分が回復する関数
	*@param heal 回復量 
	*/
	void heal(int heal);
public:
	/**
	*魔法攻撃をする関数
	*@param target 攻撃対象
	*/
	void magic( Character &target );
	/**
	*物理攻撃をする関数
	*@param target 攻撃対象
	*/
	void attack(Character &target);
	/**
	*相手を回復をする関数
	*@param target 回復対象
	*/
	void care( Character &target );
	/**
	*キャラクタの行動を得る関数
	*TestBattleのtestAttackで呼ばれる
	*/
	Selection getSelection();
	/**
	*キャラクタの行動選択をセットする
	*/
	void Character::select( Selection const &selection );
	/**
	*キャラクタの敵味方情報を得る
	*@return 敵味方識別列挙定数
	*/
	Iff getIff();
};

