#include "Enemy.h"

//const int Enemy::NUMBER_OF_COMMANDS = 3;
//const std::string Enemy::COMMANDS[NUMBER_OF_COMMANDS] = { "attack", "magic", "care" };

Enemy::Enemy(std::string name, CharaData data, int id)
:Character(name, data, id)
{
	engine_m.seed( seed_m() );
	iff_m = Iff::FOE;
}


Enemy::~Enemy()
{
}


std::string Enemy::selectCommand( CharaList &chacters )
{
	std::string command;
	random_m.param( Dist::param_type( 0, BattleCommands::NUMBER_OF_COMMANDS_m - 1 ) );
	command = BattleCommands::COMMANDS_m[random_m( engine_m )];


	std::cout << name_m << " の せんたく" << std::endl;

	//選べるコマンド一覧を表示する

	std::cout << "Command:";
	std::cout << command << std::endl;

	return command;
}

std::string Enemy::selectTarget( CharaList &characters, std::string skillName )
{
	std::string target;
	CharaList targets = getAvailableTargets( this, characters, skillName );
	random_m.param( Dist::param_type( 0, targets.size() - 1 ) );
	CharaList::iterator ite = targets.begin();

	std::advance( ite, random_m( engine_m ) );
	target = ( *ite )->name_m;
	std::cout << "Target:";
	std::cout << target << std::endl;

	return target;
}

