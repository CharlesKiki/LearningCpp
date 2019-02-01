#include<globalParameter.h>
#include<graphics.h>
#include<conio.h>

/*
	功能:根据状态绘制游戏角色
*/
void Ekko_Show()
{
	//Ekko下落到一定程度时，屏幕不再下落
	if (Ekko_y > 1700)
	{
		Screen_Center_y = 800 / 2 + (Ekko_y - 1700)/3;
	}
	else
		Screen_Center_y = 800 / 2;



	if (Status_check_i == 0)//站立显示
	{
		if (Ekko_Face == 1)//向右
		{
			if (Ekko_Stand_Count >= 1 && Ekko_Stand_Count <= 180)//方便debug的时候检查
			{
				if (Ekko_Stand_Count == 180)
				{
					putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Stand_1_mask, NOTSRCERASE);
					putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Stand_1, SRCINVERT);
					Ekko_Stand_Count = 1;
				}
				else if (Ekko_Stand_Count >= 1 && Ekko_Stand_Count < 45)
				{
					putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Stand_1_mask, NOTSRCERASE);
					putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Stand_1, SRCINVERT);
					Ekko_Stand_Count++;
				}
				else if (Ekko_Stand_Count >= 45 && Ekko_Stand_Count < 95)
				{
					putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Stand_2_mask, NOTSRCERASE);
					putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Stand_2, SRCINVERT);
					Ekko_Stand_Count++;
				}
				else if (Ekko_Stand_Count >= 95 && Ekko_Stand_Count < 180)
				{
					putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Stand_3_mask, NOTSRCERASE);
					putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Stand_3, SRCINVERT);
					Ekko_Stand_Count++;
				}
			}//以上为向右站立显示
		}
		else if (Ekko_Face == -1)//向左
		{
			if (Ekko_Stand_Count >= 1 && Ekko_Stand_Count <= 300)//方便debug的时候检查
			{
				if (Ekko_Stand_Count == 180)
				{
					putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Stand_1_OPPOSITE_mask, NOTSRCERASE);
					putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Stand_1_OPPOSITE, SRCINVERT);
					Ekko_Stand_Count = 1;
				}
				else if (Ekko_Stand_Count >= 1 && Ekko_Stand_Count < 45)
				{
					putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Stand_1_OPPOSITE_mask, NOTSRCERASE);
					putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Stand_1_OPPOSITE, SRCINVERT);
					Ekko_Stand_Count++;
				}
				else if (Ekko_Stand_Count >= 45 && Ekko_Stand_Count < 95)
				{
					putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Stand_2_OPPOSITE_mask, NOTSRCERASE);
					putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Stand_2_OPPOSITE, SRCINVERT);
					Ekko_Stand_Count++;
				}
				else if (Ekko_Stand_Count >= 95 && Ekko_Stand_Count < 180)
				{
					putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Stand_3_OPPOSITE_mask, NOTSRCERASE);
					putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Stand_3_OPPOSITE, SRCINVERT);
					Ekko_Stand_Count++;
				}
			}//以上为反向站立显示
		}

	}
	else if (Status_check_i == 1)//跑动显示
	{
		if (Ekko_Face == 1)//向右
		{
			if (Ekko_Run_Count >= 1 && Ekko_Run_Count <= Ekko_Run_Frequency * 8)//方便debug用的范围
			{
				if (Ekko_Run_Count >= 1 && Ekko_Run_Count < Ekko_Run_Frequency)
				{
					putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Run_1_mask, NOTSRCERASE);
					putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Run_1, SRCINVERT);
					Ekko_Run_Count++;
				}
				else if (Ekko_Run_Count >= Ekko_Run_Frequency && Ekko_Run_Count < Ekko_Run_Frequency * 2)
				{
					putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Run_2_mask, NOTSRCERASE);
					putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Run_2, SRCINVERT);
					Ekko_Run_Count++;
				}
				else if (Ekko_Run_Count >= Ekko_Run_Frequency * 2 && Ekko_Run_Count < Ekko_Run_Frequency * 3)
				{
					putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Run_3_mask, NOTSRCERASE);
					putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Run_3, SRCINVERT);
					Ekko_Run_Count++;
				}
				else if (Ekko_Run_Count >= Ekko_Run_Frequency * 3 && Ekko_Run_Count < Ekko_Run_Frequency * 4)
				{
					putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Run_4_mask, NOTSRCERASE);
					putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Run_4, SRCINVERT);
					Ekko_Run_Count++;
				}
				else if (Ekko_Run_Count >= Ekko_Run_Frequency * 4 && Ekko_Run_Count < Ekko_Run_Frequency * 5)
				{
					putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Run_5_mask, NOTSRCERASE);
					putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Run_5, SRCINVERT);
					Ekko_Run_Count++;
				}
				else if (Ekko_Run_Count >= Ekko_Run_Frequency * 5 && Ekko_Run_Count < Ekko_Run_Frequency * 6)
				{
					putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Run_6_mask, NOTSRCERASE);
					putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Run_6, SRCINVERT);
					Ekko_Run_Count++;
				}
				else if (Ekko_Run_Count >= Ekko_Run_Frequency * 6 && Ekko_Run_Count < Ekko_Run_Frequency * 7)
				{
					putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Run_7_mask, NOTSRCERASE);
					putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Run_7, SRCINVERT);
					Ekko_Run_Count++;
				}
				else if (Ekko_Run_Count >= Ekko_Run_Frequency * 7 && Ekko_Run_Count < Ekko_Run_Frequency * 8)
				{
					putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Run_8_mask, NOTSRCERASE);
					putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Run_8, SRCINVERT);
					Ekko_Run_Count++;
				}
				else if (Ekko_Run_Count == Ekko_Run_Frequency * 8)
				{
					putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Run_8_mask, NOTSRCERASE);
					putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Run_8, SRCINVERT);
					Ekko_Run_Count = 1;
				}
			}


			////测试
			//putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2,&img_planeNormal1, NOTSRCERASE);//显示正常飞机,zhezhao
			//putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &img_planeNormal2, SRCINVERT);//tupian
		}//以上为跑动时的检测


		else if (Ekko_Face == -1)//向左
		{
			if (Ekko_Run_Count >= 1 && Ekko_Run_Count <= Ekko_Run_Frequency * 8)//方便debug用的范围
			{
				if (Ekko_Run_Count >= 1 && Ekko_Run_Count < Ekko_Run_Frequency)
				{
					putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Run_1_OPPOSITE_mask, NOTSRCERASE);
					putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Run_1_OPPOSITE, SRCINVERT);
					Ekko_Run_Count++;
				}
				else if (Ekko_Run_Count >= Ekko_Run_Frequency && Ekko_Run_Count < Ekko_Run_Frequency * 2)
				{
					putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Run_2_OPPOSITE_mask, NOTSRCERASE);
					putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Run_2_OPPOSITE, SRCINVERT);
					Ekko_Run_Count++;
				}
				else if (Ekko_Run_Count >= Ekko_Run_Frequency * 2 && Ekko_Run_Count < Ekko_Run_Frequency * 3)
				{
					putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Run_3_OPPOSITE_mask, NOTSRCERASE);
					putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Run_3_OPPOSITE, SRCINVERT);
					Ekko_Run_Count++;
				}
				else if (Ekko_Run_Count >= Ekko_Run_Frequency * 3 && Ekko_Run_Count < Ekko_Run_Frequency * 4)
				{
					putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Run_4_OPPOSITE_mask, NOTSRCERASE);
					putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Run_4_OPPOSITE, SRCINVERT);
					Ekko_Run_Count++;
				}
				else if (Ekko_Run_Count >= Ekko_Run_Frequency * 4 && Ekko_Run_Count < Ekko_Run_Frequency * 5)
				{
					putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Run_5_OPPOSITE_mask, NOTSRCERASE);
					putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Run_5_OPPOSITE, SRCINVERT);
					Ekko_Run_Count++;
				}
				else if (Ekko_Run_Count >= Ekko_Run_Frequency * 5 && Ekko_Run_Count < Ekko_Run_Frequency * 6)
				{
					putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Run_6_OPPOSITE_mask, NOTSRCERASE);
					putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Run_6_OPPOSITE, SRCINVERT);
					Ekko_Run_Count++;
				}
				else if (Ekko_Run_Count >= Ekko_Run_Frequency * 6 && Ekko_Run_Count < Ekko_Run_Frequency * 7)
				{
					putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Run_7_OPPOSITE_mask, NOTSRCERASE);
					putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Run_7_OPPOSITE, SRCINVERT);
					Ekko_Run_Count++;
				}
				else if (Ekko_Run_Count >= Ekko_Run_Frequency * 7 && Ekko_Run_Count < Ekko_Run_Frequency * 8)
				{
					putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Run_8_OPPOSITE_mask, NOTSRCERASE);
					putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Run_8_OPPOSITE, SRCINVERT);
					Ekko_Run_Count++;
				}
				else if (Ekko_Run_Count == Ekko_Run_Frequency * 8)
				{
					putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Run_8_OPPOSITE_mask, NOTSRCERASE);
					putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Run_8_OPPOSITE, SRCINVERT);
					Ekko_Run_Count = 1;
				}

			}
		}//以上为跑动时的检测
	}
	else if (Status_check_i == 2) //下落
	{
		//此处数值变化与Move函数的y轴速度变化密切相关

		if (Ekko_Face == 1)//right
		{
			if (JumpOrNot == 1 && DropOrNot == 1 && jump_limit_check == 0 && w_check == 1)
			{
				putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Jump_1_mask, NOTSRCERASE);
				putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Jump_1, SRCINVERT);
			}
			else if (JumpOrNot == 1 && DropOrNot == 1 && jump_limit_check == 1 && w_check == 1 && Ekko_Speed_y < -0.2)
			{
				putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Jump_2_mask, NOTSRCERASE);
				putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Jump_2, SRCINVERT);
			}
			else if (JumpOrNot == 1 && DropOrNot == 1 && jump_limit_check == 1 && w_check == 1 && Ekko_Speed_y > -0.2)
			{
				putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Jump_3_mask, NOTSRCERASE);
				putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Jump_3, SRCINVERT);
			}
			else /*if (JumpOrNot == 0 && DropOrNot == 1)*/
			{
				putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &img_Ekko_Fall_mask, NOTSRCERASE);
				putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &img_Ekko_Fall, SRCINVERT);
			}
		}
		else if (Ekko_Face == -1)//left
		{
			if (JumpOrNot == 1 && DropOrNot == 1 && jump_limit_check == 0 && w_check == 1)
			{
				putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Jump_1_OPPOSITE_mask, NOTSRCERASE);
				putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Jump_1_OPPOSITE, SRCINVERT);
			}
			else if (JumpOrNot == 1 && DropOrNot == 1 && jump_limit_check == 1 && w_check == 1 && Ekko_Speed_y < -0.2)
			{
				putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Jump_2_OPPOSITE_mask, NOTSRCERASE);
				putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Jump_2_OPPOSITE, SRCINVERT);
			}
			else if (JumpOrNot == 1 && DropOrNot == 1 && jump_limit_check == 1 && w_check == 1 && Ekko_Speed_y > -0.2)
			{
				putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Jump_3_OPPOSITE_mask, NOTSRCERASE);
				putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Jump_3_OPPOSITE, SRCINVERT);
			}
			else /*if (JumpOrNot == 0 && DropOrNot == 1)*/
			{
				putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &img_Ekko_Fall_OPPOSITE_mask, NOTSRCERASE);
				putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &img_Ekko_Fall_OPPOSITE, SRCINVERT);
			}
		}

	}
	else if (Status_check_i == 3)
	{
	if (Ekko_Face == 1)
	{
		putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Dash_up_mask, NOTSRCERASE);
		putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Dash_up, SRCINVERT);
	}
	else
	{
		putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Dash_up_mask_OPPOSITE, NOTSRCERASE);
		putimage(Screen_Center_x - Ekko_Width / 2, Screen_Center_y - Ekko_High / 2, &Ekko_Dash_up_OPPOSITE, SRCINVERT);
	}
    }
}