//
//	文件功能:元素状态初始化，绘制元素 -- 角色，地形，敌人，游戏主逻辑
//	注释：该文件包含了游戏素材的初始化工作，并且含有所有的游戏循环。
//

#include<conio.h>
#include<stdlib.h>
#include<Windows.h>
#include<graphics.h>
#pragma comment(lib,"Winmm.lib")


//以下是包含游戏角色的行动的文件的调用
#include"Ekko_Show.h"     	//包含有艾克的显示，艾克的显示 与上一次循环中Move函数的执行 相关联
#include"Ekko_Move.h"       //包含有Move函数，控制Ekko的水平移动
#include"Ekko_Crash.h"      //引入碰撞（在EKKO会发生位移的函数中）
#include"Start.h"

//以下是定义游戏包含的区域大小
#define MAP_High 2000
#define MAP_Width 6000   //这两个数据我乱编的，后期需要调整

//游戏画面分辨率
#define Scene_Width 1600
#define Scene_High 800  // 将游戏画面 初步定义为1600*800的窗口


//	函数功能:获取角色实际大小
//	场景：根据在画布中像素坐标的调整，各个边缘随着游戏角色的x、y坐标的变化而适应
void ADJUST_EKKO()
{
	Ekko_Left = Ekko_x - Ekko_Width / 2;     
	Ekko_Right = Ekko_x + Ekko_Width / 2;
	Ekko_Top = Ekko_y - Ekko_High / 2;
	Ekko_Bottom = Ekko_y + Ekko_High / 2;
}

//技能 -- 静止世间
void SlowTime()
{
	if (SlowOrNot == 1)
	{
		Running_Time = GetTickCount();
		if (Running_Time - Start_Time <= 5000)
		{
			Sleep(10);
		}
		else
		{
			SlowOrNot = 0;
		}
	}
}

//清除图像（如果需要使用）
void clean()
{

}


