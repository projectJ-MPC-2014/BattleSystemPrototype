#pragma once

#include <iostream>
#include <string>

/**
 * ������o�̓N���X
 */
class Output
{
public:
	/**
	 * �R���X�g���N�^
	 */
	Output();
	/**
	 * �f�X�g���N�^
	 */
	~Output();

public:
	/**
	 * ���s���Ȃ�������o��
	 * @param message �o�͂��镶����
	 */
	void message( std::string message );
	/**
	 * ���s���镶����o��
	 * @param message �o�͂��镶����
	 */
	void messageLine( std::string message );
};

