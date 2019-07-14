//
//	文件功能：角色掉落状态
//
//
//
//

#include<Windows.h>
#include"globalParameter.h"		//引入全局变量
#include"collisionDetection.h"	//引入碰撞（在角色会发生位移的函数中）

/*
	功能：
	注：
		下落方向为正方向
		该函数的声明在Player_Move.h中
*/
void Drop_Ekko()       
{
	if (Dash_Check == 1)//冲刺时Drop不运行
	{
		;
	}
	else
	{
		if (DropOrNot == 0 && Crash_Ground())//平底踩空下滑
		{
			DropOrNot = 1;
			Status_check_i = 2;
			JumpOrNot = 1;
			jump_limit_check = 1;
			w_check = 1;
		}

		if (DropOrNot == 1 && !Crash_Ground())//调试用, crash_ground返还1时为要碰撞，不碰撞时返还0,所以用上了  ！
		{
			Status_check_i = 2;//图片演示发生变化
			if (Crash_Top())
			{
				Ekko_Speed_y *= -1;       //竖直方向速度完全变反
				goto ChangeSpeedY;
			}
			Ekko_Speed_y += 0.06;
			Ekko_y += Ekko_Speed_y;
		}
		else if (DropOrNot == 1 && Crash_Ground())//这句话的功能是   EKKO着陆时的变化,此时出现了crash_ground返还1
		{
			Status_check_i = 1;
			Ekko_y = Land_Top[LockedOne_y] - Ekko_High / 2;
			Ekko_Speed_y = 0;
			DropOrNot = 0;
			Dash_limit = 0;
		}

	ChangeSpeedY:;

		if (Status_check_i != 0 && Status_check_i != 1 && Status_check_i != 2)//检测图形是否出错
		{
			system("pause");
			exit(0);
		}
	}
	
}