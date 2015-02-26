#pragma once

#include<list>
#include"Character\Character.h"
#include"Action\ConditionOfTarget.h"

class Character;

/**
* �L�����N�^�����X�g�ł܂Ƃ߂����b�p�N���X
*/
class CharacterList
{
private:
	/**�L�����N�^���X�g�̌^*/
	typedef std::list<Character*> CharaList_t;
public:
	/**�C�e���[�^�̌^*/
	typedef std::list<Character*>::iterator iterator;
private:
	/**�L�����N�^���X�g�{��*/
	CharaList_t characters_m;
private:
	/**
	*�s���I���҂̑I�������s����K�p�ł�������𖞂����Ώۂ��L�����N�^���X�g���甲���o���ă��X�g�ɂ��ĕԂ�
	* @param condition �s����K�p�ł������,for_each�ɓn���֐��I�u�W�F�N�g
	* @return �Ώۂ��܂Ƃ߂����X�g
	*/
	template<class Condition>
	CharacterList createTargets(Condition &condition)
	{
		CharacterList targets;
		
		targets.characters_m.resize(
			std::count_if(characters_m.begin(), characters_m.end(), condition));
		std::copy_if(
			characters_m.begin(), characters_m.end(), targets.begin(), condition);
		
		return targets;
	}

public:
	/**
	*�I���\�ȑΏ�(�X�L����K�p�ł���)�̃��X�g�𓾂�֐�
	*@param actor �s������L�����N�^
	*@param action actor���I�������X�L���̖��O
	*@return �X�L����K�p�ł���L�����N�^�̃��X�g
	*/
	CharacterList getAvailableTargets(
		Character*actor, std::string action);
	/**
	*�f�������ɕ��ёւ���
	*/
	void sort();
	/**
	*���X�g�ɃL�����N�^��}������
	*/
	void insert(Character *character);
	/**
	*�擪�̃C�e���[�^��Ԃ�
	* @return �擪�̃C�e���[�^
	*/
	iterator begin();
	/**
	*�����̃C�e���[�^��Ԃ�
	* @return �����̃C�e���[�^
	*/
	iterator end();
	/**
	*�����𖞂����L�����N�^���������ăL�����N�^�N���X�̃|�C���^��Ԃ�
	* @paaram ����(�֐��I�u�W�F�N�g)
	* @return �����𖞂����L�����N�^��������Ȃ��� nullptr, ���������� ���̃L�����N�^�ւ̃|�C���^
	*/
	template<typename Condition>
	Character *findIf(Condition condition)
	{
		auto found = std::find_if(
			characters_m.begin(), characters_m.end(), condition);
		return found == characters_m.end() ? nullptr : *found;
	}

	//void erase(iterator first, iterator last);
	/**
	*���X�g�̗v�f����Ԃ�
	* @return ���X�g�̗v�f��
	*/
	size_t size()const;
};

