#pragma once

#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include"Action\ActionFactory.h"
#include "Character/Character.h"

/**
*�e�X�g�p�̃o�g���V�X�e��
*/
class TestBattle
{
public:
	/**�R���X�g���N�^*/
	TestBattle() = default;
	/**�f�X�g���N�^*/
	~TestBattle() = default;
public:
	/**�S�L�����N�^�̃X�e�[�^�X��\��*/
	void testPrint(CharacterList &characters);
	/**
	*attacker�̍s����I����,�s�����Ƃ̏���������
	*@param actorName �s���Җ�
	*@param actionName �s����
	*@param targetName �Ώۂ̖��O
	*@oaram characters �S�L�����N�^�̃��X�g
	*/
	void testAttack(
		std::string actorName,
		std::string actionName,
		std::string targetName,
		CharacterList characters);
};
