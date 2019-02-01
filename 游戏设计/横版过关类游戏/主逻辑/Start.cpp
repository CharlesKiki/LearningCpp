#include<graphics.h>
#include<conio.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
#pragma comment(lib,"Winmm.lib")
extern IMAGE start;
//开始界面
void Start()
{
	MOUSEMSG mouse;
	mouse.mkLButton = false;
	mouse.x = 0;
	mouse.y = 0;
	while (true)//开始菜单
	{
		BeginBatchDraw();
		putimage(0, 0, &start);


		if (MouseHit())
			mouse = GetMouseMsg();
		if (mouse.mkLButton)//单击出现小圈
		{
			circle(mouse.x, mouse.y, 5);
		}

		if (mouse.x < 1522 && mouse.x > 1247 && mouse.y > 413 && mouse.y < 473)//当鼠标放在按钮上
		{
			rectangle(1247, 473, 1522, 413);
		}
		if (mouse.x < 1522 && mouse.x > 1247 && mouse.y > 502 && mouse.y < 570)
		{
			rectangle(1247, 576, 1522, 516);
		}

		if (mouse.mkLButton && mouse.x < 1535 && mouse.x > 1260 && mouse.y > 413 && mouse.y < 473)//点击按钮
		{
			mciSendString("close StartWord", NULL, 0, NULL);
			mciSendString("open .\\图片资源\\时间不在于拥有多少.mp3 alias StartWord", NULL, 0, NULL);
			mciSendString("play StartWord", NULL, 0, NULL);
			FlushMouseMsgBuffer();
			break;
		}

		if (mouse.mkLButton && mouse.x < 1535 && mouse.x > 1260 && mouse.y > 502 && mouse.y < 570)
		{
			FlushMouseMsgBuffer();
			closegraph();
			exit(0);
		}

		FlushBatchDraw();

	}
}
