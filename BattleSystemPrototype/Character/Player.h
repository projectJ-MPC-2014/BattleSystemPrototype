#pragma once

#include<string>
#include"Character.h"

/**
*プレイヤキャラクタ
*/
class Player : public Character
{
public:
	/**コンストラクタ*/
	Player(std::string name, CharaData data, int id);
	/**デストラクタ*/
	~Player() = default;
public:
};

