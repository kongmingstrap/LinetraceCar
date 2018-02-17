/*" FILE COMMENT***************************************************/
/* 
/*  System Name     : AD変換
/*  File Name       : Ad.c
/*  Module Name     : Ad
/*  Process         : AD変換
/*  Programmer      : 田中　孝明        2008-5-23
/* 
/* << File Version >>
/*
/****" FILE COMMENT END "******************************************/

#include "Common.h"
#include "Ad.h"

/*==================================================================*/
/*							定数宣言								*/
/*==================================================================*/
#define RIGHT_SENSOR_PORT		( COMMON_RIGHT_SENSOR_PORT )
#define CENTER_SENSOR_PORT		( COMMON_CENTER_SENSOR_PORT )
#define LEFT_SENSOR_PORT		( COMMON_LEFT_SENSOR_PORT )

/*==================================================================*/
/*							大域関数宣言							*/
/*==================================================================*/

/*==================================================================*/
/*							静的変数宣言							*/
/*==================================================================*/

/*==================================================================*/
/*							静的関数宣言							*/
/*==================================================================*/

/*" function comment"********************************************/
/* 
/*  Function Name   : fnInitSci
/*  Process         : シリアル通信レジスタ初期化
/*  Argument        : なし
/*  Return Value    : なし
/*  Programmer      : 田中　孝明        2008-1-23
/* << History >>
/* 
/*" function comment end"****************************************/
void fnInitSci( void )
{
	volatile u16 u16t_wait_cnt = 0;

	SCR1 = 0x00;		/* シリアルコントロールレジスタ */
	SMR1 = 0x00;		/* シリアルモードレジスタ */
	BRR1 = 80;			/* ビットレートレジスタ(25MHz 9600bps) */

	/* 1bit期間待つ */
	/* 9600bpsのとき0.1041666...ms */
	/* 加算処理が一回80ns(25MHz時)として */
	for( u16t_wait_cnt = 0 ; u16t_wait_cnt < 1302 ; u16t_wait_cnt++ )
	{
		/* 処理なし */
	}

	SCR1 = /*BIT_7 |*/		/* 送信データエンプティ割り込み */
			 BIT_6 |		/* 受信データフル割り込み */
			 BIT_5 |		/* トランスミットイネーブル(TE) */
			 BIT_4;			/* レシーブイネーブル(RE) */
			 /*BIT_3 |*/	/* マルチプロセッサインターラプトイネーブル */
			 /*BIT_2 |*/	/* トランスミットエンドインターラプトイネーブル */
			 /*BIT_1 |*/	/* クロックセレクト */
			 /*BIT_0;*/		/* クロックセレクト */
	
	return;
}

/*" function comment"********************************************/
/* 
/*  Function Name   : fnTransSci
/*  Process         : データ送信
/*  Argument        : *u8t_data			データへのポインタ
/*  				   u8t_send_size	データサイズ
/*  Return Value    : 1(TRUE） 成功
/*                    0(FALSE) 失敗
/*  Programmer      : 田中　孝明        2008-1-23
/* << History >>
/* 
/*" function comment end"****************************************/
u8 fnTransSci( u8 *u8t_data, u8 u8t_send_size )
{
	u8 u8t_send_num = 0;

	/* 送信完了まで待つ */
	for(;;)
	{
		/* レジスタが空 */
		if( CHECK_BIT( SSR1 , SCI_TDRE_BIT ) == TRUE )
		{
			/* 送信サイズに達していれば成功を返す */
			if( u8t_send_num >= u8t_send_size )
			{
				return TRUE;
			}
			else
			{
				TDR1 = data[ u8t_send_num ];		/* レジスタにデータセット */
				CLR_BIT( SSR1 , SCI_TDRE_BIT );		/* 送信完了 */
				u8t_send_num++;						/* 送信位置をインクリメント */
			}
		}
	}
}
/*" function comment"********************************************/
/* 
/*  Function Name   : fnReceiveSci
/*  Process         : データ受信
/*  Argument        : なし
/*  Return Value    : 1(TRUE） 成功
/*                    0(FALSE) 失敗
/*  Programmer      : 田中　孝明        2008-1-23
/* << History >>
/* 
/*" function comment end"****************************************/
u8 fnReceiveSci( void )
{
	/* 受信データ有り */
	if( CHECK_BIT( SSR1 , SCI_RDRF_BIT ) == TRUE )
	{
		u8s_receive_data = RDR1;			/* 受信データ格納変数に格納 */
		CLR_BIT( SSR1 , SCI_TDRE_BIT );		/* 完了受信 */
		return TRUE;
	}
}

/*" function comment"********************************************/
/* 
/*  Function Name   : fnInitReceiveData
/*  Process         : 受信データ格納変数の初期化
/*  Argument        : なし
/*  Return Value    : なし
/*  Programmer      : 田中　孝明        2008-1-23
/* << History >>
/* 
/*" function comment end"****************************************/
void fnReceiveSci( void )
{
	u8s_receive_data = 0;
	
	return;
}

/*" function comment"********************************************/
/* 
/*  Function Name   : fnGetReceiveData
/*  Process         : 受信データ格納変数を返す
/*  Argument        : なし
/*  Return Value    : 受信データ
/*  Programmer      : 田中　孝明        2008-1-23
/* << History >>
/* 
/*" function comment end"****************************************/
u8 fnGetReceiveData( void )
{
	return ( u8s_receive_data );
}
