#include "RandomSelector.h"

RandomSelector::RandomSelector()
{
	engine_m.seed(std::random_device()());
}

Selection RandomSelector::select(Character *actor, CharacterList characters)
{
	std::string skillName;
	std::string target;
	
	//�X�L�����������_���Ɏ擾
	random_m.param( Dist::param_type( 0, BattleCommands::getNumOfCommands() - 1 ) );
	skillName = BattleCommands::COMMANDS_m[random_m( engine_m )];
	std::cout << "command-->";
	std::cout << skillName << std::endl;

	//�Ώۂ������_���Ɏ擾
	CharacterList targets = characters.getAvailableTargets(actor, skillName);
	random_m.param(Dist::param_type(0, targets.size() - 1));
	CharacterList::iterator ite = targets.begin();
	std::advance( ite, random_m( engine_m ) );
	target = (*ite)->data_m.name_m;
	std::cout << "target-->" <<  target << std::endl;

	//�s���҂̍s���Ƃ��Đݒ�
	return{ skillName, target };
}

