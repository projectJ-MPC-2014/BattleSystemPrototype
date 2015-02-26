#pragma once
#include<cassert>
#include<string>
#include<algorithm>
#include<memory>
#include"CharaData.h"
#include"Selection.h"
#include"../Selector/Selector.h"

class Selector;
class CharacterList;

/**
*キャラクタの情報がまとめられている
*スキルごとに計算をするメソッドを持つ
*リファクタリングが必要
*/
class Character
{
protected:
	/**選択された行動*/
	Selection selection_m;
public:
	/**キャラクタのデータ*/
	CharaData data_m;	
public:
	/**
	*コンストラクタ
	*キャラクタの情報を設定する
	*@param name キャラクタ名
	*@param data キャラクタの数値データ
	*@param id キャラクタID
	*/
	Character(CharaData data);
	/**デストラクタ*/
	virtual ~Character() = default;
public:
	/**
	*キャラクタの行動を得る関数
	*TestBattleのtestAttackで呼ばれる
	*/
	Selection getSelection();
	/**
	*キャラクタごとの行動選択の仕方を表すクラスを生成する
	*/
	virtual std::unique_ptr<Selector> getSelector() = 0;
};

