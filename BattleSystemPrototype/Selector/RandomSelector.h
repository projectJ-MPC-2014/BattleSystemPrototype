#pragma once

#include <random>
#include<iostream>
#include "Selector.h"
#include "../BattleCommands.h"


/**
*�����ŃL�����N�^�̍s�������肷��N���X
*/
class RandomSelector :public Selector
{
public:
	/**��l���z�̌^*/
	typedef std::uniform_int_distribution<> Dist;
	/**�A�������̃G���W��*/
	std::mt19937 engine_m;
	/**��l���z�̗���*/
	Dist random_m;
public:
	/**
	*�R���X�g���N�^
	*�A���G���W���̃V�[�h��ݒ肷��
	*/
	RandomSelector();
	/**�f�X�g���N�^*/
	~RandomSelector() = default;
public:
	/**
	 * �w�肳�ꂽ�L�����N�^�[�̍s���𗐐��őI������
	 * @param attacker �U����
	 * @param characters �S�L�����N�^�[
	 * @return �I�����ꂽ���ǂ���
	 *		�I�����ꂽ��1
	 *		�I������Ȃ�������0
	 */
	Selection select( Character *attacker, CharacterList characters )override;
};

