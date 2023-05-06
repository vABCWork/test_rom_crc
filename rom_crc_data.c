#include "machine.h"
#include "misratypes.h"
#include "rom_crc_data.h"


// #pragma section�ŃZ�N�V��������ύX
// �������ꂽ�Z�N�V�������̊J�n�A�h���X�́A�����N�I�v�V�����̃Z�N�V�����J�n�A�h���X�Őݒ肷��B
//
// ��: �Z�N�V���� CROM_CRC_CODE_2�� FFFC 0000 �Ɋ���t��
//   B_1,R_1,B_2,R_2,B,R,SU,SI/00000004,CROM_CRC_CODE_2/0FFFC0000,PResetPRG,C_1,C_2,C,C$DSEC,C$BSEC,C$INIT,C$VTBL,C$VECT,D_1,D_2,D,P,PIntPRG,W_1,W_2,W,L/0FFFC0100,EXCEPTVECT/0FFFFFF80,RESETVECT/0FFFFFFFC
//
// �Q�l:
//�i4.2.4 �g���d�l�̎g�p���@�@(1) �Z�N�V�����؂�ւ��L�q�j ���A
//�i CC-RX �R���p�C�� ���[�U�[�Y�}�j���A�� (R20UT3248JJ0112 Rev.1.12 )
//

// �����N���̃Z�N�V�������́ACROM_CRC_CODE_2�@�ƂȂ�B�@(2�� 2byte�̂���) 
#pragma section   ROM_CRC_CODE

const uint16_t  rom_crc_data = 0x5497;     // CS+�ɂ��o�͂��ꂽ�ACRC�l���L������B
