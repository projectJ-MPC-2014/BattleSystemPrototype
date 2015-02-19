#include "CUISelector.h"


int CUISelector::select( Character *attacker, CharaList characters )
{
	std::string skillName;
	std::string target;

	std::cout << attacker->name_m + " の せんたく" << std::endl;
	// todo:選べるコマンド一覧を表示する
	std::cout << "Command:";
	std::cin >> skillName;

	CharaList targets = getAvailableTargets( attacker, characters, skillName );
	auto print = []( Character *target ){std::cout << target->name_m << std::endl; };
	auto contains = [&target]( Character* t ){return target == t->name_m; };

	std::for_each( targets.begin(), targets.end(), print );
	while( true ) {
		std::cout << "Target:";
		std::cin >> target;
		if( std::any_of( targets.begin(), targets.end(), contains ) ) {
			break;
		}
	}

	attacker->select( { skillName, target } );

	return 1;
}