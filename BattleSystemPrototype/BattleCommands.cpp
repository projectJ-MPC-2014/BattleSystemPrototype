#include "BattleCommands.h"

const BattleCommands::Commands BattleCommands::COMMANDS_m = { "attack", "magic", "care" };

const int BattleCommands::getNumOfCommands()
{
	return COMMANDS_m.size();
}