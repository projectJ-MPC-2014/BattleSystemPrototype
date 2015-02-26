#pragma once

#include"../Character/Character.h"

/**
*�L�����N�^�̍s����\���C���^�[�t�F�[�X
*/
class Action
{
public:
	/**�R���X�g���N�^*/
	Action() = default;
	/**�f�X�g���N�^*/
	virtual ~Action() = default;
public:
	/**
	*�A�N�V���������s����
	* @param actor �s��������L�����N�^
	* @param target �s�����󂯂�L�����N�^
	*/
	virtual void doAction(Character *actor, Character *target) = 0;
};

