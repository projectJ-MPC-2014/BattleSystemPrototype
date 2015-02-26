#pragma once

#include "../Character/Character.h"
#include "../CharacterList.h"

class Character;
class CharacterList;

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
	 *		�I�����ꂽ�� �I�����ꂽ�I��
	 *		�I������Ȃ������� Selection::nullSelection()
	 */
	virtual Selection select(Character *actor, CharacterList characters) = 0;
};


