#include "Player.h"


Player::Player(std::string name, CharaData data, int id)
:Character(name, data, id)
{
	iff_m = Iff::FRIEND;
}


Player::~Player()
{
}

std::string Player::selectCommand( CharaList &chacters )
{
	std::string command;

	output_m.messageLine( name_m + " の せんたく" );

	// 選べるコマンド一覧を表示する

	output_m.message( "Command:" );
	command = input_m.command();
	
	return command ;
}

std::string Player::selectTarget( CharaList &characters, std::string skillName )
{
	std::string target;
	CharaList targets = getAvailableTargets( this, characters, skillName );
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

	return target;
}