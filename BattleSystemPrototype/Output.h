#pragma once

#include <iostream>
#include <string>

/**
 * ������o�̓N���X
 */
class Output
{
public:
	Output();
	~Output();
public:
	void message( std::string message );
	void messageLine( std::string message );
};

