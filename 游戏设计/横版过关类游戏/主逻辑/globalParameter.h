//
//  文件功能：全局变量引用
//
//
//
#include<graphics.h>
/*
	功能:地形与游戏视角(摄像机)
*/
//---------------------------	
extern float Land_Left[];
extern float Land_Right[];  	//地图模块的中心坐标
extern float Land_Top[];
extern float Land_Bottom[];		//模块的高与宽
extern int 	 LockedOne_x;       //x方向的交互物块    进入返还1时的角标被这个变量保存
extern int   LockedOne_y;       //y方向的交互物块    进入返还1时的角标被这个变量保存
extern float Screen_Center_x;
extern float Screen_Center_y;   //图像的正中心的坐标，人物起始状态下在此不动
//----------------------------

//测试用图片 -- 资源测试



/*
	功能：游戏角色状态 -- 死亡，技能状态，移动速度，跳跃
	Commit：初始定义（全局变量）在  定义.cpp  文件中
*/
//-------------------------------
extern int Running_Time;     	 //获取系统当前时间
extern int Start_Time;       	 //时停开始的时间
extern int SlowOrNot;        	 //是否进入时停
extern int SlowLimit;        	 //时停限制
extern int DeadOrNot; 			 //判断是否死亡，是为1
extern int Dash_Check;     	 	 //检测是否处于冲刺状态。
extern int Dash_limit;       	 //限制无限冲刺
extern int Status_check_i;	  	 //角色是否跑动，跑动为1，未跑动为0,空中移动为2，在main的setup中赋予初值，在Ekko_Show.cpp中使用
extern int Ekko_Face;		  	 //角色的运动的朝向，1为X轴正半轴，-1为X轴负半轴
extern int DropOrNot;		 	 //角色下落状态为1，不下落为0
extern int JumpOrNot;		 	 //判断是否为  跳跃  的行为，1为是，0为否
extern float Ekko_Speed_x;	 	 //角色的速度x，+值为向X轴正反向，0为静止，- 值为X轴负方向
extern float Ekko_Speed_y;	  	 //角色的速度y，+为向y轴负方向，-为向y轴正方向
extern float Acceleration_x; 	 //角色水平方向加速度。右向为正数
extern int jump_limit_check;  	 //防止无限跳跃。1为限制状态，0为自由状态。
extern float Dash_Speed;         //冲刺速度
//extern int jump_falling_check; //从平台落下时激活为2（暂未实现）
//-------------------------------


//----------------------------------------------------------
extern float Ekko_x, Ekko_y;                               //游戏角色的中心坐标
extern float Ekko_High, Ekko_Width;                        //游戏角色在地图中的碰撞大小， 游戏角色的图片素材为64*64，由于EasyX对图片调用的特性，
extern float Ekko_Left, Ekko_Right, Ekko_Top, Ekko_Bottom; //图片的高度、宽度。 
//----------------------------------------------------------

/*
	功能：特定角色动画状态 -- 站立，跑动
*/
//--------------------------------
extern int Ekko_Stand_Count;      //是否站立状态，该值的改变会带来站立时图片的更替，范围为1-3
extern int Ekko_Run_Count;        //带来跑步图片更替
extern int Ekko_Run_Frequency;    //控制跑步动画变帧速率
//--------------------------------

/*
	功能：与玩家输入有关的状态
*/
//---------------------
extern int w_check;    //检测刚才是否按过w，是为1，否为0
extern int AD_in_Air;//检测空中是否使用过A/D按键
//---------------------


/*
	功能:声明图片资源
*/
extern IMAGE BULLET;    		//子弹
extern IMAGE BULLET_mask;		//
extern IMAGE start;   			//开始按钮
extern IMAGE end;				//结束按钮
extern IMAGE img_Background;	//游戏主界面背景图片

extern IMAGE Ekko_Stand_1_mask, Ekko_Stand_1;//角色站立图,其原始定义在 定义.cpp 中
extern IMAGE Ekko_Stand_2_mask, Ekko_Stand_2;//角色站立图,其原始定义在 定义.cpp 中
extern IMAGE Ekko_Stand_3_mask, Ekko_Stand_3;//角色站立图,其原始定义在 定义.cpp 中

extern IMAGE Ekko_Stand_1_OPPOSITE_mask, Ekko_Stand_1_OPPOSITE;//以上为角色站立图,其原始定义在 定义.cpp 中
extern IMAGE Ekko_Stand_2_OPPOSITE_mask, Ekko_Stand_2_OPPOSITE;//以上为角色站立图,其原始定义在 定义.cpp 中
extern IMAGE Ekko_Stand_3_OPPOSITE_mask, Ekko_Stand_3_OPPOSITE;//以上为角色站立图,其原始定义在 定义.cpp 中

