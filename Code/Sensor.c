/*" FILE COMMENT***************************************************/
/* 
/*  System Name     : �ݻ�����
/*  File Name       : Sensor.c
/*  Module Name     : Sensor
/*  Process         : �ݻ�����
/*  Programmer      : �c���@�F��        2008-5-23
/* 
/* << File Version >>
/*
/****" FILE COMMENT END "******************************************/

#include "Common.h"
#include "Sensor.h"
#include "Ad.h"

/*==================================================================*/
/*							�萔�錾								*/
/*==================================================================*/

/*==================================================================*/
/*							���֐��錾							*/
/*==================================================================*/

/*==================================================================*/
/*							�ÓI�ϐ��錾							*/
/*==================================================================*/

/*==================================================================*/
/*							�ÓI�֐��錾							*/
/*==================================================================*/

/* AD�l�i�[�z�� */
static u16 u16s_getad[ ALL_SENSOR_NUM ];

/*" function comment"********************************************/
/* 
/*  Function Name   : fnInitSensor
/*  Process         : �ݻ�������
/*  Argument        : �Ȃ�
/*  Return Value    : �Ȃ�
/*  Programmer      : �c���@�F��        2008-5-23
/* << History >>
/* 
/*" function comment end"****************************************/
void fnInitSensor( void )
{
	u8 u8_cnt;
	/* AD�l�i�[�z��̗v�f�������� */
	for( u8_cnt = 0;u8_cnt < ALL_SENSOR_NUM;i++ )
	{
		u16s_getad[u8_cnt] = 0;
	}
	
	return;
}


/*" function comment"********************************************/
/* 
/*  Function Name   : fnSensorCheck
/*  Process         : �ݻ�����
/*  Argument        : �Ȃ�
/*  Return Value    : �Ȃ�
/*  Programmer      : �c���@�F��        2008-5-23
/* << History >>
/* 
/*" function comment end"****************************************/
void fnSensorCheck( void )
{
	u8 u8_cnt;
	/* AD�߰Ċi�[�z��̗v�f��AD�l���擾 */
	for( u8_cnt = 0;u8_cnt < ALL_SENSOR_NUM;i++ )
	{
		fnAdCheck( u8_cnt );
	}
	
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
