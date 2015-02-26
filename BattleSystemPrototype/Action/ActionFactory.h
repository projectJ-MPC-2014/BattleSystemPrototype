#pragma once

#include"Attack.h"
#include"Care.h"
#include"Magic.h"
#include<string>
#include<memory>
#include<map>
#include<algorithm>

/**
*アクション名が指すアクションを生成する
*/
class ActionFactory final
{
private:
	/**文字列からアクションへの写像の型*/
	typedef std::map<std::string, std::shared_ptr<Action>> StrToAction;
	/**文字列とアクションのペアの型*/
	typedef std::pair<std::string, std::shared_ptr<Action>> StrActionPair;
private:
	/**文字列からアクションへの写像*/
	static StrToAction toAction_m;
public:
	/**
	*アクション名の指すアクションを返す
	* @param actionName アクション名
	* @return アクション名と対応するアクションへのポインタ
	*/
	static std::shared_ptr<Action> get(std::string actionName);
};

