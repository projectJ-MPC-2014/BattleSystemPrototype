#include "Output.h"

/**
 * �R���X�g���N�^
 */
Output::Output()
{
}

/**
 * �f�X�g���N�^
 */
Output::~Output()
{
}

/**
 * ���s���Ȃ�������o��
 * @param message �o�͂��镶����
 */
void Output::message( std::string message )
{
	std::cout << message;
}

/**
 * ���s���镶����o��
 * @param message �o�͂��镶����
 */
void Output::messageLine( std::string message )
{
	std::cout << message << std::endl;
}