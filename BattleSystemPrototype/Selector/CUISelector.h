#pragma once

#include <iostream>
#include <string>
#include "Selector.h"
#include"../BattleCommands.h"

/**
 * �L�����N�^�̍s����CUI����I������N���X
 */
class CUISelector : public Selector
{
public:
	/** �R���X�g���N�^ */
	CUISelector() = default;
	/** �f�X�g���N�^ */
	~CUISelector() = default;
public:
	/**
	 * �w�肳�ꂽ�L�����N�^�[�̍s����CUI�őI������
	 * @param attacker �U����
	 * @param characters �S�L�����N�^�[
	 * @return �I�����ꂽ���ǂ���
	 *		�I�����ꂽ��1
	 *		�I������Ȃ�������0
	 */
	Selection select( Character *attacker, CharacterList characters )override;
};

