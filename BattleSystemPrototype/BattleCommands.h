#pragma once

#include <string>
#include <vector>
#include <set>



class BattleCommands
{
public:
	typedef std::vector < std::string > Commands;
	static const Commands COMMANDS_m;
	static const int NUMBER_OF_COMMANDS_m;

public:
	BattleCommands();
	~BattleCommands();
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


