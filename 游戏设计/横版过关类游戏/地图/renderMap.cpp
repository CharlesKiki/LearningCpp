#include<globalParameter.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>

/*
	功能：值的单位是像素
	注：地图大小，这两个数据乱编的，需要调整
*/
#define MAP_High 	2000	//地图大小参数
#define MAP_Width   6000   
#define Scene_Width 1600	//将游戏画面参数，1600*800的窗口
#define Scene_High 800  

/*
	功能：
*/
void Map_Status_Setup()   //数组的数据初始化（赋值）
{
	Screen_Center_x = Scene_Width / 2;
	Screen_Center_y = Scene_High / 2;		//临时的将视角锁定在左下角的数据改动，要优化

	Land_Left[0] = 0;
	Land_Right[0] = 1000;
	Land_Top[0] = 750;
	Land_Bottom[0] = 1250;     //第一块地板长为1000，高为500（一）

/*	Land_Left[1] = 256;
	Land_Right[1] = 384;
	Land_Top[1] = 622;
	Land_Bottom[1] = 750;   //第一块地板上的第一个敌人，128*128（一）暂定取消*/

	Land_Left[2] = 256;
	Land_Right[2] = 400;
	Land_Top[2] = 364;
	Land_Bottom[2] = 384;	//可以运用E跳上的空中的第一个板子，离敌人128，长度为144，高20（一）

	Land_Left[3] = 480;
	Land_Right[3] = 580;
	Land_Top[3] = 264;
	Land_Bottom[3] = 284;	//空中的第二块浮板，离第一块板子80，长度100，高20（一）

	Land_Left[4] = 680;
	Land_Right[4] = 760;
	Land_Top[4] = 144;
	Land_Bottom[4] = 164;		//空中的第三块浮板，离第二块板子100，长度80,高20（一）

	Land_Left[5] = 880;
	Land_Right[5] = 1500;
	Land_Top[5] = 4;
	Land_Bottom[5] = 24;		//空中的第四块浮板，离第三块板子120，长度620,高20（一）

	Land_Left[6] = 950;
	Land_Right[6] = 1094;
	Land_Top[6] = -44;
	Land_Bottom[6] = 4;		//第四块板子上的地刺（一）1

	Land_Left[7] = 624;
	Land_Right[7] = 672;
	Land_Top[7] = 702;
	Land_Bottom[7] = 750;		//第一个地刺（一）

	Land_Left[8] = 682;
	Land_Right[8] = 730;
	Land_Top[8] = 702;
	Land_Bottom[8] = 750;		//第二个地刺（一）

	Land_Left[9] = 1200;
	Land_Right[9] = 1500;
	Land_Top[9] = 750;
	Land_Bottom[9] = 800;		//第二块地板，长300，高50（一）

	Land_Left[10] = 2000;
	Land_Right[10] = 2600;
	Land_Top[10] = 750;
	Land_Bottom[10] = 800;		//第三块地板，长600，高50（一）

	Land_Left[11] = 2252;
	Land_Right[11] = 2300;
	Land_Top[11] = 702;
	Land_Bottom[11] = 750;		//第三个地刺（一）

	Land_Left[12] = 2300;
	Land_Right[12] = 2348;
	Land_Top[12] = 702;
	Land_Bottom[12] = 750;		//第四个地刺（一）

	Land_Left[13] = 3000;
	Land_Right[13] = 4200;
	Land_Top[13] = 750;
	Land_Bottom[13] = 800;		//第一条路：地板一（二)长1200，高50

	Land_Left[14] = 3400;
	Land_Right[14] = 4200;
	Land_Top[14] = 350;
	Land_Bottom[14] = 400;		//第二条路：空中板一（二）长800，高50

	Land_Left[15] = 3800;
	Land_Right[15] = 4200;
	Land_Top[15] = 0;
	Land_Bottom[15] = 50;		//第三条路：空中板二（二）长400，高50

	Land_Left[16] = 3200;
	Land_Right[16] = 3400;
	Land_Top[16] = 550;
	Land_Bottom[16] = 600;		//过渡板一，一二之间（二）长200，高50

	Land_Left[17] = 3600;
	Land_Right[17] = 3800;
	Land_Top[17] = 150;
	Land_Bottom[17] = 200;		//过渡板二，二三之间（二）长200，高50

	Land_Left[18] = 4300;
	Land_Right[18] = 4500;
	Land_Top[18] = 750;
	Land_Bottom[18] = 800;		//路一第二块地板（二）长200，高50

	Land_Left[19] = 4300;
	Land_Right[19] = 4500;
	Land_Top[19] = 350;
	Land_Bottom[19] = 400;		//路二第二块浮板（二）长200，高50

	Land_Left[20] = 4300;
	Land_Right[20] = 4500;
	Land_Top[20] = 0;
	Land_Bottom[20] = 50;		//路三第二块浮板（二）长200，高50

	Land_Left[21] = 4800;
	Land_Right[21] = 5150;
	Land_Top[21] = 750;
	Land_Bottom[21] = 800;		//路一第三块地板（二）1 长350，高50

	Land_Left[22] = 5200;
	Land_Right[22] = 5550;
	Land_Top[22] = 750;
	Land_Bottom[22] = 800;		//路一第三块地板（二）2 长350，高50

	Land_Left[23] = 4800;
	Land_Right[23] = 5550;
	Land_Top[23] = 350;
	Land_Bottom[23] = 400;		//路二第三块浮板（二） 长750，高50

	Land_Left[24] = 4800;
	Land_Right[24] = 5550;
	Land_Top[24] = 0;
	Land_Bottom[24] = 50;		//路三第三块浮板（二） 长750，高50

	Land_Left[25] = 5850;
	Land_Right[25] = 6600;
	Land_Top[25] = 750;
	Land_Bottom[25] = 800;		//路一第四块地板（二）长750，高50

	Land_Left[26] = 5850;
	Land_Right[26] = 6200;
	Land_Top[26] = 350;
	Land_Bottom[26] = 400;		//路二第四块浮板（二）1 长350，高50

	Land_Left[27] = 6250;
	Land_Right[27] = 6600;
	Land_Top[27] = 350;
	Land_Bottom[27] = 400;		//路二第四块地板（二）2 长350，高50

	Land_Left[28] = 5850;
	Land_Right[28] = 6600;
	Land_Top[28] = 0;
	Land_Bottom[28] = 50;		//路三第四块浮板（二） 长750，高50

	Land_Left[29] = 6900;
	Land_Right[29] = 7650;
	Land_Top[29] = 750;
	Land_Bottom[29] = 800;		//路一第五块地板（二） 长750，高50

	Land_Left[30] = 6900;
	Land_Right[30] = 7650;
	Land_Top[30] = 350;
	Land_Bottom[30] = 400;		//路二第五块浮板（二）长750，高50

	Land_Left[31] = 6900;
	Land_Right[31] = 7250;
	Land_Top[31] = 0;
	Land_Bottom[31] = 50;		//路三第五块浮板（二）1 长350，高50

	Land_Left[32] = 7300;
	Land_Right[32] = 7650;
	Land_Top[32] = 0;
	Land_Bottom[32] = 50;		//路三第五块浮板（二）2 长350，高50

	Land_Left[33] = 7650;
	Land_Right[33] = 7680;
	Land_Top[33] = 635;
	Land_Bottom[33] = 800;		//路一第一个挡板，长30，高165（三）

	Land_Left[34] = 7650;
	Land_Right[34] = 9250;
	Land_Top[34] = 240;
	Land_Bottom[34] = 535;		//路一与路二之间的隔板，高295，长1600（三）11

	Land_Left[35] = 7650;
	Land_Right[35] = 7680;
	Land_Top[35] = 0;
	Land_Bottom[35] = 140;		//路三的挡板，长30，高140（三）12

	Land_Left[36] = 7650;
	Land_Right[36] = 9250;
	Land_Top[36] = 615;
	Land_Bottom[36] = 635;		//通道一的下板，长1600，高20（三）13

	Land_Left[37] = 7650;
	Land_Right[37] = 9250;
	Land_Top[37] = 140;
	Land_Bottom[37] = 160;		//通道二的上板，长1600，高20（三）13

	Land_Left[38] = 9550;
	Land_Right[38] = 9750;
	Land_Top[38] = 900;
	Land_Bottom[38] = 940;		//出通道一后能踩的唯一浮块，长200，高40（三）名字：张14

	Land_Left[39] = 9220;
	Land_Right[39] = 9320;
	Land_Top[39] = 685;
	Land_Bottom[39] = 705;		//踩过张后唯一能踩的浮块，长100，高20（三）名字：明2

	Land_Left[40] = 9550;
	Land_Right[40] = 9750;
	Land_Top[40] = 620;
	Land_Bottom[40] = 640;		//踩过明后唯一能踩的浮块，长200，高20（三）名字：懿15

	Land_Left[41] = 9250;
	Land_Right[41] = 9350;
	Land_Top[41] = 420;
	Land_Bottom[41] = 440;		//踩过懿后唯一能踩的浮块，长100，高20（三）名字：江2

	Land_Left[42] = 9550;
	Land_Right[42] = 9750;
	Land_Top[42] = 200;
	Land_Bottom[42] = 220;		//踩过江后唯一能踩的浮块，长200，高20（三）名字：健15

	Land_Left[43] = 9750;
	Land_Right[43] = 10250;
	Land_Top[43] = 0;
	Land_Bottom[43] = 950;		//大平台，长500，高950（四）

	Land_Left[44] = 7680;
	Land_Right[44] = 8160;
	Land_Top[44] = 92;
	Land_Bottom[44] = 140;		//地刺五（三），48*48*10

	Land_Left[45] = 8160;
	Land_Right[45] = 8640;
	Land_Top[45] = 92;
	Land_Bottom[45] = 140;		//地刺六（三），48*48*10

	Land_Left[46] = 8640;
	Land_Right[46] = 9120;
	Land_Top[46] = 92;
	Land_Bottom[46] = 140;		//地刺七（三），48*48*10

	Land_Left[47] = 10550;
	Land_Right[47] = 10650;
	Land_Top[47] = 50;
	Land_Bottom[47] = 70;		//一号浮板（四），长100，高20

	Land_Left[48] = 11050;
	Land_Right[48] = 11150;
	Land_Top[48] = -20;
	Land_Bottom[48] = 0;		//二号浮板（四），长100，高20

	Land_Left[49] = 11550;
	Land_Right[49] = 11650;
	Land_Top[49] = 100;
	Land_Bottom[49] = 120;		//三号浮板（四），长100，高20

	Land_Left[50] = 12050;
	Land_Right[50] = 12150;
	Land_Top[50] = 250;
	Land_Bottom[50] = 270;		//四号（四） 同上

	Land_Left[51] = 12550;
	Land_Right[51] = 12650;
	Land_Top[51] = 430;
	Land_Bottom[51] = 450;		//五号（四） 同上

	Land_Left[52] = 13050;
	Land_Right[52] = 13150;
	Land_Top[52] = 630;
	Land_Bottom[52] = 650;		//六号（四） 同上

	Land_Left[53] = 13550;
	Land_Right[53] = 13650;
	Land_Top[53] = 780;
	Land_Bottom[53] = 800;		//七号（四） 同上

	Land_Left[54] = 14050;
	Land_Right[54] = 14150;
	Land_Top[54] = 640;
	Land_Bottom[54] = 660;		//八号（四） 同上

	Land_Left[55] = 14550;
	Land_Right[55] = 14650;
	Land_Top[55] = 450;
	Land_Bottom[55] = 470;		//九号（四）同上

	Land_Left[56] = 15050;
	Land_Right[56] = 15150;
	Land_Top[56] = 320;
	Land_Bottom[56] = 340;		//十号（四）同上

	Land_Left[57] = 15550;
	Land_Right[57] = 15650;
	Land_Top[57] = 200;
	Land_Bottom[57] = 220;		//十一号（四） 同上

	Land_Left[58] = 16050;
	Land_Right[58] = 16150;
	Land_Top[58] = 360;
	Land_Bottom[58] = 380;		//十二号（四） 同上

	Land_Left[59] = 16550;
	Land_Right[59] = 16650;
	Land_Top[59] = 500;
	Land_Bottom[59] = 520;		//十五号（四） 同上

	Land_Left[60] = 17050;
	Land_Right[60] = 17150;
	Land_Top[60] = 590;
	Land_Bottom[60] = 610;		//十六号（四） 同上

	Land_Left[61] = 17550;
	Land_Right[61] = 17650;
	Land_Top[61] = 780;
	Land_Bottom[61] = 800;		//十七号（四） 同上

	Land_Left[62] = 17750;
	Land_Right[62] = 18150;
	Land_Top[62] = 850;
	Land_Bottom[62] = 900;		//终于终点啦，左边（五），长400，高50

	Land_Left[63] = 18950;
	Land_Right[63] = 19750;
	Land_Top[63] = 850;
	Land_Bottom[63] = 900;		//终于终点啦，右边（五），长800，高50
	
	Land_Left[64] = 1305;
	Land_Right[64] = 1450;
	Land_Top[64] = -44;
	Land_Bottom[64] = 4;		//第四块板子上的地刺（一）1

	Land_Left[65] = 3856;
	Land_Right[65] = 4000;
	Land_Top[65] = 702;
	Land_Bottom[65] = 750;		//第四块板子上的地刺（一）2

	Land_Left[66] = 3956;
	Land_Right[66] = 4100;
	Land_Top[66] = 302;
	Land_Bottom[66] = 350;		//第四块板子上的地刺（一）1

	/*----------------------------------------完结撒花！！！----------------------------------------------------------*/

	Block_Number = 67;      //每写一个数组，请手动+1。  该变量大小小于数组最大下角标

	enemy_x[0] = 5175;		//第一个弹幕点，半径25；
	enemy_y[0] = 775;
	enemy_x[1] = 6225;		//第二个弹幕点，半径25；
	enemy_y[1] = 375;
	enemy_x[2] = 7275;		//第三个弹幕点，半径25；
	enemy_y[2] = 25;
	enemy_x[3] = 7850;		//第四个弹幕点，半径25；
	enemy_y[3] = -75;
	enemy_x[4] = 8400;		//第五个弹幕点，半径25；
	enemy_y[4] = -75;
	enemy_x[5] = 8950;		//第六个弹幕点，半径25；
	enemy_y[5] = -75;
	enemy_x[6] = 7850;		//第七个弹幕点，半径25；
	enemy_y[6] = 875;
	enemy_x[7] = 8400;		//第八个弹幕点，半径25；
	enemy_y[7] = 875;
	enemy_x[8] = 8950;		//第九个弹幕点，半径25；
	enemy_y[8] = 875;
	enemy_x[9] = 11100;		//第十个弹幕点，半径25；
	enemy_y[9] = -400;
	enemy_x[10] = 12600;	//第十一个弹幕点，半径25；
	enemy_y[10] = 0;
	enemy_x[11] = 14100;	//第十二个弹幕点，半径25；
	enemy_y[11] = 0;
	enemy_x[12] = 15600;	//第十三个弹幕点，半径25；
	enemy_y[12] = 0;
	enemy_x[13] = 18250;		//第十四个弹幕点，半径25；
	enemy_y[13] = 500;
	enemy_x[14] = 18400;		//第十五个弹幕点，半径25；
	enemy_y[14] = 300;
	enemy_x[15] = 18550;		//第十六个弹幕点，半径25；
	enemy_y[15] = 500;
	enemy_x[16] = 18700;		//第十七个弹幕点，半径25；
	enemy_y[16] = 300;
	enemy_x[17] = 18850;		//第十八个弹幕点，半径25；
	enemy_y[17] = 500;
	enemy_x[18] = 820;		//第十九个弹幕点，半径25；
	enemy_y[18] = 350;
	enemy_x[19] = 1750;		//第二十个弹幕点，半径25；
	enemy_y[19] = 1000;
	enemy_x[20] = 3800;		//第二十一个弹幕点，半径25；
	enemy_y[20] = -200;
	enemy_x[21] = 3600;		//第二十二个弹幕点，半径25；
	enemy_y[21] = 950;

	for (i = 0; i < 22; i++)
	{
		start_x[i][0] = bullet_x[i][0] = enemy_x[i] + 22;
		start_y[i][0] = bullet_y[i][0] = enemy_y[i] - 18;
		start_x[i][1] = bullet_x[i][1] = enemy_x[i];
		start_y[i][1] = bullet_y[i][1] = enemy_y[i] - 25;
		start_x[i][2] = bullet_x[i][2] = enemy_x[i] - 22;
		start_y[i][2] = bullet_y[i][2] = enemy_y[i] - 15;
		start_x[i][3] = bullet_x[i][3] = enemy_x[i] - 18;
		start_y[i][3] = bullet_y[i][3] = enemy_y[i] + 18;
		start_x[i][4] = bullet_x[i][4] = enemy_x[i] + 2;
		start_y[i][4] = bullet_y[i][4] = enemy_y[i] + 25;
		start_x[i][5] = bullet_x[i][5] = enemy_x[i] + 20;
		start_y[i][5] = bullet_y[i][5] = enemy_y[i] + 17;
	}

}

