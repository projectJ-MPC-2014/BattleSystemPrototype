#pragma once

#include <iostream>
#include <string>
#include <list>
#include <algorithm>
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
	void testPrint(CharaList &characters);
	/**
	*attacker�̍s����I����,�s�����Ƃ̏���������
	*@param attacker �s����
	*@oaram characters �S�L�����N�^�̃��X�g
	*/
	void testAttack(Character* attacker, CharaList &characters);
};

