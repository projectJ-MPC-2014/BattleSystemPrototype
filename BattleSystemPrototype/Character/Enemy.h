#pragma once

#include"Character.h"
#include"../Selector/RandomSelector.h"

/**
*�G�L�����N�^
*/
class Enemy : public Character
{
public:
	/**�R���X�g���N�^*/
	Enemy(CharaData data);
	/**�f�X�g���N�^*/
	~Enemy() = default;
public:
	/**
	*�����_���ɍs���I������N���X�𐶐�����
	*�s���I���N���X�ւ̃|�C���^
	*/
	std::unique_ptr<Selector> getSelector()override;
};
