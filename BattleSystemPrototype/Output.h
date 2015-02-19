#pragma once

#include <iostream>
#include <string>

/**
 * 文字列出力クラス
 */
class Output
{
public:
	/**
	 * コンストラクタ
	 */
	Output();
	/**
	 * デストラクタ
	 */
	~Output();

public:
	/**
	 * 改行しない文字列出力
	 * @param message 出力する文字列
	 */
	void message( std::string message );
	/**
	 * 改行する文字列出力
	 * @param message 出力する文字列
	 */
	void messageLine( std::string message );
};

