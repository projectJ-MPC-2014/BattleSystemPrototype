#include "CharacterList.h"

void CharacterList::insert(Character *character)
{
	characters_m.emplace_back(character);
}

void CharacterList::sort()
{
	auto compareAgility = [](Character *chara1, Character *chara2)
	{
		return chara1->data_m.agility_m > chara2->data_m.agility_m;
	};

	characters_m.sort(compareAgility);
}

CharacterList CharacterList::getAvailableTargets(
	Character*actor, std::string action)
{
	CharacterList targets;
	//コマンドごとに選択可能な攻撃相手を抽出したリストを返す
	if(action == "attack") {
		targets = createTargets(IsNotAlly(actor));
	}
	else if(action == "magic") {
		targets = createTargets(IsNotAlly(actor));
	}
	else if(action == "care") {
		targets = createTargets(IsAlly(actor));
	}
	return targets;
}

size_t CharacterList::size()const
{
	return characters_m.size();
}

CharacterList::iterator CharacterList::begin()
{
	return characters_m.begin();
}

CharacterList::iterator CharacterList::end()
{
	return characters_m.end();
}