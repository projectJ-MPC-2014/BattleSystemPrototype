#include "CUISelector.h"

Selection CUISelector::select( Character *actor, CharacterList characters )
{
	std::string action;
	std::string target;

	//スキルをCUI入力
	auto isAction = [&action](std::string a) { return a == action; };
	std::cout << "Select command.\t" << "attack magic care\n";
	do {
		std::cout << "command-->";
		std::cin >> action;
	} while(std::none_of(BattleCommands::COMMANDS_m.begin(), BattleCommands::COMMANDS_m.end(), isAction));

	//選択可能なキャラクタを抽出して表示
	CharacterList targets = characters.getAvailableTargets(actor, action);
	auto print = [](Character *target) { std::cout << target->data_m.name_m << " "; };
	auto isTarget = [&target](Character* t) { return target == t->data_m.name_m; };

	std::cout << "Select target.\t";
	std::for_each(targets.begin(), targets.end(), print);
	std::cout << std::endl;

	//ターゲットをCUI入力(正しく入力するまで繰り返し)
	do {
		std::cout << "target-->";
		std::cin >> target;
	} while(std::none_of(targets.begin(), targets.end(), isTarget));

	//攻撃者の行動として設定
	return{ action, target };
}