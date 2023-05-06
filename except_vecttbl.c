//
//    ��O�x�N�^�e�[�u���A���Z�b�g�x�N�^�A �I�v�V�����ݒ胁����(OFSM),�t���b�V���������v���e�N�g�p ID
//   
//  1) ��O�x�N�^�e�[�u���ŁA����`���ߗ�O�A�������ߗ�O�A�A�N�Z�X��O�A���������_��O�A�m���}�X�J�u�����荞�ݏ����̊J�n�A�h���X��ݒ�B
//  �E��O�x�N�^�e�[�u���̐擪�A�h���X�́A���W�X�^ EXTB�Ŏ������B  
//�@�E�X�^�[�g�A�b�v�� (restprg.c)�ŁAEXTB �� section EXCEPTVECT�̒l���i�[���Ă���B
//  �EEXCEPTVECT�̔z�u�A�h���X�́A�����N�I�v�V�����̃Z�N�V�����J�n�A�h���X�Ŏw��B�i0xffff ff80)
//
// 2) ���Z�b�g�x�N�^�́A0xffff fffc�ɔz�u�B 
//�@�E RESETVECT�̔z�u�A�h���X�́A�����N�I�v�V�����̃Z�N�V�����J�n�A�h���X�Ŏw��B�i0xffff fffc)
//  
// 3) �I�v�V�����ݒ胁����(OFSM)
//    �G���f�B�A���I�����W�X�^(MDE),�I�v�V�����@�\�I�����W�X�^1 (OFS1), (OSF2)��ݒ�B
//
// 4) �t���b�V���������v���e�N�g�@�\�p��ID�̈�
//
// �Q�l:
// �uRX23E-A�O���[�v ���[�U�[�Y�}�j���A���@�n�[�h�E�F�A�ҁv( Rev.1.20 2022.04 )
//    2.6.1 ��O�x�N�^�e�[�u��
//    13.1 ��O����
//    2.2.2.9 ���������_�X�e�[�^�X���[�h(FPSW)
//    7. �I�v�V�����ݒ胁����(OFSM)
//    38.9 �t���b�V���������v���e�N�g�@�\
//

extern void Dummy(void);
extern void Excep_SuperVisorInst(void);
extern void Excep_AccessInst(void);
extern void Excep_UndefinedInst(void);
extern void Excep_FloatingPoint(void);
extern void NonMaskableInterrupt(void);

extern void PowerON_Reset_PC(void);


//
// �I�v�V�����@�\�I�����W�X�^�Ɨ�O�x�N�^�e�[�u�� (0xffff ff80�` 0xffff fff8)
//   ( reserved�ɂ́ADummy()�֐��̐擪�A�h���X������) 
//
//  �A�h���X   : ���e
// 0xffff ff80 : �G���f�B�A���I�����W�X�^(MDE) (���g���G���f�B�A���p)
// 0xffff ff84 : reserved  
// 0xffff ff88 : �I�v�V�����@�\�I�����W�X�^1 (OFS1)
// 0xffff ff8c : �I�v�V�����@�\�I�����W�X�^0 (OFS0)
// 0xffff ff90 : reserved  
// 0xffff ff94 : reserved
// 0xffff ff98 : reserved
// 0xffff ff9c : reserved
// 0xffff ffa0 : �t���b�V���������v���e�N�g�p�@ID
// 0xffff ffa4 : �t���b�V���������v���e�N�g�p�@ID
// 0xffff ffa8 : �t���b�V���������v���e�N�g�p�@ID
// 0xffff ffac : �t���b�V���������v���e�N�g�p�@ID
// 0xffff ffb0 : reserved  
// 0xffff ffb4 : reserved
// 0xffff ffb8 : reserved
// 0xffff ffbc : reserved
// 0xffff ffc0 : reserved  
// 0xffff ffc4 : reserved
// 0xffff ffc8 : reserved
// 0xffff ffcc : reserved
// 0xffff ffd0 : �������ߗ�O
// 0xffff ffd4 : �A�N�Z�X��O
// 0xffff ffd8 : reserved
// 0xffff ffdc : ����`���ߗ�O
// 0xffff ffe0 : reserved
// 0xffff ffe4 : ���������_��O
// 0xffff ffe8 : reserved
// 0xffff ffec : reserved
// 0xffff fff0 : reserved
// 0xffff fff4 : reserved
// 0xffff fff8 : �m���}�X�J�u�����荞��
//
// 0xffff fffc : ���Z�b�g�x�N�^


#pragma section C EXCEPTVECT

void (*const Except_Vectors[])(void) = {

// 0xffffff80  MDE register
    (void (*)(void))0xffffffff, // little

// 0xffffff84  Reserved
    Dummy,
    
// 0xffffff88  OFS1 register
//
// �u�����P�[�W�G�f�B�^��CRC���Z���CRC-CCITT���ʂ̈Ⴂ�v (https://ja-support.renesas.com/knowledgeBase/17796715)
//  FINE�ڑ��Ń}�C�R���Ɛڑ����Ă���ꍇ(JTAG�ڑ��̏ꍇ�͊Y�����܂���)�AE1�܂���E20�G�~�����[�^�N������
//  �G�~�����[�^����p�̃R�[�h�Ƃ��ăI�v�V�����@�\�I�����W�X�^1(OFS1�F�A�h���XFFFFFF88h-FFFFFF8Bh)��bit24��0���������܂�܂��B
// 

    (void (*)(void))0xfeffffff, // OFS1
    
// 0xffffff8c  OFS0 register
    (void (*)(void))0xffffffff, // OFS0

// 0xffffff90  Reserved
    Dummy,
    
// 0xffffff94  Reserved
    Dummy,
    
// 0xffffff98  Reserved
    Dummy,
    
// 0xffffff9c  Reserved
    Dummy,
    
// 0xffffffa0  ID
    (void (*)(void))0xffffffff,

// 0xffffffa4  ID
    (void (*)(void))0xffffffff,
    
// 0xffffffa8  ID
    (void (*)(void))0xffffffff,
    
// 0xffffffac  ID
    (void (*)(void))0xffffffff,
    
// 0xffffffb0  Reserved
    Dummy,
    
// 0xffffffb4  Reserved
    Dummy,
    
// 0xffffffb8  Reserved
    Dummy,
    
// 0xffffffbc  Reserved
    Dummy,
    
// 0xffffffc0  Reserved
    Dummy,

// 0xffffffc4  Reserved
    Dummy,
    
// 0xffffffc8  Reserved
    Dummy,
    
// 0xffffffcc  Reserved
    Dummy,
    
// 0xffffffd0  �������ߗ�O
    Excep_SuperVisorInst,
    
// 0xffffffd4  �A�N�Z�X��O
    Excep_AccessInst,
    
// 0xffffffd8  Reserved
    Dummy,
    
// 0xffffffdc   ����`���ߗ�O
    Excep_UndefinedInst,
    
// 0xffffffe0  Reserved
    Dummy,
    
// 0xffffffe4  ���������_��O
    Excep_FloatingPoint,
    
// 0xffffffe8  Reserved
    Dummy,
    
// 0xffffffec  Reserved
    Dummy,
    
//v0xfffffff0  Reserved
    Dummy,
    
//v0xfffffff4  Reserved
    Dummy,
    
//v0xfffffff8  �m���}�X�J�u�����荞�݁@ NMI
    NonMaskableInterrupt,

};


#pragma section C RESETVECT
void (*const Reset_Vectors[])(void) = {
	PowerON_Reset_PC 
};