//初始化游戏数据
void startup()              
{

	initgraph(Scene_Width, Scene_High);//初始化画布大小


	//以下为LOADIMAGE函数区域
#if 1
	loadimage(&start, _T(".\\图片资源\\开始界面.jpg"));
	loadimage(&end, _T(".\\图片资源\\去世画面.png"));
	//背景图片
	loadimage(&img_Background, _T(".\\图片资源\\祖安（）.jpg"));

	//艾克站立正面
	loadimage(&Ekko_Stand_1, _T(".\\图片资源\\ekko站立\\ekko站立1\\ekko站立1.png"));
	loadimage(&Ekko_Stand_1_mask, _T(".\\图片资源\\ekko站立\\ekko站立1\\ekko站立1底小图（裁）正_mask.bmp"));
	loadimage(&Ekko_Stand_2_mask, _T(".\\图片资源\\ekko站立\\ekko站立2\\ekko站立2小底图（裁）正_mask.bmp"));
	loadimage(&Ekko_Stand_2, _T(".\\图片资源\\ekko站立\\ekko站立2\\ekko站立2.png"));
	loadimage(&Ekko_Stand_3_mask, _T(".\\图片资源\\ekko站立\\ekko站立3\\EKKO站立NO3_M_mask.bmp"));
	loadimage(&Ekko_Stand_3, _T(".\\图片资源\\ekko站立\\ekko站立3\\ekko站立3.png"));
	//艾克站立反面
	loadimage(&Ekko_Stand_1_OPPOSITE_mask, _T(".\\图片资源\\ekko站立\\ekko站立1\\ekko站立1底小图（裁）反_mask.bmp"));//载入图片
	loadimage(&Ekko_Stand_1_OPPOSITE, _T(".\\图片资源\\ekko站立\\ekko站立1\\ekko站立1_反.png"));
	loadimage(&Ekko_Stand_2_OPPOSITE_mask, _T(".\\图片资源\\ekko站立\\ekko站立2\\ekko站立2小底图（裁）反_mask.bmp"));
	loadimage(&Ekko_Stand_2_OPPOSITE, _T(".\\图片资源\\ekko站立\\ekko站立2\\ekko站立2_反.png"));
	loadimage(&Ekko_Stand_3_OPPOSITE_mask, _T(".\\图片资源\\ekko站立\\ekko站立3\\EKKO站立NO3_M_反_mask.bmp"));
	loadimage(&Ekko_Stand_3_OPPOSITE, _T(".\\图片资源\\ekko站立\\ekko站立3\\ekko站立3_反.png"));
	/*----------------------------------------------------艾克跑动------------------------------------------------------*/
	loadimage(&Ekko_Run_1_mask, _T(".\\图片资源\\ekko跑动\\ekko跑动1\\ekko跑动1小底图（裁）正_mask.bmp"));//1
	loadimage(&Ekko_Run_1, _T(".\\图片资源\\ekko跑动\\ekko跑动1\\ekko_Run1.png"));
	loadimage(&Ekko_Run_2_mask, _T(".\\图片资源\\ekko跑动\\ekko跑动2\\ekko跑动2小底图（裁）正_mask.bmp"));//2
	loadimage(&Ekko_Run_2, _T(".\\图片资源\\ekko跑动\\ekko跑动2\\ekko_Run2.png"));
	loadimage(&Ekko_Run_3_mask, _T(".\\图片资源\\ekko跑动\\ekko跑动3\\ekko跑动3小底图（裁）正_mask.bmp"));//3
	loadimage(&Ekko_Run_3, _T(".\\图片资源\\ekko跑动\\ekko跑动3\\ekko_Run3.png"));
	loadimage(&Ekko_Run_4_mask, _T(".\\图片资源\\ekko跑动\\ekko跑动4\\ekko跑动4小底图（裁）正_mask.bmp"));//4
	loadimage(&Ekko_Run_4, _T(".\\图片资源\\ekko跑动\\ekko跑动4\\ekko_Run4.png"));
	loadimage(&Ekko_Run_5_mask, _T(".\\图片资源\\ekko跑动\\ekko跑动5\\ekko跑动5小底图（裁）正_mask.bmp"));//5
	loadimage(&Ekko_Run_5, _T(".\\图片资源\\ekko跑动\\ekko跑动5\\ekko_Run5.png"));
	loadimage(&Ekko_Run_6_mask, _T(".\\图片资源\\ekko跑动\\ekko跑动6\\ekko跑动6小底图（裁）正_mask.bmp"));//6
	loadimage(&Ekko_Run_6, _T(".\\图片资源\\ekko跑动\\ekko跑动6\\ekko_Run6.png"));
	loadimage(&Ekko_Run_7_mask, _T(".\\图片资源\\ekko跑动\\ekko跑动7\\ekko跑动7小底图（裁）正_mask.bmp"));//7
	loadimage(&Ekko_Run_7, _T(".\\图片资源\\ekko跑动\\ekko跑动7\\ekko_Run7.png"));
	loadimage(&Ekko_Run_8_mask, _T(".\\图片资源\\ekko跑动\\ekko跑动8\\ekko跑动8小底图（裁）正_mask.bmp"));//8
	loadimage(&Ekko_Run_8, _T(".\\图片资源\\ekko跑动\\ekko跑动8\\ekko_Run8.png"));

	loadimage(&Ekko_Run_1_OPPOSITE_mask, _T(".\\图片资源\\ekko跑动\\ekko跑动1\\ekko跑动1小底图（裁）反_mask.bmp"));//1
	loadimage(&Ekko_Run_1_OPPOSITE, _T(".\\图片资源\\ekko跑动\\ekko跑动1\\ekko_Run_反.png"));
	loadimage(&Ekko_Run_2_OPPOSITE_mask, _T(".\\图片资源\\ekko跑动\\ekko跑动2\\ekko跑动2小底图（裁）反_mask.bmp"));//2
	loadimage(&Ekko_Run_2_OPPOSITE, _T(".\\图片资源\\ekko跑动\\ekko跑动2\\ekko_Run2_反.png"));
	loadimage(&Ekko_Run_3_OPPOSITE_mask, _T(".\\图片资源\\ekko跑动\\ekko跑动3\\ekko跑动3小底图（裁）反_mask.bmp"));//3
	loadimage(&Ekko_Run_3_OPPOSITE, _T(".\\图片资源\\ekko跑动\\ekko跑动3\\ekko_Run3_反.png"));
	loadimage(&Ekko_Run_4_OPPOSITE_mask, _T(".\\图片资源\\ekko跑动\\ekko跑动4\\ekko跑动4小底图（裁）反_mask.bmp"));//4
	loadimage(&Ekko_Run_4_OPPOSITE, _T(".\\图片资源\\ekko跑动\\ekko跑动4\\ekko_Run4_反.png"));
	loadimage(&Ekko_Run_5_OPPOSITE_mask, _T(".\\图片资源\\ekko跑动\\ekko跑动5\\ekko跑动5小底图（裁）反_mask.bmp"));//5
	loadimage(&Ekko_Run_5_OPPOSITE, _T(".\\图片资源\\ekko跑动\\ekko跑动5\\ekko_Run5_反.png"));
	loadimage(&Ekko_Run_6_OPPOSITE_mask, _T(".\\图片资源\\ekko跑动\\ekko跑动6\\ekko跑动6小底图（裁）反_mask.bmp"));//6
	loadimage(&Ekko_Run_6_OPPOSITE, _T(".\\图片资源\\ekko跑动\\ekko跑动6\\ekko_Run6_反.png"));
	loadimage(&Ekko_Run_7_OPPOSITE_mask, _T(".\\图片资源\\ekko跑动\\ekko跑动7\\ekko跑动7小底图（裁）反_mask.bmp"));//7
	loadimage(&Ekko_Run_7_OPPOSITE, _T(".\\图片资源\\ekko跑动\\ekko跑动7\\ekko_Run7_反.png"));
	loadimage(&Ekko_Run_8_OPPOSITE_mask, _T(".\\图片资源\\ekko跑动\\ekko跑动8\\ekko跑动8小底图（裁）反_mask.bmp"));//8
	loadimage(&Ekko_Run_8_OPPOSITE, _T(".\\图片资源\\ekko跑动\\ekko跑动8\\ekko_Run8_反.png"));
	//--------------------------------------------以上为跑动素材拷用（准备的确实不好= =毕竟自己画的）---------------
	//以下为艾克跳跃
	loadimage(&Ekko_Jump_1_mask, _T(".\\图片资源\\ekko跳跃and下落\\Jump 1\\Ekko_Jump1_裁_mask.bmp"));
	loadimage(&Ekko_Jump_1, _T(".\\图片资源\\ekko跳跃and下落\\Jump 1\\Jump1  WHITE BIG_副本.png"));//1
	loadimage(&Ekko_Jump_2_mask, _T(".\\图片资源\\ekko跳跃and下落\\Jump2\\Ekko_Jump2_M_mask.bmp"));
	loadimage(&Ekko_Jump_2, _T(".\\图片资源\\ekko跳跃and下落\\Jump2\\Jump2 副本.png"));//2
	loadimage(&Ekko_Jump_3_mask, _T(".\\图片资源\\ekko跳跃and下落\\Jump3\\Ekko_Jump3_M_mask.bmp"));
	loadimage(&Ekko_Jump_3, _T(".\\图片资源\\ekko跳跃and下落\\Jump3\\Jump3_副本.png"));//3
	loadimage(&img_Ekko_Fall_mask, _T(".\\图片资源\\ekko跳跃and下落\\Drop\\Ekko_Fall_M_mask.bmp"));
	loadimage(&img_Ekko_Fall, _T(".\\图片资源\\ekko跳跃and下落\\Drop\\Drop_副本.png"));//4

	loadimage(&Ekko_Jump_1_OPPOSITE_mask, _T(".\\图片资源\\ekko跳跃and下落\\Jump 1\\Ekko_Jump1_裁_mask_反.bmp"));
	loadimage(&Ekko_Jump_1_OPPOSITE, _T(".\\图片资源\\ekko跳跃and下落\\Jump 1\\Jump1  WHITE BIG_反.png"));//1
	loadimage(&Ekko_Jump_2_OPPOSITE_mask, _T(".\\图片资源\\ekko跳跃and下落\\Jump2\\Ekko_Jump2_M_mask_反.bmp"));
	loadimage(&Ekko_Jump_2_OPPOSITE, _T(".\\图片资源\\ekko跳跃and下落\\Jump2\\Jump2 副本_反.png"));//2
	loadimage(&Ekko_Jump_3_OPPOSITE_mask, _T(".\\图片资源\\ekko跳跃and下落\\Jump3\\Ekko_Jump3_M_mask_反.bmp"));
	loadimage(&Ekko_Jump_3_OPPOSITE, _T(".\\图片资源\\ekko跳跃and下落\\Jump3\\Jump3_副本_反.png"));//3
	loadimage(&img_Ekko_Fall_OPPOSITE_mask, _T(".\\图片资源\\ekko跳跃and下落\\Drop\\Ekko_Fall_M_mask_反.bmp"));
	loadimage(&img_Ekko_Fall_OPPOSITE, _T(".\\图片资源\\ekko跳跃and下落\\Drop\\Drop_副本_反.png"));//4
	//以下为艾克冲刺
	loadimage(&Ekko_Dash_up, _T(".\\图片资源\\Ekko_Dash\\D_up.png"));
	loadimage(&Ekko_Dash_up_mask, _T(".\\图片资源\\Ekko_Dash\\D_up_M_mask.bmp"));
    loadimage(&Ekko_Dash_up_OPPOSITE, _T(".\\图片资源\\Ekko_Dash\\D_up_副本.png"));
	loadimage(&Ekko_Dash_up_mask_OPPOSITE, _T(".\\图片资源\\Ekko_Dash\\D_up_M_mask_副本.bmp"));

	loadimage(&MAP_trap_1, _T(".\\图片资源\\地图元素\\地刺小图.png"));
	loadimage(&MAP_trap_1_mask, _T(".\\图片资源\\地图元素\\地刺_副本_mask.bmp"));//地刺
	loadimage(&MAP_trap_2, _T(".\\图片资源\\地图元素\\地刺2.png"));
	loadimage(&MAP_trap_2_mask, _T(".\\图片资源\\地图元素\\地刺2副本_mask.bmp"));//地刺
	loadimage(&MAP_trap_3, _T(".\\图片资源\\地图元素\\地刺3.png"));
	loadimage(&MAP_trap_3_mask, _T(".\\图片资源\\地图元素\\地刺3副本_mask.bmp"));//地刺

	loadimage(&MAP_floor_1, _T(".\\图片资源\\地板\\地板1.png"));
	loadimage(&MAP_floor_1_mask, _T(".\\图片资源\\地板\\地板1副本_mask.bmp"));//地板
	loadimage(&MAP_floor_2, _T(".\\图片资源\\地板\\地板2.png"));
	loadimage(&MAP_floor_2_mask, _T(".\\图片资源\\地板\\地板2副本_mask.bmp"));//地板
	loadimage(&MAP_floor_3, _T(".\\图片资源\\地板\\地板3.png"));
	loadimage(&MAP_floor_3_mask, _T(".\\图片资源\\地板\\地板3副本_mask.bmp"));//地板
	loadimage(&MAP_floor_4, _T(".\\图片资源\\地板\\地板4.png"));
	loadimage(&MAP_floor_4_mask, _T(".\\图片资源\\地板\\地板4副本_mask.bmp"));//地板
	loadimage(&MAP_floor_5, _T(".\\图片资源\\地板\\地板5.png"));
	loadimage(&MAP_floor_5_mask, _T(".\\图片资源\\地板\\地板5副本_mask.bmp"));//地板
	loadimage(&MAP_floor_6, _T(".\\图片资源\\地板\\地板6.png"));
	loadimage(&MAP_floor_6_mask, _T(".\\图片资源\\地板\\地板6副本_mask.bmp"));//地板
	loadimage(&MAP_floor_7, _T(".\\图片资源\\地板\\地板7.png"));
	loadimage(&MAP_floor_7_mask, _T(".\\图片资源\\地板\\地板7副本_mask.bmp"));//地板

	loadimage(&MAP_board_1, _T(".\\图片资源\\浮板\\浮砖1.png"));//浮板
	loadimage(&MAP_board_2, _T(".\\图片资源\\浮板\\浮砖2.png"));
	loadimage(&MAP_board_3, _T(".\\图片资源\\浮板\\浮砖3.png"));
	loadimage(&MAP_board_4, _T(".\\图片资源\\浮板\\浮砖4.png"));
	loadimage(&MAP_board_4, _T(".\\图片资源\\浮板\\浮砖4.png"));
	loadimage(&MAP_board_5, _T(".\\图片资源\\浮板\\浮砖5.png"));
	loadimage(&MAP_board_6, _T(".\\图片资源\\浮板\\浮砖6.png"));
	loadimage(&MAP_board_7, _T(".\\图片资源\\浮板\\浮砖7.png"));
	loadimage(&MAP_board_8, _T(".\\图片资源\\浮板\\浮砖8.png"));
	loadimage(&MAP_board_9, _T(".\\图片资源\\浮板\\浮砖9.png"));
	loadimage(&MAP_board_10, _T(".\\图片资源\\浮板\\浮砖10.png"));
	loadimage(&MAP_board_11, _T(".\\图片资源\\浮板\\浮砖11.png"));
	loadimage(&MAP_board_12, _T(".\\图片资源\\浮板\\浮砖12.png"));
	loadimage(&MAP_board_13, _T(".\\图片资源\\浮板\\浮砖13.png"));
	loadimage(&MAP_board_14, _T(".\\图片资源\\浮板\\浮砖14.png"));
	loadimage(&MAP_board_15, _T(".\\图片资源\\浮板\\浮砖15.png"));
	loadimage(&MAP_board_16, _T(".\\图片资源\\浮板\\浮砖16.png"));

	loadimage(&MAP_enemy, _T(".\\图片资源\\地图元素\\圆形炮台.png"));
	loadimage(&MAP_enemy_mask, _T(".\\图片资源\\地图元素\\圆形炮台_副本_mask.bmp"));//弹幕点

	loadimage(&BULLET, _T(".\\图片资源\\地图元素\\子弹.png"));				//子弹
	loadimage(&BULLET_mask, _T(".\\图片资源\\地图元素\\子弹副本_mask.bmp"));

	loadimage(&SlowChance, _T(".\\图片资源\\Ekko的标志.jpg"));
	loadimage(&SlowChance_mask, _T(".\\图片资源\\Ekko的标志_副本_mask.bmp"));



#endif // 加载图片（用#if 1 #endif只是为了能够折叠这一段代码，方便浏览）

	/*
		commit：该参数由实际图片大小与游戏绘制机制决定 -- EasyX画布方法绘制
	*/
	Ekko_High = 64;		//角色大小，请勿轻易修改
	Ekko_Width = 64;   	//角色大小，请勿轻易修改

	/*----------------------部分全局变量的赋值-------------------------------*/

	Status_check_i = 1;		//游戏开始时角色的状态 -- 悬空

	LockedOne_y = 0;		//角色初始位置设定上站在第一个块上

	LockedOne_x = -1;		//初始位置 -- 一开始角色不碰撞任何元素

	Ekko_Face = 1;			//初始方向为向右

	Ekko_Speed_y = 0;		//初始y方向静止

	Ekko_Speed_x = 0;		//初始x方向静止

	DropOrNot = 1;			//开始，不完全重合于平台，有少许下落

	JumpOrNot = 1;			//跳跃状态

	Ekko_Stand_Count = 1; 	//站立状态

	Ekko_Run_Count = 1;		//跑动状态

	Ekko_Run_Frequency = 18;//跑动系数

	jump_limit_check = 1;	//跳跃检查

	w_check = 1;			//输入检查

	Acceleration_x = 0;		//x正方向加速度

	Dash_Check = 0;			//冲刺
	Dash_limit = 1;			//冲刺

	DeadOrNot = 0;          //是否死亡状态

	SlowOrNot = 0;			//技能慢速
	SlowLimit;

	/*-----------------------------------------------------------------------*/


	Map_Status_Setup();    //导入地图数据

	/*
		功能：刷新角色碰撞边缘
		场景：此方法执行前需要初始化角色状态
	*/
	ADJUST_EKKO();

	/*
		功能:批量绘制
		注：
	*/
	BeginBatchDraw();
}

