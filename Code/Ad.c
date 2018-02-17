/*" FILE COMMENT***************************************************/
/* 
/*  System Name     : AD�ϊ�
/*  File Name       : Ad.c
/*  Module Name     : Ad
/*  Process         : AD�ϊ�
/*  Programmer      : �c���@�F��        2008-5-23
/* 
/* << File Version >>
/*
/****" FILE COMMENT END "******************************************/

#include "Common.h"
#include "Ad.h"

/*==================================================================*/
/*							�萔�錾								*/
/*==================================================================*/
#define RIGHT_SENSOR_PORT		( COMMON_RIGHT_SENSOR_PORT )
#define CENTER_SENSOR_PORT		( COMMON_CENTER_SENSOR_PORT )
#define LEFT_SENSOR_PORT		( COMMON_LEFT_SENSOR_PORT )

/*==================================================================*/
/*							���֐��錾							*/
/*==================================================================*/

/*==================================================================*/
/*							�ÓI�ϐ��錾							*/
/*==================================================================*/

/*==================================================================*/
/*							�ÓI�֐��錾							*/
/*==================================================================*/

/*" function comment"********************************************/
/* 
/*  Function Name   : fnInitSci
/*  Process         : �V���A���ʐM���W�X�^������
/*  Argument        : �Ȃ�
/*  Return Value    : �Ȃ�
/*  Programmer      : �c���@�F��        2008-1-23
/* << History >>
/* 
/*" function comment end"****************************************/
void fnInitSci( void )
{
	volatile u16 u16t_wait_cnt = 0;

	SCR1 = 0x00;		/* �V���A���R���g���[�����W�X�^ */
	SMR1 = 0x00;		/* �V���A�����[�h���W�X�^ */
	BRR1 = 80;			/* �r�b�g���[�g���W�X�^(25MHz 9600bps) */

	/* 1bit���ԑ҂� */
	/* 9600bps�̂Ƃ�0.1041666...ms */
	/* ���Z���������80ns(25MHz��)�Ƃ��� */
	for( u16t_wait_cnt = 0 ; u16t_wait_cnt < 1302 ; u16t_wait_cnt++ )
	{
		/* �����Ȃ� */
	}

	SCR1 = /*BIT_7 |*/		/* ���M�f�[�^�G���v�e�B���荞�� */
			 BIT_6 |		/* ��M�f�[�^�t�����荞�� */
			 BIT_5 |		/* �g�����X�~�b�g�C�l�[�u��(TE) */
			 BIT_4;			/* ���V�[�u�C�l�[�u��(RE) */
			 /*BIT_3 |*/	/* �}���`�v���Z�b�T�C���^�[���v�g�C�l�[�u�� */
			 /*BIT_2 |*/	/* �g�����X�~�b�g�G���h�C���^�[���v�g�C�l�[�u�� */
			 /*BIT_1 |*/	/* �N���b�N�Z���N�g */
			 /*BIT_0;*/		/* �N���b�N�Z���N�g */
	
	return;
}

/*" function comment"********************************************/
/* 
/*  Function Name   : fnTransSci
/*  Process         : �f�[�^���M
/*  Argument        : *u8t_data			�f�[�^�ւ̃|�C���^
/*  				   u8t_send_size	�f�[�^�T�C�Y
/*  Return Value    : 1(TRUE�j ����
/*                    0(FALSE) ���s
/*  Programmer      : �c���@�F��        2008-1-23
/* << History >>
/* 
/*" function comment end"****************************************/
u8 fnTransSci( u8 *u8t_data, u8 u8t_send_size )
{
	u8 u8t_send_num = 0;

	/* ���M�����܂ő҂� */
	for(;;)
	{
		/* ���W�X�^���� */
		if( CHECK_BIT( SSR1 , SCI_TDRE_BIT ) == TRUE )
		{
			/* ���M�T�C�Y�ɒB���Ă���ΐ�����Ԃ� */
			if( u8t_send_num >= u8t_send_size )
			{
				return TRUE;
			}
			else
			{
				TDR1 = data[ u8t_send_num ];		/* ���W�X�^�Ƀf�[�^�Z�b�g */
				CLR_BIT( SSR1 , SCI_TDRE_BIT );		/* ���M���� */
				u8t_send_num++;						/* ���M�ʒu���C���N�������g */
			}
		}
	}
}
/*" function comment"********************************************/
/* 
/*  Function Name   : fnReceiveSci
/*  Process         : �f�[�^��M
/*  Argument        : �Ȃ�
/*  Return Value    : 1(TRUE�j ����
/*                    0(FALSE) ���s
/*  Programmer      : �c���@�F��        2008-1-23
/* << History >>
/* 
/*" function comment end"****************************************/
u8 fnReceiveSci( void )
{
	/* ��M�f�[�^�L�� */
	if( CHECK_BIT( SSR1 , SCI_RDRF_BIT ) == TRUE )
	{
		u8s_receive_data = RDR1;			/* ��M�f�[�^�i�[�ϐ��Ɋi�[ */
		CLR_BIT( SSR1 , SCI_TDRE_BIT );		/* ������M */
		return TRUE;
	}
}

/*" function comment"********************************************/
/* 
/*  Function Name   : fnInitReceiveData
/*  Process         : ��M�f�[�^�i�[�ϐ��̏�����
/*  Argument        : �Ȃ�
/*  Return Value    : �Ȃ�
/*  Programmer      : �c���@�F��        2008-1-23
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
/*  Process         : ��M�f�[�^�i�[�ϐ���Ԃ�
/*  Argument        : �Ȃ�
/*  Return Value    : ��M�f�[�^
/*  Programmer      : �c���@�F��        2008-1-23
/* << History >>
/* 
/*" function comment end"****************************************/
u8 fnGetReceiveData( void )
{
	return ( u8s_receive_data );
}
