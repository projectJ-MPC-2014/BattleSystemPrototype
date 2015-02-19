#include "Input.h"


Input::Input()
{
}


Input::~Input()
{
}


std::string Input::command()
{
	std::string command;
	std::cin >> command;
	return command;
}