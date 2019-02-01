/*
	文件作用：碰撞效果实现
*/
#include<globalParameter.h>
#include<Windows.h>
#include<math.h>

/*
	功能：
*/
int ABS(float A, float B)        //float型绝对值。单独定义并且用在下面的函数中
{
	float C;
	C = A - B;
	if (C >= 0)
	{
		return C;
	}
	else
	{
		C = (-1)*C;
		return C;
	}
}



/*
	功能：墙体碰撞判断，判断是否即将和地形碰撞。
	返回：即将 碰撞 返还 1 ，否则返还 0
*/
int Crash_Wall()
{
	for (int i = 0; i < Block_Number; i++)
	{
		if (Ekko_Speed_x > 0)
		{
			if (
				Ekko_x + Ekko_Width / 2 <= Land_Left[i] && Ekko_x + Ekko_Speed_x + Ekko_Width / 2 > Land_Left[i]
				&&
				Ekko_y + Ekko_High / 2 > Land_Top[i] && Ekko_y - Ekko_High / 2 < Land_Bottom[i]
				)
			{
				LockedOne_x = i;
				return 1;
				//break;
			}
			else if (i == LockedOne_x && ABS(Land_Left[i], Ekko_x + Ekko_Width / 2) < 4)
			{
				return 1;
			}

			else
				continue;
		}
		else if (Ekko_Speed_x < 0)
		{
			if (
				Ekko_x - Ekko_Width / 2 >= Land_Right[i] && Ekko_x + Ekko_Speed_x - Ekko_Width / 2 < Land_Right[i]
				&&
				Ekko_y + Ekko_High / 2 > Land_Top[i] && Ekko_y - Ekko_High / 2 < Land_Bottom[i]
				)
			{
				LockedOne_x = i;
				return 1;
				//break;
			}
			else if (i == LockedOne_x && ABS(Ekko_x - Ekko_Width / 2, Land_Right[i]) < 3)
			{
				return 1;
			}
			else
				continue;
		}
		//else if (Ekko_Speed_x == 0 && i == LockedOne_x && Land_Left[i] - (Ekko_x + Ekko_Width / 2) < 3)   //3为测试数据
		//{
		//	return 1;
		//}
		//else if (Ekko_Speed_x == 0 && i == LockedOne_x && (Ekko_x - Ekko_Width / 2)- Land_Right[i]   < 3)   //3为测试数据
		//{
		//	return 1;
//		}
	}
	return 0;
}

/*
	功能：地面碰撞判断，判断和地面是否碰撞
	返回：即将碰撞返还1，否则返还0
	注：踩到地刺的判定，死亡判定
*/
int Crash_Ground()
{
	for (int i = 0; i < Block_Number; i++)
	{
		if (Ekko_Speed_y > 0)
		{
			if (
				Ekko_y + Ekko_High / 2 <= Land_Top[i] && Ekko_y + Ekko_Speed_y + 0.06 + Ekko_High / 2 > Land_Top[i]          //0.06是Y轴方向加速度
				&&
				Ekko_x + Ekko_Width / 2 > Land_Left[i] && Ekko_x - Ekko_Width / 2 < Land_Right[i]
				)
			{
				LockedOne_y = i;
				if (LockedOne_y == 6||LockedOne_y == 7 || LockedOne_y == 8 || LockedOne_y == 11 || LockedOne_y == 12 || LockedOne_y == 44 || LockedOne_y == 45 || LockedOne_y == 46 || LockedOne_y == 64 || LockedOne_y == 65 || LockedOne_y == 66)
					DeadOrNot = 1;
				return 1;
				//break;
			}
			else
				continue;

		}
		else if (DropOrNot == 1 && Ekko_Speed_y == 0)//悬空时速度为0
		{
			return 0;
		}

		else if (DropOrNot == 0 && Ekko_Speed_y == 0 && LockedOne_y == i && (Ekko_x + Ekko_Width / 2 < Land_Left[i] || Ekko_x - Ekko_Width / 2 > Land_Right[i]))//落地后速度为0但是踩空
		{
			
			return 1;
		}
		else if (DropOrNot == 0 && Ekko_Speed_y == 0 && LockedOne_y == i && (Ekko_x - Ekko_Width / 2 < Land_Right[i] && Ekko_x + Ekko_Width / 2 > Land_Left[i]))//落地后速度为0，踩实
		{
			return 0;
		}
		else if (Ekko_Speed_y < 0)
		{
			return 0;
		}
	}
	return 0;
}

/*
	功能：
*/
int Crash_Top()
{
	for (int i = 0; i < Block_Number; i++)
	{
		if (Ekko_Speed_y < 0)
		{
			if (
				Ekko_y - Ekko_High / 2 >= Land_Bottom[i] && Ekko_y + Ekko_Speed_y - Ekko_High / 2 < Land_Bottom[i]
				&&
				Ekko_x + Ekko_Width / 2 > Land_Left[i] && Ekko_x - Ekko_Width / 2 < Land_Right[i]
				)
			{
				LockedOne_y = i;
				return 1;
				//break;
			}
		}
		else
			break;
	}
	return 0;
}