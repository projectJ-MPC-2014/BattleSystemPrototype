#pragma once
#include "Action.h"

/**
*���@�U���̌v�Z������N���X
*/
class Magic :
	public Action
{
public:
	/**
	*���@�U�������ăL�����N�^�̃X�e�[�^�X���v�Z����
	* @param actor ���@�U��������L�����N�^
	* @param target ���@�U�����󂯂�L�����N�^
	*/
	void doAction(Character *actor, Character *target)override;
};

