#pragma once

#include"Iff.h"

/**
*�L�����N�^�̐��l�f�[�^���܂Ƃ߂��\����
*/
struct CharaData
{
	/**�L�����N�^ID*/
	int id_m;
	/**�L�����N�^��*/
	std::string name_m;
	/**�̗�*/
	int hp_m;
	/**�U����*/
	int attack_m;
	/**����*/
	int magic_m;
	/**�q����*/
	int agility_m;
	/**
	*�����t���O
	*hp��0���傫�����ɐ^
	*/
	bool isAlive_m;
	/**�v���C���ɂƂ��ēG��������*/
	Iff iff_m;
	};

