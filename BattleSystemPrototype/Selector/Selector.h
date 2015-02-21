#pragma once

#include "../Character/Character.h"

/**
 * �R�}���h��I������C���^�[�t�F�C�X
 */
class Selector
{
public:
	/** �R���X�g���N�^ */
	Selector() = default;
	/** �f�X�g���N�^ */
	virtual ~Selector() = default;

public:
	/**
	 * �w�肳�ꂽ�L�����N�^�[�̍s����I������
	 * @param attacker �U����
	 * @param characters �S�L�����N�^�[
	 * @return �I�����ꂽ���ǂ���
	 *		�I�����ꂽ��1
	 *		�I������Ȃ�������0
	 */
	virtual int select( Character *attacker, CharaList characters ) = 0;
};

