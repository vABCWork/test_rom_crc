
#include	"iodefine.h"
#include	"misratypes.h"
#include	"crc_16.h"
#include	"rom_crc_data.h"

uint8_t rom_crc_16_err;  // ROM��CRC���s��v�̏ꍇ=1


uint16_t	calculated_crc; // CRC���Z��ɂ��v�Z�l(�f�[�^����CRC�v�Z)
uint16_t	invert_crc;	// ���]�l

// CRC�v�Z�̃e�X�g
//  �r���h�������J�[����o�͂��ꂽCRC�l(rom_crc_data)��CRC���Z��Ōv�Z���ăr�b�g���]�����l(inver_crc)����v����΁A
//  CRC����v���Ă���B
//  CRC�v�Z�͈͂́A 0xfffc0100�`0xffffffff
//
//
// CRC���Z��F
// ���������� (CRC-CCITT XModem (h'1021) ( X^16 + X^12 + X^5 + 1))
// �����l: 0xffff
//  MSB�t�@�[�X�g
//
void ROM_CRC_Err_Check(void)
{
	uint8_t *pt;
	
	uint32_t i;
	
	uint32_t start_adrs;
	uint32_t end_adrs;
	
	
	Init_CRC();			// CRC���Z��̏�����
	
	
	start_adrs = 0xfffc0100;	     // �v���O�����擪�A�h���X
	end_adrs = 0xffffffff;	             // �ŏI�A�h���X
	
	
	pt = (uint8_t *)start_adrs;
	
	for ( i = 0 ; i < (end_adrs - start_adrs + 1) ; i++ ) {	     // CRC�̌v�Z

		CRC.CRCDIR = *pt;
		
		pt++;
	}
	
	       
	calculated_crc = CRC.CRCDOR;        // CRC�̉��Z����
	
	invert_crc = ~calculated_crc;	    // �r�b�g���]
	
	if ( rom_crc_data != invert_crc ) { // CRC�̕s��v�̏ꍇ	
		rom_crc_16_err = 1;
	}
	else{				    // CRC��v�̏ꍇ
		rom_crc_16_err = 0;
	}
	
}






// CRC���Z��̏�����
// CRC-CCITT
// ���������� : X^16 + X^12 + X^5 + 1
// �����l: 0xffff
//  MSB�t�@�[�X�g
//
void Init_CRC(void)
{
	
	CRC.CRCCR.BYTE = 0x87;		     // CRCDOR���W�X�^���N���A, MSB�t�@�[�X�g, 16�r�b�gCRC�iX^16 + X^12 + X^5 + 1 �j
	CRC.CRCDOR = 0xffff;		     // �����l

}

