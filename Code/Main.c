/*" FILE COMMENT***************************************************/
/* 
/*  System Name     : ﾒｲﾝ処理
/*  File Name       : Main.c
/*  Module Name     : main
/*  Process         : ﾒｲﾝ処理
/*  Programmer      : 田中　孝明        2008-5-23
/* 
/* << File Version >>
/*
/****" FILE COMMENT END "******************************************/

#include "Common.h"
#include "NormalMode.h"


/*" function comment"********************************************/
/* 
/*  Function Name   : main
/*  Process         : main
/*  Argument        : なし
/*  Return Value    : なし
/*  Programmer      : 田中　孝明        2008-5-23
/* << History >>
/* 
/*" function comment end"****************************************/
void main( void )
{
	/* ﾒｲﾝﾙｰﾌﾟ */
	for(;;)
	{
		fnNormalMode();		/* 通常処理 */
	}
}


