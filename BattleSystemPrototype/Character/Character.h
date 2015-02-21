#pragma once
#include <iostream>
#include<cassert>
#include<string>
#include<list>
#include<algorithm>
#include"CharaData.h"

/**
*�G�������ʂ̗񋓑�
*/
enum class Iff:int	//Identify friend or foe
{
	/**�G�����s��*/
	UNKNOWN,
	/**�v���C���̖���*/
	FRIEND,
	/**�v���C���̓G*/
	FOE
};


class Character;
/**
*�v���C���̍s����\���\����
*�X�L�����Ƃ��̑Ώۂ�����
*/
struct Selection
{
	/**�X�L����*/
	std::string skillName_m;
	/**�Ώۂ̖��O*/
	std::string target_m;
};


/**�L�����N�^�̃��X�g*/
typedef std::list<Character*> CharaList;

/**
*�I���\�ȑΏ�(�X�L����K�p�ł���)�̃��X�g�𓾂�֐�
*@param attacker �s������L�����N�^
*@param characters �S�L�����N�^�̃��X�g
*@param skillName attacker���I�������X�L���̖��O
*@return �X�L����K�p�ł���L�����N�^�̃��X�g
*/
CharaList getAvailableTargets(
	Character*attacker,
	CharaList &characters,
	std::string skillName );


/**
*�L�����N�^�̏�񂪂܂Ƃ߂��Ă���
*�X�L�����ƂɌv�Z�����郁�\�b�h������
*���t�@�N�^�����O���K�v
*/
class Character
{
protected:
	/**�v���C���ɂƂ��ēG��������*/
	Iff iff_m;
	/**�I�����ꂽ�s��*/
	Selection selection_m;
public:
	/**�L�����N�^�̃f�[�^*/
	CharaData data_m;
	/**�L�����N�^��*/
	std::string name_m;
	/**�L�����N�^ID*/
	int id_m;
public:
	/**
	*�R���X�g���N�^
	*�L�����N�^�̏���ݒ肷��
	*@param name �L�����N�^��
	*@param data �L�����N�^�̐��l�f�[�^
	*@param id �L�����N�^ID
	*/
	Character(std::string name, CharaData data, int id);
	/**�f�X�g���N�^*/
	virtual ~Character() = default;
protected:
	/**
	*�_���[�W���󂯂�֐�
	*@param damage �󂯂�_���[�W(�̗͂��������)
	*/
	void damage(int damage);
	/**
	*�������񕜂���֐�
	*@param heal �񕜗� 
	*/
	void heal(int heal);
public:
	/**
	*���@�U��������֐�
	*@param target �U���Ώ�
	*/
	void magic( Character &target );
	/**
	*�����U��������֐�
	*@param target �U���Ώ�
	*/
	void attack(Character &target);
	/**
	*������񕜂�����֐�
	*@param target �񕜑Ώ�
	*/
	void care( Character &target );
	/**
	*�L�����N�^�̍s���𓾂�֐�
	*TestBattle��testAttack�ŌĂ΂��
	*/
	Selection getSelection();
	/**
	*�L�����N�^�̍s���I�����Z�b�g����
	*/
	void Character::select( Selection const &selection );
	/**
	*�L�����N�^�̓G�������𓾂�
	*@return �G�������ʗ񋓒萔
	*/
	Iff getIff();
};

