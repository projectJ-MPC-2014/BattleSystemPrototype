#pragma once

#include <iostream>
#include <string>

class Output
{
public:
	Output();
	~Output();
public:
	void message( std::string message );
	void messageLine( std::string message );
};