void SlowChancesShow()
{
	for (int m = 0; m < SlowLimit; m++)
	{
		putimage(150 * m, 10, &SlowChance_mask, NOTSRCERASE);
		putimage(150 * m, 10, &SlowChance, SRCINVERT);
	}
}

/*
	功能：（此处为预计）show2 为进入游戏画面后的正式画面展示
	注：地图绘制（由于FlashBatchDraw，无法在show2函数以外绘制地图）
*/
void show2()                
{
	MAP();                  
	Ekko_Show();
	SlowChancesShow();
	FlushBatchDraw();
	cleardevice();
}

/*
	功能：无需输入即可执行的角色动作和状态更新
*/
void updateWithoutInput()   
{
	Drop_Ekko();
	SlowTime();
}

/*
	功能：需输入才执行的角色动作和状态更新
*/
void updateWithInput()   
{
	MoveEKKO();
	ADJUST_EKKO();
}

//游戏主体框架
int main()
{
	startup();  //初始化
	Start();

	//-----------------------复活坐标设置
reborn:
	//英雄联盟,MitiS - The Boy Who Shattered Time (MitiS Remix)
	mciSendString(_T("open .\\图片资源\\1.mp3 alias bkmusic"), NULL, 0, NULL);//背景音乐
	mciSendString(_T("play bkmusic repeat"), NULL, 0, NULL);//循环播放
	Ekko_Speed_x = 0;
	Ekko_Speed_y = 0;
	Ekko_x = Land_Left[0] + 32;  	 //放在第一个平台靠左处
	Ekko_y = Land_Top[0] - 80;       //放在平台上空                          	
	/*--------------------Ekko的初始坐标---------------------------*/
	SlowLimit = 3;
	//-----------------------复活坐标设置//reborn
	while (true)                       //游戏主体
	{
		//		clean();//清除指定图像，暂时没有清除的目标
		show2();
		updateWithoutInput();
		updateWithInput();

		//------------------------死亡判断
		if (Ekko_y > 3000)
			DeadOrNot = 1;
		if (DeadOrNot == 1)
		{
			mciSendString("close Woman", NULL, 0, NULL);
			mciSendString("close bkmusic", NULL, 0, NULL);
			mciSendString("close RebornWord", NULL, 0, NULL);
			mciSendString("close StartWord", NULL, 0, NULL);
			mciSendString("close DeadWord", NULL, 0, NULL);
			mciSendString("open .\\图片资源\\去世.mp3 alias DeadWord", NULL, 0, NULL);
			mciSendString("play DeadWord", NULL, 0, NULL);
			break;
		}
		//-------------------------------
	}
	//---------------------------Game Over----------------------------------
	while (true)
	{
		MOUSEMSG mouse;

		BeginBatchDraw();
		putimage(0, 0, &end);
		mouse.mkLButton = false;
		mouse.x = 0;
		mouse.y = 0;
		if (MouseHit())
		{
			mouse = GetMouseMsg();
		}
		if (mouse.mkLButton)//单击出现小圈
		{
			circle(mouse.x, mouse.y, 5);
		}

		if (mouse.x < 1000 && mouse.x > 600 && mouse.y > 553 && mouse.y < 613)//当鼠标放在按钮上
		{
			rectangle(970, 553, 680, 633);
		}
		if (mouse.x < 1000 && mouse.x > 600 && mouse.y > 663 && mouse.y < 733)
		{
			mciSendString("open .\\图片资源\\10.mp3 alias Woman", NULL, 0, NULL);
			mciSendString("play Woman", NULL, 0, NULL);
			rectangle(970, 653, 680, 723);
		}

		if (mouse.mkLButton && mouse.x < 1000 && mouse.x > 600 && mouse.y > 553 && mouse.y < 613)//点击按钮
		{
			FlushMouseMsgBuffer();
			mciSendString("close DeadWord", NULL, 0, NULL);
			mciSendString("close RebornWord", NULL, 0, NULL);
			mciSendString("open .\\图片资源\\两级反转.mp3 alias RebornWord", NULL, 0, NULL);
			mciSendString("play RebornWord", NULL, 0, NULL);

			SlowOrNot = 0;      //刷新时停
			DeadOrNot = 0;      //初始化该变量
			goto reborn;        //重新开始
		}

		if (mouse.mkLButton && mouse.x < 1000 && mouse.x > 600 && mouse.y > 663 && mouse.y < 733)
		{
			FlushMouseMsgBuffer();
			closegraph();
			exit(0);
		}

		FlushBatchDraw();
	}
	//---------------------------Game Over----------------------------------
	return 0;
}