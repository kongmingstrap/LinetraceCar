#ifndef INC__COMMON_H
#define INC__COMMON_H

/*" FILE COMMENT***************************************************/
/* 
/*  System Name     : 共通項目の定義
/*  File Name       : common.h
/*  Module Name     : common
/*  Process         : 共通項目の定義
/*  Programmer      : T.hasegawa        2008-5-21
/* 
/* << File Version >>
/*
/****" FILE COMMENT END "******************************************/

/*==================================================================*/
/*							変更不要								*/
/*==================================================================*/

/* 真偽判定用、変更しないように！ */
enum
{
	  FALSE		/* 0 */
	, TRUE		/* 1 */
};

/* ﾋﾞｯﾄ */
/* SET_BIT,CLR_BIT,TOGGLE_BIT,CHECK_BITで指定してはいけない */
enum
{
	  BIT_0 = 0x01			/* 0bit目 */
	, BIT_1 = 0x01 << 1		/* 1bit目 */
	, BIT_2 = 0x01 << 2		/* 2bit目 */
	, BIT_3 = 0x01 << 3		/* 3bit目 */
	, BIT_4 = 0x01 << 4		/* 4bit目 */
	, BIT_5 = 0x01 << 5		/* 5bit目 */
	, BIT_6 = 0x01 << 6		/* 6bit目 */
	, BIT_7 = 0x01 << 7		/* 7bit目 */
};

/*==================================================================*/
/*							型定義									*/
/*==================================================================*/
/* 型定義 */
typedef 	signed char 		s8;
typedef 	unsigned char 		u8;
typedef 	signed short 		s16;
typedef 	unsigned short 		u16;
typedef 	signed long 		s32;
typedef 	unsigned long 		u32;

/* BITﾌｨｰﾙﾄﾞ構造体定義 */
typedef struct
{
	u8 b7: 1;
	u8 b6: 1;
	u8 b5: 1;
	u8 b4: 1;
	u8 b3: 1;
	u8 b2: 1;
	u8 b1: 1;
	u8 b0: 1;
}bit;

/*==================================================================*/
/*						BIT操作ﾏｸﾛ定義								*/
/*==================================================================*/
/* targetのbitで指定したビットを1にする */
#define SET_BIT( target , bit )			( ( target ) |=  ( BIT_0 << ( bit ) ) )
/* targetのbitで指定したビットを0にする */
#define CLR_BIT( target , bit )			( ( target ) &= ~( BIT_0 << ( bit ) ) )
/* targetのbitで指定したビットの0/1を反転する */
#define TOGGLE_BIT( target , bit )		( ( target ) ^=  ( BIT_0 << ( bit ) ) )
/* targetのbitで指定したビットの0/1を判定する */
#define CHECK_BIT( target , bit )		( ( target ) &   ( BIT_0 << ( bit ) ) )

/*==================================================================*/
/*						変更可能な設定値							*/
/*==================================================================*/

/*------------------------------------------------------------------*/
/*							CPU動作ｸﾛｯｸ								*/
/*------------------------------------------------------------------*/
/* 動作ｸﾛｯｸ */
#define CPU_CLOCK_HZ					( 25000000 )

/*------------------------------------------------------------------*/
/*							AD変換ﾎﾟｰﾄ								*/
/*------------------------------------------------------------------*/

#define COMMON_RIGHT_SENSOR_PORT		( AN0 )
#define COMMON_CENTER_SENSOR_PORT		( AN1 )
#define COMMON_LEFT_SENSOR_PORT			( AN2 )

/*------------------------------------------------------------------*/
/*							ﾓｰﾀｰﾎﾟｰﾄ								*/
/*------------------------------------------------------------------*/

#define COMMON_RIGHT_MOTOR_CW_PORT		( D0 )
#define COMMON_RIGHT_MOTOR_CCW_PORT		( D1 )
#define COMMON_LEFT_MOTOR_CW_PORT		( D2 )
#define COMMON_LEFT_MOTOR_CCW_PORT		( D3 )

#endif	/* INC__COMMON_H */
