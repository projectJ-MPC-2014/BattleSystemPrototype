#include "Output.h"

/**
 * コンストラクタ
 */
Output::Output()
{
}

/**
 * デストラクタ
 */
Output::~Output()
{
}

/**
 * 改行しない文字列出力
 * @param message 出力する文字列
 */
void Output::message( std::string message )
{
	std::cout << message;
}

/**
 * 改行する文字列出力
 * @param message 出力する文字列
 */
void Output::messageLine( std::string message )
{
	std::cout << message << std::endl;
}