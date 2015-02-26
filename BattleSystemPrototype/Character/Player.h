#pragma once

#include<string>
#include"Character.h"
#include"../Selector/CUISelector.h"

/**
*�v���C���L�����N�^
*/
class Player : public Character
{
public:
	/**�R���X�g���N�^*/
	Player(CharaData data);
	/**�f�X�g���N�^*/
	~Player() = default;
public:
	/**
	*CUI�ōs���I������N���X�𐶐�����
	*/
	std::unique_ptr<Selector> getSelector();
};

