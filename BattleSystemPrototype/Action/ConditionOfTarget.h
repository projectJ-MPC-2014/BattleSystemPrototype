#pragma once

#include"../Character/Character.h"

class Character;

/**
*�s���I���҂��I�������s���̃^�[�Q�b�g�̏����̒��ۃN���X
*/
class ConditionOfTarget
{
protected:
	/**�s���I���L�����N�^�̃|�C���^*/
	Character *actor_m;
public:
	/**�s���I���҂�ݒ肷������t���R���X�g���N�^*/
	ConditionOfTarget(Character *actor) :actor_m(actor) {}
	/**�R�s�[�R���X�g���N�^*/
	ConditionOfTarget(ConditionOfTarget const &) = default;
	/**�f�X�g���N�^*/
	virtual~ConditionOfTarget() = default;
protected:
	/**
	*������n���ꂽ�L�����N�^�������𖞂������^��Ԃ�
	* @param chara ���肷�ׂ��L�����N�^
	* @return chara�������𖞂�����true,�����łȂ���false
	*/
	virtual bool satisfies(Character *chara) = 0;
public:
	/**
	*�h���N���X��()���Z�q��񋟂���
	*������n���ꂽ�L�����N�^�������𖞂������^��Ԃ�
	* @param chara ���肷�ׂ��L�����N�^
	* @return chara�������𖞂�����true,�����łȂ���false
	*/
	bool operator()(Character *chara)
	{
		return satisfies(chara);
	}
};

/**
*���̃L�����N�^���s���I���҂̖����łȂ��Ƃ���������\���N���X
*/
class IsNotAlly : public ConditionOfTarget
{
public:
	/**�s���I���҂�ݒ肷������t���R���X�g���N�^*/
	IsNotAlly(Character *actor):ConditionOfTarget(actor) {}
	/**�R�s�[�R���X�g���N�^*/
	IsNotAlly(IsNotAlly const &) = default;
	/**�f�X�g���N�^*/
	virtual~IsNotAlly() = default;
protected:
	/**
	*���̃L�����N�^���s���I���҂̖����łȂ����^��Ԃ�
	* @param chara ���肷�ׂ��L�����N�^
	* @return �����łȂ���true,�����ł��鎞false
	*/
	bool satisfies(Character *chara)override;
};

/**
*���̃L�����N�^���s���I���҂̖����ł���Ƃ���������\���N���X
*/
class IsAlly : public ConditionOfTarget
{
public:
	/**�s���I���҂�ݒ肷������t���R���X�g���N�^*/
	IsAlly(Character *actor) :ConditionOfTarget(actor) {}
	/**�R�s�[�R���X�g���N�^*/
	IsAlly(IsAlly const &) = default;
	/**�f�X�g���N�^*/
	virtual~IsAlly() = default;
protected:
	/**
	*���̃L�����N�^���s���I���҂̖����ł��鎞�^��Ԃ�
	* @param chara ���肷�ׂ��L�����N�^
	* @return �����̎�true,�����łȂ���false
	*/
	bool satisfies(Character *chara)override;
};
