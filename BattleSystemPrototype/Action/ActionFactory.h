#pragma once

#include"Attack.h"
#include"Care.h"
#include"Magic.h"
#include<string>
#include<memory>
#include<map>
#include<algorithm>

/**
*�A�N�V���������w���A�N�V�����𐶐�����
*/
class ActionFactory final
{
private:
	/**�����񂩂�A�N�V�����ւ̎ʑ��̌^*/
	typedef std::map<std::string, std::shared_ptr<Action>> StrToAction;
	/**������ƃA�N�V�����̃y�A�̌^*/
	typedef std::pair<std::string, std::shared_ptr<Action>> StrActionPair;
private:
	/**�����񂩂�A�N�V�����ւ̎ʑ�*/
	static StrToAction toAction_m;
public:
	/**
	*�A�N�V�������̎w���A�N�V������Ԃ�
	* @param actionName �A�N�V������
	* @return �A�N�V�������ƑΉ�����A�N�V�����ւ̃|�C���^
	*/
	static std::shared_ptr<Action> get(std::string actionName);
};

