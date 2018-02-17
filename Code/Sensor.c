/*" FILE COMMENT***************************************************/
/* 
/*  System Name     : ｾﾝｻｰ処理
/*  File Name       : Sensor.c
/*  Module Name     : Sensor
/*  Process         : ｾﾝｻｰ処理
/*  Programmer      : 田中　孝明        2008-5-23
/* 
/* << File Version >>
/*
/****" FILE COMMENT END "******************************************/

#include "Common.h"
#include "Sensor.h"
#include "Ad.h"

/*==================================================================*/
/*							定数宣言								*/
/*==================================================================*/

/*==================================================================*/
/*							大域関数宣言							*/
/*==================================================================*/

/*==================================================================*/
/*							静的変数宣言							*/
/*==================================================================*/

/*==================================================================*/
/*							静的関数宣言							*/
/*==================================================================*/

/* AD値格納配列 */
static u16 u16s_getad[ ALL_SENSOR_NUM ];

/*" function comment"********************************************/
/* 
/*  Function Name   : fnInitSensor
/*  Process         : ｾﾝｻｰ初期化
/*  Argument        : なし
/*  Return Value    : なし
/*  Programmer      : 田中　孝明        2008-5-23
/* << History >>
/* 
/*" function comment end"****************************************/
void fnInitSensor( void )
{
	u8 u8_cnt;
	/* AD値格納配列の要素分初期化 */
	for( u8_cnt = 0;u8_cnt < ALL_SENSOR_NUM;i++ )
	{
		u16s_getad[u8_cnt] = 0;
	}
	
	return;
}


/*" function comment"********************************************/
/* 
/*  Function Name   : fnSensorCheck
/*  Process         : ｾﾝｻｰﾁｪｯｸ
/*  Argument        : なし
/*  Return Value    : なし
/*  Programmer      : 田中　孝明        2008-5-23
/* << History >>
/* 
/*" function comment end"****************************************/
void fnSensorCheck( void )
{
	u8 u8_cnt;
	/* ADﾎﾟｰﾄ格納配列の要素分AD値を取得 */
	for( u8_cnt = 0;u8_cnt < ALL_SENSOR_NUM;i++ )
	{
		fnAdCheck( u8_cnt );
	}
	
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
