#pragma once

#include <string>
#include <vector>
#include <set>


/**
*�R�}���h�̏W��
*�R�}���h�̎�ނ�S�Ă܂Ƃ߂��N���X
*/
class BattleCommands
{
public:
	/**�R�}���h�̏W���̌^*/
	typedef std::vector < std::string > Commands;
public:
	/**�R�}���h�̏W��*/
	static const Commands COMMANDS_m;
	/**
	*�R�}���h�̎�ސ���Ԃ�
	*return �R�}���h�̎�ސ�
	*/
	static const int getNumOfCommands();

public:
	/**�R���X�g���N�^*/
	BattleCommands() = default;
	/**�f�X�g���N�^*/
	~BattleCommands() = default;
public:
};

/*
class BattleCommand
{
protected:

	enum { nakamaTantai , tekiTantai ,  };

	std::string commandName_m;
	 target

public:
	BattleCommand();
	virtual ~BattleCommand();
};*/


