#include	<machine.h>
#include	"iodefine.h"
#include	"misratypes.h"
#include	"delay.h"
#include	"crc_16.h"


// �A���[���p�@LED�o�̓|�[�g
// ALM1 : ROM-CRC�G���[
// ALM1: P17
#define ALM_1_PMR      (PORT1.PMR.BIT.B7)   //  �ėp���o�̓|�[�g
#define ALM_1_PDR      (PORT1.PDR.BIT.B7)   //  �o�͂܂��͓��̓|�[�g�|�[�g�Ɏw��
#define ALM_1_PODR     (PORT1.PODR.BIT.B7)  //  �o�̓f�[�^


void clear_module_stop(void);

void main(void)
{
	
	clear_module_stop();	//  ���W���[���X�g�b�v�̉���
	
	ALM_1_PMR = 0;		// �ėp���o�̓|�[�g
	ALM_1_PDR = 1;		// �o�̓|�[�g�Ɏw��
	
	
	ROM_CRC_Err_Check();
	
	
	if ( rom_crc_16_err == 1 ) {    // ROM CRC�ُ�̏ꍇ
	
	   while(1){		        // �������[�v
	   
	        ALM_1_PODR = 1; 	//  High(ALM1_LED�_��)
		delay_msec(500);   	// 500[msec]�҂�
		
		ALM_1_PODR = 0; 	//  Low (ALM1_LED����)
		delay_msec(500);   	// 500[msec]�҂�
		
	   }
	}
	
	
	while(1){	
		
		delay_msec(500);
	}
	
}





// ���W���[���X�g�b�v�̉���
//   CRC ���Z��iCRC�j
//
void clear_module_stop(void)
{
	SYSTEM.PRCR.WORD = 0xA50F;	// �N���b�N�����A����d�͒ጸ�@�\�֘A���W�X�^�̏������݋���	
	
	MSTP(CRC) = 0;			// CRC ���W���[���X�g�b�v�̉���
	
	SYSTEM.PRCR.WORD = 0xA500;	// �N���b�N�����A����d�͒ጸ�@�\�֘A���W�X�^�������݋֎~
}

