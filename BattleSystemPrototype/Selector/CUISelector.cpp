#include "CUISelector.h"


int CUISelector::select( Character *attacker, CharaList characters )
{
	std::string skillName;
	std::string target;

	//�X�L����CUI����
	std::cout << attacker->name_m + " �� ���񂽂�" << std::endl;
		// todo:�I�ׂ�R�}���h�ꗗ��\������
	std::cout << "Command:";
	std::cin >> skillName;

	//�I���\�ȃL�����N�^�𒊏o���ĕ\��
	CharaList targets = getAvailableTargets( attacker, characters, skillName );
	auto print = []( Character *target ){std::cout << target->name_m << std::endl; };
	auto contains = [&target]( Character* t ){return target == t->name_m; };
	std::for_each( targets.begin(), targets.end(), print );

	//�^�[�Q�b�g��CUI����(���������͂���܂ŌJ��Ԃ�)
	while( true ) {
		std::cout << "Target:";
		std::cin >> target;
		if( std::any_of( targets.begin(), targets.end(), contains ) ) {
			break;
		}
	}

	//�U���҂̍s���Ƃ��Đݒ�
	attacker->select( { skillName, target } );

	return 1;
}