#pragma once

#include<string>

/**
*�v���C���̍s����\���\����
*�X�L�����Ƃ��̑Ώۂ�����
*/
struct Selection
{
	/**�X�L����*/
	std::string action_m;
	/**�Ώۂ̖��O*/
	std::string target_m;
	/**�����ȍs���I���𓾂�*/
	static Selection nullSelection()
	{
		return{ "", "" };
	}
	bool operator==(Selection const &selection)
	{
		return action_m == selection.action_m &&
			target_m == selection.target_m;
	}
	bool operator!=(Selection const &selection)
	{
		return !operator==(selection);
	}
};
