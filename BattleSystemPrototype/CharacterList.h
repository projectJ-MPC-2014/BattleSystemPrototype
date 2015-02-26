#pragma once

#include<list>
#include"Character\Character.h"
#include"Action\ConditionOfTarget.h"

class Character;

/**
* キャラクタをリストでまとめたラッパクラス
*/
class CharacterList
{
private:
	/**キャラクタリストの型*/
	typedef std::list<Character*> CharaList_t;
public:
	/**イテレータの型*/
	typedef std::list<Character*>::iterator iterator;
private:
	/**キャラクタリスト本体*/
	CharaList_t characters_m;
private:
	/**
	*行動選択者の選択した行動を適用できる条件を満たす対象をキャラクタリストから抜き出してリストにして返す
	* @param condition 行動を適用できる条件,for_eachに渡す関数オブジェクト
	* @return 対象をまとめたリスト
	*/
	template<class Condition>
	CharacterList createTargets(Condition &condition)
	{
		CharacterList targets;
		
		targets.characters_m.resize(
			std::count_if(characters_m.begin(), characters_m.end(), condition));
		std::copy_if(
			characters_m.begin(), characters_m.end(), targets.begin(), condition);
		
		return targets;
	}

public:
	/**
	*選択可能な対象(スキルを適用できる)のリストを得る関数
	*@param actor 行動するキャラクタ
	*@param action actorが選択したスキルの名前
	*@return スキルを適用できるキャラクタのリスト
	*/
	CharacterList getAvailableTargets(
		Character*actor, std::string action);
	/**
	*素早い順に並び替える
	*/
	void sort();
	/**
	*リストにキャラクタを挿入する
	*/
	void insert(Character *character);
	/**
	*先頭のイテレータを返す
	* @return 先頭のイテレータ
	*/
	iterator begin();
	/**
	*末尾のイテレータを返す
	* @return 末尾のイテレータ
	*/
	iterator end();
	/**
	*条件を満たすキャラクタを検索してキャラクタクラスのポインタを返す
	* @paaram 条件(関数オブジェクト)
	* @return 条件を満たすキャラクタが見つからない時 nullptr, 見つかった時 そのキャラクタへのポインタ
	*/
	template<typename Condition>
	Character *findIf(Condition condition)
	{
		auto found = std::find_if(
			characters_m.begin(), characters_m.end(), condition);
		return found == characters_m.end() ? nullptr : *found;
	}

	//void erase(iterator first, iterator last);
	/**
	*リストの要素数を返す
	* @return リストの要素数
	*/
	size_t size()const;
};

