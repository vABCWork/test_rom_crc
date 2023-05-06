
#include <machine.h>

//    �@��O���ۂ̏����v���O����
// �@����`���ߗ�O�A�������ߗ�O�A�A�N�Z�X��O�A���������_��O�A�m���}�X�J�u���̏����v���O����
//      brk() : �������g���b�v (���荞�݃x�N�^�e�[�u���̃x�N�^�ԍ�0�̃A�h���X�ɕ���) 


// �������ߗ�O (���[�U���[�h�œ������߂̎��s�����o�����ꍇ�ɔ���)
#pragma interrupt (Excep_SuperVisorInst)
void Excep_SuperVisorInst(void){
	brk();
}

// �A�N�Z�X��O (CPU ����̃������A�N�Z�X�ɂ��G���[�����o���ꂽ�ꍇ�ɔ���)
#pragma interrupt (Excep_AccessInst)
void Excep_AccessInst(void){
	brk();
}

//  ����`���ߗ�O (����`����( ��������Ă��Ȃ�����) �̎��s�����o�����ꍇ�ɔ���)
#pragma interrupt (Excep_UndefinedInst)
void Excep_UndefinedInst(void){
	brk();
}

// ���������_��O
// �I�[�o�t���[�A�A���_�t���[�A���x�ُ�A�[�����Z�A�������Z)�̑��A��������������o�����ꍇ�ɔ����B
// FPSW ��EX�AEU�AEZ�AEO�AEV �r�b�g���g0�h �̂Ƃ��A��O�������֎~����܂��B
// (���Z�b�g��̒l�͑S��0�̂��߁A��O�����֎~)
//
#pragma interrupt (Excep_FloatingPoint)
void Excep_FloatingPoint(void){
	brk();
}

// �m���}�X�J�u�����荞�� NMI (CPU �Ƀm���}�X�J�u�����荞�ݐM������͂��邱�Ƃɂ���Ĕ���)
// NMI�[�q(P35), �Ɨ��E�I�b�`�h�b�N�^�C�}(IWDT)�ɂ��m���}�X�J�u�����荞��
#pragma interrupt (NonMaskableInterrupt)
void NonMaskableInterrupt(void){
	brk();
}

// Dummy
#pragma interrupt (Dummy)
void Dummy(void){
	brk();
}
