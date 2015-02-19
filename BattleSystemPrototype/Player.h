#pragma once

#include<string>
#include"Character.h"
#include "Input.h"
#include "Output.h"

class Player : public Character
{
public:
	Input input_m;
	Output output_m;
public:
	Player(std::string name, CharaData data, int id);
	~Player();
public:
	std::string selectCommand(CharaList &characters);
	std::string selectTarget( CharaList &characters, std::string skillName );
};