extern IMAGE Ekko_Run_1_mask, Ekko_Run_1;//跑动
extern IMAGE Ekko_Run_2_mask, Ekko_Run_2;
extern IMAGE Ekko_Run_3_mask, Ekko_Run_3;
extern IMAGE Ekko_Run_4_mask, Ekko_Run_4;
extern IMAGE Ekko_Run_5_mask, Ekko_Run_5;
extern IMAGE Ekko_Run_6_mask, Ekko_Run_6;
extern IMAGE Ekko_Run_7_mask, Ekko_Run_7;
extern IMAGE Ekko_Run_8_mask, Ekko_Run_8;

extern IMAGE Ekko_Run_1_OPPOSITE_mask, Ekko_Run_1_OPPOSITE;//跑动
extern IMAGE Ekko_Run_2_OPPOSITE_mask, Ekko_Run_2_OPPOSITE;
extern IMAGE Ekko_Run_3_OPPOSITE_mask, Ekko_Run_3_OPPOSITE;
extern IMAGE Ekko_Run_4_OPPOSITE_mask, Ekko_Run_4_OPPOSITE;
extern IMAGE Ekko_Run_5_OPPOSITE_mask, Ekko_Run_5_OPPOSITE;
extern IMAGE Ekko_Run_6_OPPOSITE_mask, Ekko_Run_6_OPPOSITE;
extern IMAGE Ekko_Run_7_OPPOSITE_mask, Ekko_Run_7_OPPOSITE;
extern IMAGE Ekko_Run_8_OPPOSITE_mask, Ekko_Run_8_OPPOSITE;

extern IMAGE Ekko_Jump_1_mask, Ekko_Jump_1;//条约
extern IMAGE Ekko_Jump_2_mask, Ekko_Jump_2;
extern IMAGE Ekko_Jump_3_mask, Ekko_Jump_3;
extern IMAGE img_Ekko_Fall_mask, img_Ekko_Fall;//向右移动

extern IMAGE Ekko_Jump_1_OPPOSITE_mask, Ekko_Jump_1_OPPOSITE;
extern IMAGE Ekko_Jump_2_OPPOSITE_mask, Ekko_Jump_2_OPPOSITE;
extern IMAGE Ekko_Jump_3_OPPOSITE_mask, Ekko_Jump_3_OPPOSITE;
extern IMAGE img_Ekko_Fall_OPPOSITE_mask, img_Ekko_Fall_OPPOSITE;//向左移动

extern IMAGE Ekko_Dash_up, Ekko_Dash_up_mask;
extern IMAGE Ekko_Dash_up_OPPOSITE, Ekko_Dash_up_mask_OPPOSITE;//向上冲刺


//敌对单位，环境单位
extern IMAGE MAP_trap_1;//地刺
extern IMAGE MAP_trap_1_mask;
extern IMAGE MAP_trap_2;//地刺
extern IMAGE MAP_trap_2_mask;
extern IMAGE MAP_trap_3;//地刺
extern IMAGE MAP_trap_3_mask;

extern IMAGE MAP_floor_1;
extern IMAGE MAP_floor_1_mask;//地板
extern IMAGE MAP_floor_2;
extern IMAGE MAP_floor_2_mask;
extern IMAGE MAP_floor_3;
extern IMAGE MAP_floor_3_mask;
extern IMAGE MAP_floor_4;
extern IMAGE MAP_floor_4_mask;
extern IMAGE MAP_floor_5;
extern IMAGE MAP_floor_5_mask;
extern IMAGE MAP_floor_6;
extern IMAGE MAP_floor_6_mask;
extern IMAGE MAP_floor_7;
extern IMAGE MAP_floor_7_mask;
extern IMAGE MAP_floor_8;
extern IMAGE MAP_floor_8_mask;

extern IMAGE MAP_board_1;//浮板
extern IMAGE MAP_board_2;
extern IMAGE MAP_board_3;
extern IMAGE MAP_board_4;
extern IMAGE MAP_board_5;
extern IMAGE MAP_board_6;
extern IMAGE MAP_board_7;
extern IMAGE MAP_board_8;
extern IMAGE MAP_board_9;
extern IMAGE MAP_board_10;
extern IMAGE MAP_board_11;
extern IMAGE MAP_board_12;
extern IMAGE MAP_board_13;
extern IMAGE MAP_board_14;
extern IMAGE MAP_board_15;
extern IMAGE MAP_board_16;

extern IMAGE MAP_enemy;				//弹幕点
extern IMAGE MAP_enemy_mask;

//角色技能
extern IMAGE SlowChance;     		//时停剩余次数的图标
extern IMAGE SlowChance_mask;     	//时停剩余次数的图标