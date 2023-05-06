#include	<machine.h>
#include	"iodefine.h"
#include	"misratypes.h"
#include	"delay.h"
#include	"crc_16.h"


// アラーム用　LED出力ポート
// ALM1 : ROM-CRCエラー
// ALM1: P17
#define ALM_1_PMR      (PORT1.PMR.BIT.B7)   //  汎用入出力ポート
#define ALM_1_PDR      (PORT1.PDR.BIT.B7)   //  出力または入力ポートポートに指定
#define ALM_1_PODR     (PORT1.PODR.BIT.B7)  //  出力データ


void clear_module_stop(void);

void main(void)
{
	
	clear_module_stop();	//  モジュールストップの解除
	
	ALM_1_PMR = 0;		// 汎用入出力ポート
	ALM_1_PDR = 1;		// 出力ポートに指定
	
	
	ROM_CRC_Err_Check();
	
	
	if ( rom_crc_16_err == 1 ) {    // ROM CRC異常の場合
	
	   while(1){		        // 無限ループ
	   
	        ALM_1_PODR = 1; 	//  High(ALM1_LED点灯)
		delay_msec(500);   	// 500[msec]待ち
		
		ALM_1_PODR = 0; 	//  Low (ALM1_LED消灯)
		delay_msec(500);   	// 500[msec]待ち
		
	   }
	}
	
	
	while(1){	
		
		delay_msec(500);
	}
	
}





// モジュールストップの解除
//   CRC 演算器（CRC）
//
void clear_module_stop(void)
{
	SYSTEM.PRCR.WORD = 0xA50F;	// クロック発生、消費電力低減機能関連レジスタの書き込み許可	
	
	MSTP(CRC) = 0;			// CRC モジュールストップの解除
	
	SYSTEM.PRCR.WORD = 0xA500;	// クロック発生、消費電力低減機能関連レジスタ書き込み禁止
}

