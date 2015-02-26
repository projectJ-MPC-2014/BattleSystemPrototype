#include "ActionFactory.h"

ActionFactory::StrToAction ActionFactory::toAction_m = {
	{ "attack", std::make_unique<Attack>() },
	{ "care", std::make_unique<Care>() },
	{ "magic", std::make_unique<Magic>() },
};

std::shared_ptr<Action> ActionFactory::get(std::string actionName)
{	
	return std::any_of(toAction_m.begin(), toAction_m.end(), [actionName](StrActionPair pair)
	{
		return pair.first == actionName;
	})
		? toAction_m[actionName] : nullptr;
}
