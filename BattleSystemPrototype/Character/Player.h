#pragma once

#include<string>
#include"Character.h"
#include "../Selector/Selector.h"
#include "../Output.h"

class Player : public Character
{
public:
	Selector *selector_m;
	Output output_m;
public:
	Player( std::string name, CharaData data, int id );
	~Player() = default;
public:
	std::string selectCommand( CharaList &characters );
	std::string selectTarget( CharaList &characters, std::string skillName );
};