/*
	功能：
*/
void MAP()            //数组上图,因为目前考虑图只改变一次，便将其放在主文件的setup函数中
{

	setcolor(RED);
	setfillcolor(BLACK);
	//先绘制背景图
	putimage(-300 + (Screen_Center_x - Ekko_x) / 15, -400 + (Screen_Center_y - Ekko_y) / 15, &img_Background);

	putimage(enemy_x[0] + (Screen_Center_x - Ekko_x) - 25, enemy_y[0] + (Screen_Center_y - Ekko_y) - 25, &MAP_enemy_mask, NOTSRCERASE);
	putimage(enemy_x[0] + (Screen_Center_x - Ekko_x) - 25, enemy_y[0] + (Screen_Center_y - Ekko_y) - 25, &MAP_enemy, SRCINVERT);
	putimage(enemy_x[1] + (Screen_Center_x - Ekko_x) - 25, enemy_y[1] + (Screen_Center_y - Ekko_y) - 25, &MAP_enemy_mask, NOTSRCERASE);
	putimage(enemy_x[1] + (Screen_Center_x - Ekko_x) - 25, enemy_y[1] + (Screen_Center_y - Ekko_y) - 25, &MAP_enemy, SRCINVERT);
	putimage(enemy_x[2] + (Screen_Center_x - Ekko_x) - 25, enemy_y[2] + (Screen_Center_y - Ekko_y) - 25, &MAP_enemy_mask, NOTSRCERASE);
	putimage(enemy_x[2] + (Screen_Center_x - Ekko_x) - 25, enemy_y[2] + (Screen_Center_y - Ekko_y) - 25, &MAP_enemy, SRCINVERT);
	putimage(enemy_x[3] + (Screen_Center_x - Ekko_x) - 25, enemy_y[3] + (Screen_Center_y - Ekko_y) - 25, &MAP_enemy_mask, NOTSRCERASE);
	putimage(enemy_x[3] + (Screen_Center_x - Ekko_x) - 25, enemy_y[3] + (Screen_Center_y - Ekko_y) - 25, &MAP_enemy, SRCINVERT);
	putimage(enemy_x[4] + (Screen_Center_x - Ekko_x) - 25, enemy_y[4] + (Screen_Center_y - Ekko_y) - 25, &MAP_enemy_mask, NOTSRCERASE);
	putimage(enemy_x[4] + (Screen_Center_x - Ekko_x) - 25, enemy_y[4] + (Screen_Center_y - Ekko_y) - 25, &MAP_enemy, SRCINVERT);
	putimage(enemy_x[5] + (Screen_Center_x - Ekko_x) - 25, enemy_y[5] + (Screen_Center_y - Ekko_y) - 25, &MAP_enemy_mask, NOTSRCERASE);
	putimage(enemy_x[5] + (Screen_Center_x - Ekko_x) - 25, enemy_y[5] + (Screen_Center_y - Ekko_y) - 25, &MAP_enemy, SRCINVERT);
	putimage(enemy_x[6] + (Screen_Center_x - Ekko_x) - 25, enemy_y[6] + (Screen_Center_y - Ekko_y) - 25, &MAP_enemy_mask, NOTSRCERASE);
	putimage(enemy_x[6] + (Screen_Center_x - Ekko_x) - 25, enemy_y[6] + (Screen_Center_y - Ekko_y) - 25, &MAP_enemy, SRCINVERT);
	putimage(enemy_x[7] + (Screen_Center_x - Ekko_x) - 25, enemy_y[7] + (Screen_Center_y - Ekko_y) - 25, &MAP_enemy_mask, NOTSRCERASE);
	putimage(enemy_x[7] + (Screen_Center_x - Ekko_x) - 25, enemy_y[7] + (Screen_Center_y - Ekko_y) - 25, &MAP_enemy, SRCINVERT);
	putimage(enemy_x[8] + (Screen_Center_x - Ekko_x) - 25, enemy_y[8] + (Screen_Center_y - Ekko_y) - 25, &MAP_enemy_mask, NOTSRCERASE);
	putimage(enemy_x[8] + (Screen_Center_x - Ekko_x) - 25, enemy_y[8] + (Screen_Center_y - Ekko_y) - 25, &MAP_enemy, SRCINVERT);
	putimage(enemy_x[9] + (Screen_Center_x - Ekko_x) - 25, enemy_y[9] + (Screen_Center_y - Ekko_y) - 25, &MAP_enemy_mask, NOTSRCERASE);
	putimage(enemy_x[9] + (Screen_Center_x - Ekko_x) - 25, enemy_y[9] + (Screen_Center_y - Ekko_y) - 25, &MAP_enemy, SRCINVERT);
	putimage(enemy_x[10] + (Screen_Center_x - Ekko_x) - 25, enemy_y[10] + (Screen_Center_y - Ekko_y) - 25, &MAP_enemy_mask, NOTSRCERASE);
	putimage(enemy_x[10] + (Screen_Center_x - Ekko_x) - 25, enemy_y[10] + (Screen_Center_y - Ekko_y) - 25, &MAP_enemy, SRCINVERT);
	putimage(enemy_x[11] + (Screen_Center_x - Ekko_x) - 25, enemy_y[11] + (Screen_Center_y - Ekko_y) - 25, &MAP_enemy_mask, NOTSRCERASE);
	putimage(enemy_x[11] + (Screen_Center_x - Ekko_x) - 25, enemy_y[11] + (Screen_Center_y - Ekko_y) - 25, &MAP_enemy, SRCINVERT);
	putimage(enemy_x[12] + (Screen_Center_x - Ekko_x) - 25, enemy_y[12] + (Screen_Center_y - Ekko_y) - 25, &MAP_enemy_mask, NOTSRCERASE);
	putimage(enemy_x[12] + (Screen_Center_x - Ekko_x) - 25, enemy_y[12] + (Screen_Center_y - Ekko_y) - 25, &MAP_enemy, SRCINVERT);
	putimage(enemy_x[13] + (Screen_Center_x - Ekko_x) - 25, enemy_y[13] + (Screen_Center_y - Ekko_y) - 25, &MAP_enemy_mask, NOTSRCERASE);
	putimage(enemy_x[13] + (Screen_Center_x - Ekko_x) - 25, enemy_y[13] + (Screen_Center_y - Ekko_y) - 25, &MAP_enemy, SRCINVERT);
	putimage(enemy_x[14] + (Screen_Center_x - Ekko_x) - 25, enemy_y[14] + (Screen_Center_y - Ekko_y) - 25, &MAP_enemy_mask, NOTSRCERASE);
	putimage(enemy_x[14] + (Screen_Center_x - Ekko_x) - 25, enemy_y[14] + (Screen_Center_y - Ekko_y) - 25, &MAP_enemy, SRCINVERT);
	putimage(enemy_x[15] + (Screen_Center_x - Ekko_x) - 25, enemy_y[15] + (Screen_Center_y - Ekko_y) - 25, &MAP_enemy_mask, NOTSRCERASE);
	putimage(enemy_x[15] + (Screen_Center_x - Ekko_x) - 25, enemy_y[15] + (Screen_Center_y - Ekko_y) - 25, &MAP_enemy, SRCINVERT);
	putimage(enemy_x[16] + (Screen_Center_x - Ekko_x) - 25, enemy_y[16] + (Screen_Center_y - Ekko_y) - 25, &MAP_enemy_mask, NOTSRCERASE);
	putimage(enemy_x[16] + (Screen_Center_x - Ekko_x) - 25, enemy_y[16] + (Screen_Center_y - Ekko_y) - 25, &MAP_enemy, SRCINVERT);
	putimage(enemy_x[17] + (Screen_Center_x - Ekko_x) - 25, enemy_y[17] + (Screen_Center_y - Ekko_y) - 25, &MAP_enemy_mask, NOTSRCERASE);
	putimage(enemy_x[17] + (Screen_Center_x - Ekko_x) - 25, enemy_y[17] + (Screen_Center_y - Ekko_y) - 25, &MAP_enemy, SRCINVERT);
	putimage(enemy_x[18] + (Screen_Center_x - Ekko_x) - 25, enemy_y[18] + (Screen_Center_y - Ekko_y) - 25, &MAP_enemy_mask, NOTSRCERASE);
	putimage(enemy_x[18] + (Screen_Center_x - Ekko_x) - 25, enemy_y[18] + (Screen_Center_y - Ekko_y) - 25, &MAP_enemy, SRCINVERT);
	putimage(enemy_x[19] + (Screen_Center_x - Ekko_x) - 25, enemy_y[19] + (Screen_Center_y - Ekko_y) - 25, &MAP_enemy_mask, NOTSRCERASE);
	putimage(enemy_x[19] + (Screen_Center_x - Ekko_x) - 25, enemy_y[19] + (Screen_Center_y - Ekko_y) - 25, &MAP_enemy, SRCINVERT);
	putimage(enemy_x[20] + (Screen_Center_x - Ekko_x) - 25, enemy_y[20] + (Screen_Center_y - Ekko_y) - 25, &MAP_enemy_mask, NOTSRCERASE);
	putimage(enemy_x[20] + (Screen_Center_x - Ekko_x) - 25, enemy_y[20] + (Screen_Center_y - Ekko_y) - 25, &MAP_enemy, SRCINVERT);
	putimage(enemy_x[21] + (Screen_Center_x - Ekko_x) - 25, enemy_y[21] + (Screen_Center_y - Ekko_y) - 25, &MAP_enemy_mask, NOTSRCERASE);
	putimage(enemy_x[21] + (Screen_Center_x - Ekko_x) - 25, enemy_y[21] + (Screen_Center_y - Ekko_y) - 25, &MAP_enemy, SRCINVERT);

	putimage(Land_Left[0] + (Screen_Center_x - Ekko_x), Land_Top[0] + (Screen_Center_y - Ekko_y), &MAP_floor_1_mask, NOTSRCERASE);
	putimage(Land_Left[0] + (Screen_Center_x - Ekko_x), Land_Top[0] + (Screen_Center_y - Ekko_y), &MAP_floor_1, SRCINVERT);
	//fillrectangle(Land_Left[1] + (Screen_Center_x - Ekko_x), Land_Top[1] + (Screen_Center_y - Ekko_y), Land_Right[1] + (Screen_Center_x - Ekko_x), Land_Bottom[1] + (Screen_Center_y - Ekko_y));
	putimage(Land_Left[2] + (Screen_Center_x - Ekko_x), Land_Top[2] + (Screen_Center_y - Ekko_y), &MAP_board_1);
	putimage(Land_Left[3] + (Screen_Center_x - Ekko_x), Land_Top[3] + (Screen_Center_y - Ekko_y), &MAP_board_2);
	putimage(Land_Left[4] + (Screen_Center_x - Ekko_x), Land_Top[4] + (Screen_Center_y - Ekko_y), &MAP_board_3);
	putimage(Land_Left[5] + (Screen_Center_x - Ekko_x), Land_Top[5] + (Screen_Center_y - Ekko_y), &MAP_board_4);
	putimage(Land_Left[6] + (Screen_Center_x - Ekko_x), Land_Top[6] + (Screen_Center_y - Ekko_y), &MAP_trap_3_mask, NOTSRCERASE);
	putimage(Land_Left[6] + (Screen_Center_x - Ekko_x), Land_Top[6] + (Screen_Center_y - Ekko_y), &MAP_trap_3, SRCINVERT);
	putimage(Land_Left[7] + (Screen_Center_x - Ekko_x), Land_Top[7] + (Screen_Center_y - Ekko_y), &MAP_trap_1_mask, NOTSRCERASE);
	putimage(Land_Left[7] + (Screen_Center_x - Ekko_x), Land_Top[7] + (Screen_Center_y - Ekko_y), &MAP_trap_1, SRCINVERT);
	putimage(Land_Left[8] + (Screen_Center_x - Ekko_x), Land_Top[8] + (Screen_Center_y - Ekko_y), &MAP_trap_1_mask, NOTSRCERASE);
	putimage(Land_Left[8] + (Screen_Center_x - Ekko_x), Land_Top[8] + (Screen_Center_y - Ekko_y), &MAP_trap_1, SRCINVERT);
	putimage(Land_Left[9] + (Screen_Center_x - Ekko_x), Land_Top[9] + (Screen_Center_y - Ekko_y), &MAP_floor_2_mask, NOTSRCERASE);
	putimage(Land_Left[9] + (Screen_Center_x - Ekko_x), Land_Top[9] + (Screen_Center_y - Ekko_y), &MAP_floor_2, SRCINVERT);
	putimage(Land_Left[10] + (Screen_Center_x - Ekko_x), Land_Top[10] + (Screen_Center_y - Ekko_y), &MAP_floor_3_mask, NOTSRCERASE);
	putimage(Land_Left[10] + (Screen_Center_x - Ekko_x), Land_Top[10] + (Screen_Center_y - Ekko_y), &MAP_floor_3, SRCINVERT);
	putimage(Land_Left[11] + (Screen_Center_x - Ekko_x), Land_Top[11] + (Screen_Center_y - Ekko_y), &MAP_trap_1_mask, NOTSRCERASE);
	putimage(Land_Left[11] + (Screen_Center_x - Ekko_x), Land_Top[11] + (Screen_Center_y - Ekko_y), &MAP_trap_1, SRCINVERT);
	putimage(Land_Left[12] + (Screen_Center_x - Ekko_x), Land_Top[12] + (Screen_Center_y - Ekko_y), &MAP_trap_1_mask, NOTSRCERASE);
	putimage(Land_Left[12] + (Screen_Center_x - Ekko_x), Land_Top[12] + (Screen_Center_y - Ekko_y), &MAP_trap_1, SRCINVERT);
	putimage(Land_Left[13] + (Screen_Center_x - Ekko_x), Land_Top[13] + (Screen_Center_y - Ekko_y), &MAP_floor_4_mask, NOTSRCERASE);
	putimage(Land_Left[13] + (Screen_Center_x - Ekko_x), Land_Top[13] + (Screen_Center_y - Ekko_y), &MAP_floor_4, SRCINVERT);
	putimage(Land_Left[14] + (Screen_Center_x - Ekko_x), Land_Top[14] + (Screen_Center_y - Ekko_y), &MAP_board_7);
	putimage(Land_Left[15] + (Screen_Center_x - Ekko_x), Land_Top[15] + (Screen_Center_y - Ekko_y), &MAP_board_8);
	putimage(Land_Left[16] + (Screen_Center_x - Ekko_x), Land_Top[16] + (Screen_Center_y - Ekko_y), &MAP_board_5);
	putimage(Land_Left[17] + (Screen_Center_x - Ekko_x), Land_Top[17] + (Screen_Center_y - Ekko_y), &MAP_board_5);
	putimage(Land_Left[18] + (Screen_Center_x - Ekko_x), Land_Top[18] + (Screen_Center_y - Ekko_y), &MAP_floor_5_mask, NOTSRCERASE);
	putimage(Land_Left[18] + (Screen_Center_x - Ekko_x), Land_Top[18] + (Screen_Center_y - Ekko_y), &MAP_floor_5, SRCINVERT);
	putimage(Land_Left[19] + (Screen_Center_x - Ekko_x), Land_Top[19] + (Screen_Center_y - Ekko_y), &MAP_board_5);
	putimage(Land_Left[20] + (Screen_Center_x - Ekko_x), Land_Top[20] + (Screen_Center_y - Ekko_y), &MAP_board_5);
	putimage(Land_Left[21] + (Screen_Center_x - Ekko_x), Land_Top[21] + (Screen_Center_y - Ekko_y), &MAP_floor_6_mask, NOTSRCERASE);
	putimage(Land_Left[21] + (Screen_Center_x - Ekko_x), Land_Top[21] + (Screen_Center_y - Ekko_y), &MAP_floor_6, SRCINVERT);
	putimage(Land_Left[22] + (Screen_Center_x - Ekko_x), Land_Top[22] + (Screen_Center_y - Ekko_y), &MAP_floor_6_mask, NOTSRCERASE);
	putimage(Land_Left[22] + (Screen_Center_x - Ekko_x), Land_Top[22] + (Screen_Center_y - Ekko_y), &MAP_floor_6, SRCINVERT);
	putimage(Land_Left[23] + (Screen_Center_x - Ekko_x), Land_Top[23] + (Screen_Center_y - Ekko_y), &MAP_board_9);
	putimage(Land_Left[24] + (Screen_Center_x - Ekko_x), Land_Top[24] + (Screen_Center_y - Ekko_y), &MAP_board_9);
	putimage(Land_Left[25] + (Screen_Center_x - Ekko_x), Land_Top[25] + (Screen_Center_y - Ekko_y), &MAP_floor_7_mask, NOTSRCERASE);
	putimage(Land_Left[25] + (Screen_Center_x - Ekko_x), Land_Top[25] + (Screen_Center_y - Ekko_y), &MAP_floor_7, SRCINVERT);
	putimage(Land_Left[26] + (Screen_Center_x - Ekko_x), Land_Top[26] + (Screen_Center_y - Ekko_y), &MAP_board_6);
	putimage(Land_Left[27] + (Screen_Center_x - Ekko_x), Land_Top[27] + (Screen_Center_y - Ekko_y), &MAP_board_6);
	putimage(Land_Left[28] + (Screen_Center_x - Ekko_x), Land_Top[28] + (Screen_Center_y - Ekko_y), &MAP_board_9);
	putimage(Land_Left[29] + (Screen_Center_x - Ekko_x), Land_Top[29] + (Screen_Center_y - Ekko_y), &MAP_floor_7_mask, NOTSRCERASE);
	putimage(Land_Left[29] + (Screen_Center_x - Ekko_x), Land_Top[29] + (Screen_Center_y - Ekko_y), &MAP_floor_7, SRCINVERT);
	putimage(Land_Left[30] + (Screen_Center_x - Ekko_x), Land_Top[30] + (Screen_Center_y - Ekko_y), &MAP_board_9);
	putimage(Land_Left[31] + (Screen_Center_x - Ekko_x), Land_Top[31] + (Screen_Center_y - Ekko_y), &MAP_board_6);
	putimage(Land_Left[32] + (Screen_Center_x - Ekko_x), Land_Top[32] + (Screen_Center_y - Ekko_y), &MAP_board_6);
	putimage(Land_Left[33] + (Screen_Center_x - Ekko_x), Land_Top[33] + (Screen_Center_y - Ekko_y), &MAP_board_10);
	putimage(Land_Left[34] + (Screen_Center_x - Ekko_x), Land_Top[34] + (Screen_Center_y - Ekko_y), &MAP_board_11);
	putimage(Land_Left[35] + (Screen_Center_x - Ekko_x), Land_Top[35] + (Screen_Center_y - Ekko_y), &MAP_board_12);
	putimage(Land_Left[36] + (Screen_Center_x - Ekko_x), Land_Top[36] + (Screen_Center_y - Ekko_y), &MAP_board_13);
	putimage(Land_Left[37] + (Screen_Center_x - Ekko_x), Land_Top[37] + (Screen_Center_y - Ekko_y), &MAP_board_13);
	putimage(Land_Left[38] + (Screen_Center_x - Ekko_x), Land_Top[38] + (Screen_Center_y - Ekko_y), &MAP_board_14);
	putimage(Land_Left[39] + (Screen_Center_x - Ekko_x), Land_Top[39] + (Screen_Center_y - Ekko_y), &MAP_board_2);
	putimage(Land_Left[40] + (Screen_Center_x - Ekko_x), Land_Top[40] + (Screen_Center_y - Ekko_y), &MAP_board_15);
	putimage(Land_Left[41] + (Screen_Center_x - Ekko_x), Land_Top[41] + (Screen_Center_y - Ekko_y), &MAP_board_2);
	putimage(Land_Left[42] + (Screen_Center_x - Ekko_x), Land_Top[42] + (Screen_Center_y - Ekko_y), &MAP_board_15);
	putimage(Land_Left[43] + (Screen_Center_x - Ekko_x), Land_Top[43] + (Screen_Center_y - Ekko_y), &MAP_board_16);
	putimage(Land_Left[44] + (Screen_Center_x - Ekko_x), Land_Top[44] + (Screen_Center_y - Ekko_y), &MAP_trap_2_mask, NOTSRCERASE);
	putimage(Land_Left[44] + (Screen_Center_x - Ekko_x), Land_Top[44] + (Screen_Center_y - Ekko_y), &MAP_trap_2, SRCINVERT);
	putimage(Land_Left[45] + (Screen_Center_x - Ekko_x), Land_Top[45] + (Screen_Center_y - Ekko_y), &MAP_trap_2_mask, NOTSRCERASE);
	putimage(Land_Left[45] + (Screen_Center_x - Ekko_x), Land_Top[45] + (Screen_Center_y - Ekko_y), &MAP_trap_2, SRCINVERT);
	putimage(Land_Left[46] + (Screen_Center_x - Ekko_x), Land_Top[46] + (Screen_Center_y - Ekko_y), &MAP_trap_2_mask, NOTSRCERASE);
	putimage(Land_Left[46] + (Screen_Center_x - Ekko_x), Land_Top[46] + (Screen_Center_y - Ekko_y), &MAP_trap_2, SRCINVERT);
	putimage(Land_Left[47] + (Screen_Center_x - Ekko_x), Land_Top[47] + (Screen_Center_y - Ekko_y), &MAP_board_2);
	putimage(Land_Left[48] + (Screen_Center_x - Ekko_x), Land_Top[48] + (Screen_Center_y - Ekko_y), &MAP_board_2);
	putimage(Land_Left[49] + (Screen_Center_x - Ekko_x), Land_Top[49] + (Screen_Center_y - Ekko_y), &MAP_board_2);
	putimage(Land_Left[50] + (Screen_Center_x - Ekko_x), Land_Top[50] + (Screen_Center_y - Ekko_y), &MAP_board_2);
	putimage(Land_Left[51] + (Screen_Center_x - Ekko_x), Land_Top[51] + (Screen_Center_y - Ekko_y), &MAP_board_2);
	putimage(Land_Left[52] + (Screen_Center_x - Ekko_x), Land_Top[52] + (Screen_Center_y - Ekko_y), &MAP_board_2);
	putimage(Land_Left[53] + (Screen_Center_x - Ekko_x), Land_Top[53] + (Screen_Center_y - Ekko_y), &MAP_board_2);
	putimage(Land_Left[54] + (Screen_Center_x - Ekko_x), Land_Top[54] + (Screen_Center_y - Ekko_y), &MAP_board_2);
	putimage(Land_Left[55] + (Screen_Center_x - Ekko_x), Land_Top[55] + (Screen_Center_y - Ekko_y), &MAP_board_2);
	putimage(Land_Left[56] + (Screen_Center_x - Ekko_x), Land_Top[56] + (Screen_Center_y - Ekko_y), &MAP_board_2);
	putimage(Land_Left[57] + (Screen_Center_x - Ekko_x), Land_Top[57] + (Screen_Center_y - Ekko_y), &MAP_board_2);
	putimage(Land_Left[58] + (Screen_Center_x - Ekko_x), Land_Top[58] + (Screen_Center_y - Ekko_y), &MAP_board_2);
	putimage(Land_Left[59] + (Screen_Center_x - Ekko_x), Land_Top[59] + (Screen_Center_y - Ekko_y), &MAP_board_2);
	putimage(Land_Left[60] + (Screen_Center_x - Ekko_x), Land_Top[60] + (Screen_Center_y - Ekko_y), &MAP_board_2);
	putimage(Land_Left[61] + (Screen_Center_x - Ekko_x), Land_Top[61] + (Screen_Center_y - Ekko_y), &MAP_board_2);
	putimage(Land_Left[62] + (Screen_Center_x - Ekko_x), Land_Top[62] + (Screen_Center_y - Ekko_y), &MAP_board_8);
	putimage(Land_Left[63] + (Screen_Center_x - Ekko_x), Land_Top[63] + (Screen_Center_y - Ekko_y), &MAP_board_7);
	putimage(Land_Left[64] + (Screen_Center_x - Ekko_x), Land_Top[64] + (Screen_Center_y - Ekko_y), &MAP_trap_3_mask, NOTSRCERASE);
	putimage(Land_Left[64] + (Screen_Center_x - Ekko_x), Land_Top[64] + (Screen_Center_y - Ekko_y), &MAP_trap_3, SRCINVERT);
	putimage(Land_Left[65] + (Screen_Center_x - Ekko_x), Land_Top[65] + (Screen_Center_y - Ekko_y), &MAP_trap_3_mask, NOTSRCERASE);
	putimage(Land_Left[65] + (Screen_Center_x - Ekko_x), Land_Top[65] + (Screen_Center_y - Ekko_y), &MAP_trap_3, SRCINVERT);
	putimage(Land_Left[66] + (Screen_Center_x - Ekko_x), Land_Top[66] + (Screen_Center_y - Ekko_y), &MAP_trap_3_mask, NOTSRCERASE);
	putimage(Land_Left[66] + (Screen_Center_x - Ekko_x), Land_Top[66] + (Screen_Center_y - Ekko_y), &MAP_trap_3, SRCINVERT);


	//炮塔&子弹
	float bullet_v_x[22][6];	//子弹在x方向的速度
	float bullet_v_y[22][6];	//子弹在y方向的速度
	int   m, n;			//用于计数

	for (i = 0; i < 22; i++)			//录入子弹的速度
	{
		bullet_v_x[i][0] = 1.8;
		bullet_v_y[i][0] = -1.8;
		bullet_v_x[i][1] = 0;
		bullet_v_y[i][1] = -1.5;
		bullet_v_x[i][2] = -2;
		bullet_v_y[i][2] = -2;
		bullet_v_x[i][3] = -2.1;
		bullet_v_y[i][3] = 2.1;
		bullet_v_x[i][4] = 0;
		bullet_v_y[i][4] = 1.5;
		bullet_v_x[i][5] = 2.2;
		bullet_v_y[i][5] = 2.2;

	}
	for (n = 0; n < 22; n++)
	{
		for (m = 0; m < 6; m++)
		{
			putimage(bullet_x[n][m] + (Screen_Center_x - Ekko_x), bullet_y[n][m] + (Screen_Center_y - Ekko_y), &BULLET_mask, NOTSRCERASE);	//输出子弹的图像
			putimage(bullet_x[n][m] + (Screen_Center_x - Ekko_x), bullet_y[n][m] + (Screen_Center_y - Ekko_y), &BULLET, SRCINVERT);
		}
	}
	for (n = 0; n < 22; n++)
	{
		for (m = 0; m < 6; m++)
		{
			bullet_x[n][m] = bullet_x[n][m] + bullet_v_x[n][m];
			bullet_y[n][m] = bullet_y[n][m] + bullet_v_y[n][m];
			if (bullet_x[n][m] >= enemy_x[n] + 550 || bullet_y[n][m] >= enemy_y[n] + 550 || bullet_x[n][m] <= enemy_x[n] - 550 || bullet_y[n][m] <= enemy_y[n] - 550)
			{
				bullet_x[n][m] = start_x[n][m];
				bullet_y[n][m] = start_y[n][m];
			}
			if (abs((long)(bullet_x[n][m] - Ekko_x)) < 27 && abs((long)(bullet_y[n][m] - Ekko_y)) < 27)//艾克与子弹碰撞的判定
				DeadOrNot = 1;
		}
	}
}