#pragma once

#include <set>

class CommandList
{
public:
	/**コマンドの集合*/
	std::set<std::string> command_m;
public:
	/**コンストラクタ*/
	CommandList() = default;
	/**デストラクタ*/
	~CommandList() = default;
};

