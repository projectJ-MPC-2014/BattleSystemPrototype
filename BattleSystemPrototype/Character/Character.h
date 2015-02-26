#pragma once
#include<cassert>
#include<string>
#include<algorithm>
#include<memory>
#include"CharaData.h"
#include"Selection.h"
#include"../Selector/Selector.h"

class Selector;
class CharacterList;

/**
*�L�����N�^�̏�񂪂܂Ƃ߂��Ă���
*�X�L�����ƂɌv�Z�����郁�\�b�h������
*���t�@�N�^�����O���K�v
*/
class Character
{
protected:
	/**�I�����ꂽ�s��*/
	Selection selection_m;
public:
	/**�L�����N�^�̃f�[�^*/
	CharaData data_m;	
public:
	/**
	*�R���X�g���N�^
	*�L�����N�^�̏���ݒ肷��
	*@param name �L�����N�^��
	*@param data �L�����N�^�̐��l�f�[�^
	*@param id �L�����N�^ID
	*/
	Character(CharaData data);
	/**�f�X�g���N�^*/
	virtual ~Character() = default;
public:
	/**
	*�L�����N�^�̍s���𓾂�֐�
	*TestBattle��testAttack�ŌĂ΂��
	*/
	Selection getSelection();
	/**
	*�L�����N�^���Ƃ̍s���I���̎d����\���N���X�𐶐�����
	*/
	virtual std::unique_ptr<Selector> getSelector() = 0;
};

