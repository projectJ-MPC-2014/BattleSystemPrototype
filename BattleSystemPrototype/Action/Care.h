#pragma once
#include "Action.h"

/**
*�񕜖��@�̌v�Z������N���X
*/
class Care : public Action
{
public:
	/**
	*�񕜖��@��K�p���ăL�����N�^�̃X�e�[�^�X���v�Z����
	* @param actor �񕜖��@�𔭓�����L�����N�^
	* @param target �񕜖��@���󂯂�L�����N�^
	*/
	void doAction(Character *actor, Character *target)override;
};

