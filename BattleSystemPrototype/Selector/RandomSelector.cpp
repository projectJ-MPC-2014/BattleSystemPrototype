#include "RandomSelector.h"

RandomSelector::RandomSelector()
{
	engine_m.seed(std::random_device()());
}

int RandomSelector::select( Character *attacker, CharaList characters )
{
	std::string skillName;
	std::string target;
	
	random_m.param( Dist::param_type( 0, BattleCommands::getNumOfCommands() - 1 ) );
	skillName = BattleCommands::COMMANDS_m[random_m( engine_m )];
	std::cout << attacker->name_m << " の せんたく" << std::endl;
	std::cout << "Command:";
	std::cout << skillName << std::endl;

	CharaList targets = getAvailableTargets( attacker, characters, skillName );
	random_m.param( Dist::param_type( 0, targets.size() - 1 ) );
	CharaList::iterator ite = targets.begin();

	std::advance( ite, random_m( engine_m ) );
	target = ( *ite )->name_m;
	std::cout << "Target:";
	std::cout << target << std::endl;

	attacker->select( { skillName, target } );

	return 1;
}

