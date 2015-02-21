#pragma once

#include <string>
#include <vector>
#include <set>


/**
*コマンドの集合
*コマンドの種類を全てまとめたクラス
*/
class BattleCommands
{
public:
	/**コマンドの集合の型*/
	typedef std::vector < std::string > Commands;
public:
	/**コマンドの集合*/
	static const Commands COMMANDS_m;
	/**
	*コマンドの種類数を返す
	*return コマンドの種類数
	*/
	static const int getNumOfCommands();

public:
	/**コンストラクタ*/
	BattleCommands() = default;
	/**デストラクタ*/
	~BattleCommands() = default;
public:
};

/*
class BattleCommand
{
protected:

	enum { nakamaTantai , tekiTantai ,  };

	std::string commandName_m;
	 target

public:
	BattleCommand();
	virtual ~BattleCommand();
};*/


