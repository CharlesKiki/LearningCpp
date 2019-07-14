//
//	文件功能:角色移动逻辑 -- 冲刺
//	注：控制角色下落的函数（加速度）在Ekko.cpp中
//
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<time.h>
#include<Windows.h>
#include<graphics.h>
#include"Player_Move.h"
#include"globalParameter.h"		//引入全局变量
#include"collisionDetection.h"	//引入碰撞（在角色会发生位移的函数中）

/*
	函数功能：
*/
void MoveEKKO()
{
	static float SIN, COS;	//记录角度

	AD_in_Air=0;			//控制是否移动

	MOUSEMSG mouse;			//EasyX方法，获取鼠标信息
	mouse.uMsg = false;

	//鼠标事件响应方法
	if (MouseHit())
	{
		mouse = GetMouseMsg();
	}

	//检测是否是鼠标右键触发
	if (mouse.uMsg == WM_RBUTTONDOWN && Dash_Check == 0&&Dash_limit==0)            //准备冲刺
	{
		//system("pause");	//暂停，测试触发成功
		mciSendString("close DashWord", NULL, 0, NULL);
		srand((unsigned)time(NULL));
		int selectMusic = rand() % 3;
		if(selectMusic == 0)
		    mciSendString("open .\\图片资源\\冲刺1.mp3 alias DashWord", NULL, 0, NULL);
		else if(selectMusic==1)
			mciSendString("open .\\图片资源\\冲刺2.mp3 alias DashWord", NULL, 0, NULL);
		else if(selectMusic==2)
			mciSendString("open .\\图片资源\\冲刺3.mp3 alias DashWord", NULL, 0, NULL);
		mciSendString("play DashWord", NULL, 0, NULL);
		Dash_Speed = 11;
		COS = ((mouse.x - Screen_Center_x) / sqrt((mouse.y - Screen_Center_y)*(mouse.y - Screen_Center_y) + (mouse.x - Screen_Center_x)*(mouse.x - Screen_Center_x)));
		SIN= ((mouse.y - Screen_Center_y) / sqrt((mouse.y - Screen_Center_y)*(mouse.y - Screen_Center_y) + (mouse.x - Screen_Center_x)*(mouse.x - Screen_Center_x)));
		Ekko_Speed_x = Dash_Speed * COS;//鼠标位置决定冲刺方向
		Ekko_Speed_y = Dash_Speed * SIN;
		Dash_Check = 1;
		Dash_limit = 1;
		if (!Crash_Wall()&&!Crash_Top()&&!Crash_Ground())
		{
			Ekko_x += Ekko_Speed_x;
			Ekko_y += Ekko_Speed_y;
		}
		else
		{
			Ekko_Speed_x = 0;
			Ekko_Speed_y = 0;
			Dash_Check = 0;
			Dash_limit = 0;

		}

		if (Dash_Check==1)
		{
			Status_check_i = 3;//图形演示变为冲刺
			if (Ekko_Speed_x > 0)
				Ekko_Face = 1;
			else
				Ekko_Face = -1;
			DropOrNot = 1;
			w_check = 1;
			JumpOrNot = 1;
			jump_limit_check = 1;
		}

	}
	else if (Dash_Check == 1)	//冲刺过程不可控
	{
		if (Dash_Speed > 3)
		{
			Dash_Speed -= 0.2;
		}
		Ekko_Speed_x = Dash_Speed * COS;
		Ekko_Speed_y = Dash_Speed * SIN;
		if (Crash_Wall())
		{
			Ekko_Speed_x = 0;
			Dash_Check = 0;
		}

		if (Crash_Top())
		{
			Ekko_Speed_y = 0;
			Dash_Check = 0;
		}

		if (Crash_Ground())
		{
			Ekko_Speed_y = 0;
			Dash_Check = 0;
			Dash_limit = 0;
		}
		if(Dash_Speed<=5)
		{
			Dash_Check = 0;
		}
		Ekko_x += Ekko_Speed_x;
		Ekko_y += Ekko_Speed_y;
	}
	else//非冲刺的情况
	{
	//人物和墙壁高度差距大到 足以脱离开以后，应该立刻解锁
	if (LockedOne_x != -1)
	{
		if (Ekko_y + Ekko_High / 2 <= Land_Top[LockedOne_x] || Ekko_y - Ekko_High / 2 >= Land_Bottom[LockedOne_x])
		{
			LockedOne_x = -1;
		}
	}

	//调试用代码
	//    system("pause");

	if (
		(!(GetAsyncKeyState(0x41) & 0x8000))//什么操作都没有的时候，Status返还为0
		&&
		(!(GetAsyncKeyState(0x44) & 0x8000))
		&&
		(!(GetAsyncKeyState(0x57) & 0x8000))
		/*&&
		(!(GetAsyncKeyState(0x53) & 0x8000))*/             //目前没有s键
		&&
		DropOrNot == 0
		)
	{
		if (Ekko_Speed_x > 0)  //减速
		{
			if (Crash_Wall())                  //解决撞墙一瞬间，速度被重置为0，之后的循环内读取不到
			{
				Acceleration_x = 0;
				Ekko_Speed_x = 0;
				goto loop;
			}

			Acceleration_x = -0.25;
			Ekko_Speed_x += Acceleration_x;
			if (Ekko_Speed_x < 0.2)         //消去 浮点型数误差 可能导致的 速度无法归零 的现象
				Ekko_Speed_x = 0;
			Ekko_x += Ekko_Speed_x;
		}
		else if (Ekko_Speed_x < 0)  //减速
		{
			Acceleration_x = 0.25;
			if (Crash_Wall())                  //解决撞墙一瞬间，速度被重置为0，之后的循环内读取不到
			{
				Acceleration_x = 0;
				Ekko_Speed_x = 0;
				goto loop;
			}
			Ekko_Speed_x += Acceleration_x;
			if (Ekko_Speed_x > -0.2)         //消去 浮点型数误差 可能导致的 速度无法归零 的现象
				Ekko_Speed_x = 0;
			Ekko_x += Ekko_Speed_x;
		}
		Status_check_i = 0;

		//goto loop;
	}
	else if (
		/*(!(GetAsyncKeyState(0x41) & 0x8000))//什么操作都没有的时候,但在空中，返还2                     //检测不到ad键，自然不会检测到撞墙，故先将次注释掉...
		&&
		(!(GetAsyncKeyState(0x44) & 0x8000))
		&&*/
		(!(GetAsyncKeyState(0x57) & 0x8000))
		/*&&
		(!(GetAsyncKeyState(0x53) & 0x8000))*/             //目前没有s键
		&&
		DropOrNot == 1

		)
	{
		//无限跳跃限制：jump_limit_check==1时，和 w 有关的所有操作皆无法执行
		if (!(GetAsyncKeyState(0x57) & 0x8000) && jump_limit_check == 0 && w_check == 1)//注释：使用w_check变量是为了便于与 非跳跃腾空 的情况分离开
		{
			jump_limit_check = 1;
			Ekko_x += Ekko_Speed_x * 0.9;
			goto loop;
		}
		if (
			(GetAsyncKeyState(0x41) & 0x8000)
			||
			(GetAsyncKeyState(0x44) & 0x8000)
			)
		{
			goto loop2;                     //在空中有AD操作时，不再进行原本的位移,跳跃至AD的检测
		}
		if (Crash_Wall())                  //解决撞墙一瞬间，速度被重置为0，之后的循环内读取不到
		{
			Acceleration_x = 0;
			Ekko_Speed_x = 0;
			goto loop;
		}
		Ekko_x += Ekko_Speed_x;
		Status_check_i = 2;
		//goto loop;
	}


    loop2://在空中有AD操作时，不再进行原本的位移


	if ((GetAsyncKeyState(0x41) & 0x8000))                  // a 
	{
		if (Ekko_Speed_x >= -2.5)
		{

			Acceleration_x = -0.1;//获得加速度
			Ekko_Speed_x += Acceleration_x;
		}
		else if (Ekko_Speed_x <= -3)
		{
			Acceleration_x = 0.8;
			Ekko_Speed_x += Acceleration_x;
		}
		if (Crash_Wall())//如果要撞墙
		{
			Acceleration_x = 0;
			Ekko_Speed_x = 0;
			goto loop1;
		}

		if (Ekko_Face == 1)//变换方向
		{
			Ekko_Face = -1;
		}
		Ekko_x += Ekko_Speed_x;	

		if (DropOrNot == 0)
		{
			Status_check_i = 1;
		}
		else if (DropOrNot == 1)//检测空中是否按过AD
		{
			AD_in_Air = 1;
		}
	}
	else if ((GetAsyncKeyState(0x44) & 0x8000))                 // d
	{


		if (Ekko_Speed_x <= 2.5)
		{

			Acceleration_x = 0.1;//获得加速度
			Ekko_Speed_x += Acceleration_x;
		}
		else if (Ekko_Speed_x >= 3)
		{
			Acceleration_x = -0.8;
			Ekko_Speed_x += Acceleration_x;
		}
		if (Crash_Wall())//如果要撞墙
		{
			Acceleration_x = 0;
			Ekko_Speed_x = 0;
			goto loop1;//跳到对w  的检测
		}

		if (Ekko_Face == -1)//变换方向
		{
			Ekko_Face = 1;
		}
		Ekko_x += Ekko_Speed_x;
		if (DropOrNot == 0)
		{
			Status_check_i = 1;
		}
		else if (DropOrNot == 1)//检测空中是否按过AD
		{
			AD_in_Air = 1;
		}
	}

loop1:

	if ((GetAsyncKeyState(0x57) & 0x8000) && jump_limit_check == 0 && w_check == 0)                                                                    // w，跳跃,水平方向不受影响，即需要在操作W时水平位移
	{
		Ekko_Speed_y = -2;          //跳跃初速度
		if (Crash_Top())
		{
			Ekko_Speed_y = 0;
			goto loop;
		}
		LockedOne_y = -1;              //接触锁定，方便其他碰撞判断
		JumpOrNot = 1;
		w_check = 1;

		DropOrNot = 1;
		Status_check_i = 2;          //演示跳跃图

		Ekko_x += Ekko_Speed_x * 0.3;       //起跳时水平加速
	}
	else if ((GetAsyncKeyState(0x57) & 0x8000) && w_check == 1 && jump_limit_check == 0)                                                               //激活w_check后，仍然按着W,但加速没被禁止
	{                                                                                                                                         //此处x坐标直接改变，y坐标由于不跳跃也有可能变化（悬空），其变化放在了Drop
		if (Ekko_Speed_y < 0 && Ekko_Speed_y >= -3.5 && jump_limit_check == 0)//速度在这个范围发生改变
		{
			if (Crash_Top())
			{
				Ekko_Speed_y = 0;
				goto loop;
			}
			Ekko_Speed_y -= 0.11;//该数据必须稍大于Ekko.cpp的Drop函数中的加速度,且差值越小，跳得越高
			if (Crash_Wall())
			{
				Acceleration_x = 0;
				Ekko_Speed_x = 0;
			}
			if(AD_in_Air==0)//防止空中加速
			Ekko_x += Ekko_Speed_x * 0.3;
		}
		if (Ekko_Speed_y <= -3.6)//极限情况，无法再加速
		{
			jump_limit_check = 1;
			if (Crash_Wall())
			{
				Acceleration_x = 0;
				Ekko_Speed_x = 0;
			}
			if (AD_in_Air == 0)//防止空中加速
			Ekko_x += Ekko_Speed_x * 0.3;
		}
	}
	//无限跳跃限制：jump_limit_check==1时，和 w 有关的所有操作皆无法执行

	else if (((GetAsyncKeyState(0x57) & 0x8000)) && jump_limit_check == 1 && w_check == 1)//空中空按W，这一处是防止先按W+A，然后松开A留下W，水平位移骤停的情况（补充一个水平坐标变化）
	{
		if (Crash_Wall())
		{
			Acceleration_x = 0;
			Ekko_Speed_x = 0;
		}
		if (AD_in_Air == 0)//防止空中加速
		Ekko_x += Ekko_Speed_x;
	}

	if (w_check == 1 && jump_limit_check == 1 && JumpOrNot == 1 && Ekko_Speed_y >= 0)
	{
		JumpOrNot = 0;
	}
	 }

loop://什么都不按的时候调至此

//------------------------------------------时停------------------------------------
	 if ((GetAsyncKeyState(0x45) & 0x8000)&&SlowLimit>0)           //按E
	 {
		 if (SlowOrNot == 0)
		 {
			 int selectMusic = rand() % 2;
			 mciSendString("close SlowWord", NULL, 0, NULL);
			 if (selectMusic == 0)
				 mciSendString("open .\\图片资源\\时停1.mp3 alias SlowWord", NULL, 0, NULL);
			 else if(selectMusic==1)
				 mciSendString("open .\\图片资源\\时停2.mp3 alias SlowWord", NULL, 0, NULL);
			 mciSendString("play SlowWord", NULL, 0, NULL);
			 SlowLimit--;
			 Start_Time = GetTickCount();
			 SlowOrNot = 1;
		 }
	 }




//影响DropOrNot的其他因素   在Ekko_Drop.cpp的函数中
	if (DropOrNot == 0)
	{
		Ekko_Speed_y = 0;
		w_check = 0;
		jump_limit_check = 0;
	}
}