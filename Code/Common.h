#ifndef INC__COMMON_H
#define INC__COMMON_H

/*" FILE COMMENT***************************************************/
/* 
/*  System Name     : ���ʍ��ڂ̒�`
/*  File Name       : common.h
/*  Module Name     : common
/*  Process         : ���ʍ��ڂ̒�`
/*  Programmer      : T.hasegawa        2008-5-21
/* 
/* << File Version >>
/*
/****" FILE COMMENT END "******************************************/

/*==================================================================*/
/*							�ύX�s�v								*/
/*==================================================================*/

/* �^�U����p�A�ύX���Ȃ��悤�ɁI */
enum
{
	  FALSE		/* 0 */
	, TRUE		/* 1 */
};

/* �ޯ� */
/* SET_BIT,CLR_BIT,TOGGLE_BIT,CHECK_BIT�Ŏw�肵�Ă͂����Ȃ� */
enum
{
	  BIT_0 = 0x01			/* 0bit�� */
	, BIT_1 = 0x01 << 1		/* 1bit�� */
	, BIT_2 = 0x01 << 2		/* 2bit�� */
	, BIT_3 = 0x01 << 3		/* 3bit�� */
	, BIT_4 = 0x01 << 4		/* 4bit�� */
	, BIT_5 = 0x01 << 5		/* 5bit�� */
	, BIT_6 = 0x01 << 6		/* 6bit�� */
	, BIT_7 = 0x01 << 7		/* 7bit�� */
};

/*==================================================================*/
/*							�^��`									*/
/*==================================================================*/
/* �^��` */
typedef 	signed char 		s8;
typedef 	unsigned char 		u8;
typedef 	signed short 		s16;
typedef 	unsigned short 		u16;
typedef 	signed long 		s32;
typedef 	unsigned long 		u32;

/* BIT̨���ލ\���̒�` */
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
/*						BIT����ϸے�`								*/
/*==================================================================*/
/* target��bit�Ŏw�肵���r�b�g��1�ɂ��� */
#define SET_BIT( target , bit )			( ( target ) |=  ( BIT_0 << ( bit ) ) )
/* target��bit�Ŏw�肵���r�b�g��0�ɂ��� */
#define CLR_BIT( target , bit )			( ( target ) &= ~( BIT_0 << ( bit ) ) )
/* target��bit�Ŏw�肵���r�b�g��0/1�𔽓]���� */
#define TOGGLE_BIT( target , bit )		( ( target ) ^=  ( BIT_0 << ( bit ) ) )
/* target��bit�Ŏw�肵���r�b�g��0/1�𔻒肷�� */
#define CHECK_BIT( target , bit )		( ( target ) &   ( BIT_0 << ( bit ) ) )

/*==================================================================*/
/*						�ύX�\�Ȑݒ�l							*/
/*==================================================================*/

/*------------------------------------------------------------------*/
/*							CPU����ۯ�								*/
/*------------------------------------------------------------------*/
/* ����ۯ� */
#define CPU_CLOCK_HZ					( 25000000 )

/*------------------------------------------------------------------*/
/*							AD�ϊ��߰�								*/
/*------------------------------------------------------------------*/

#define COMMON_RIGHT_SENSOR_PORT		( AN0 )
#define COMMON_CENTER_SENSOR_PORT		( AN1 )
#define COMMON_LEFT_SENSOR_PORT			( AN2 )

/*------------------------------------------------------------------*/
/*							Ӱ���߰�								*/
/*------------------------------------------------------------------*/

#define COMMON_RIGHT_MOTOR_CW_PORT		( D0 )
#define COMMON_RIGHT_MOTOR_CCW_PORT		( D1 )
#define COMMON_LEFT_MOTOR_CW_PORT		( D2 )
#define COMMON_LEFT_MOTOR_CCW_PORT		( D3 )

#endif	/* INC__COMMON_H */
