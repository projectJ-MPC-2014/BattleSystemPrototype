#pragma once

#include <iostream>
#include <string>

/**
 * 文字列出力クラス
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

