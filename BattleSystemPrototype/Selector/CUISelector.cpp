#include "CUISelector.h"

Selection CUISelector::select( Character *actor, CharacterList characters )
{
	std::string action;
	std::string target;

	//�X�L����CUI����
	auto isAction = [&action](std::string a) { return a == action; };
	std::cout << "Select command.\t" << "attack magic care\n";
	do {
		std::cout << "command-->";
		std::cin >> action;
	} while(std::none_of(BattleCommands::COMMANDS_m.begin(), BattleCommands::COMMANDS_m.end(), isAction));

	//�I���\�ȃL�����N�^�𒊏o���ĕ\��
	CharacterList targets = characters.getAvailableTargets(actor, action);
	auto print = [](Character *target) { std::cout << target->data_m.name_m << " "; };
	auto isTarget = [&target](Character* t) { return target == t->data_m.name_m; };

	std::cout << "Select target.\t";
	std::for_each(targets.begin(), targets.end(), print);
	std::cout << std::endl;

	//�^�[�Q�b�g��CUI����(���������͂���܂ŌJ��Ԃ�)
	do {
		std::cout << "target-->";
		std::cin >> target;
	} while(std::none_of(targets.begin(), targets.end(), isTarget));

	//�U���҂̍s���Ƃ��Đݒ�
	return{ action, target };
}