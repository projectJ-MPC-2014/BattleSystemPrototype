#pragma once

#include<string>

/**
*プレイヤの行動を表す構造体
*スキル名とその対象を持つ
*/
struct Selection
{
	/**スキル名*/
	std::string action_m;
	/**対象の名前*/
	std::string target_m;
	/**無効な行動選択を得る*/
	static Selection nullSelection()
	{
		return{ "", "" };
	}
	bool operator==(Selection const &selection)
	{
		return action_m == selection.action_m &&
			target_m == selection.target_m;
	}
	bool operator!=(Selection const &selection)
	{
		return !operator==(selection);
	}
};
