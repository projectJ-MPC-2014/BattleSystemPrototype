#pragma once

#include<string>
#include"Character.h"

/**
*�v���C���L�����N�^
*/
class Player : public Character
{
public:
	/**�R���X�g���N�^*/
	Player(std::string name, CharaData data, int id);
	/**�f�X�g���N�^*/
	~Player() = default;
public:
};

