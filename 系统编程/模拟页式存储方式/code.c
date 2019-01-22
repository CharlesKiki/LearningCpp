#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define Null 0
/*
	程序设计思路：使用链表的方式表达内存的连续，使用结构体来表达一个可用的内存
	单元

	这里还有一个尚未验证的背景知识。似乎现代的操作系统会给每个进程分配4G的虚拟
	内存，这就导致了用户输入的addr值可以是0~4G的内存大小（也就是说这个程序
	默认不可以输入大于4G的内存容量）
	并且precess_size是整个分配内存空间的大小。由这个参数可以得到一个页的的小
	值

	这个程序的两个create函数和其他的函数有高度的耦合度。
	代码开头的全局变量实际上是连接几个方法的参数，这些参数往往和用户的输入有关

	约定在这个程序中，当描述对内存单元访问的意思等用于对连续申请的内存单元上的
	结构体进行访问
	而且需要注意的是，这个内存单元虽然是模拟访问的，但是它并没有实际存在能存储
	数据的空间，也就是只能标识一个内存空间被占用了

*/


/*
	数据结构定义：
*/
struct node
{
	int page;	//页号
	int frame;  //物理块号
	int flag;   //状态位
	struct node *next;
}*pagetable;


/*
	变量声明：
	frame_mang[3]			缓冲区？？？
	rear=0,fris=0,num=0		栈？？？
	precess_size			需要分配给进程的内存大小，这是模拟输入的值，
	//最好1024以上的大小
	page_length				页的大小
	addr					地址，这个地址指向了想要访问的内存单元
	page_num				页的数量，这个数量和声明的内存大小有关
*/
int frame_mang[3];
int rear = 0, fris = 0, num = 0;
long precess_size;
int page_length;
long addr;
int page_num;

void create_pagetable();	//创建页表
void create_address();		//输入地址进行   处理？？？？
void visit();
/*
对输入地址进行  处理？？？
visit函数是
*/
void change(int page_num1);				//调换
void display();				//显示页表

/*
	函数功能：测试用例
*/
int main()
{
	pagetable = Null;

	create_pagetable();
	/*
		执行该方法会触发用户输入一个以byte为单位的内存大小
		这会让pagetable初始化为一个指定大小的内存区域
	*/
	create_address();
	return 0;
}

/*
	函数功能:创建
	使用场景：先初始化
*/
void create_pagetable()
{
	//下标，
	int i;
	//两个页结构指针
	struct node *p, *p1;

	//初始化页结构指针
	p = Null;
	p1 = Null;
	//输入进程的值

	printf("please input the size of your process:");
	//十进制的数，这可能是一个根据byte来输入的值，也就是说，它的输入值
	//应该是1024以上的输入值
	scanf("%ld", &precess_size);
	printf("\n");

	//最后转化为，mb的大小
	page_length = (int)(precess_size / 1024);
	//大小比1mb小，自动加1，不能小于1mb的大小
	if (precess_size % 1024 != 0)
	{
		page_length = page_length + 1;
	}


	//页长
	printf("page_length is :%d\n", page_length);

	//页链表结构作为头节点，循环添加节点
	for (i = 0; i < page_length; i++)
	{
		/*
			malloc分配的空间，占用的逻辑地址是连续的，但物理内存则不一定。
			用指针可以一个挨一个访问
			就像连续一样
			这个由系统帮助完成了
			系统会为每个程序分配虚拟的4GB空间
		*/
		p = (struct node*)malloc(sizeof(struct node));
		/*
			commit：flag  01
			page 页的逻辑增长序号
			frame -1
		*/
		p->flag = 0;
		p->page = i;
		p->frame = -1;
		p->next = Null;

		//在测试用例中，先声明了页结构表
		if (pagetable == Null)
		{
			pagetable = p;
			p1 = p;
		}
		else
		{
			p1->next = p;
			p1 = p;
		}
	}

}
/*
	函数功能：地址链表建立
	该方法接受用户输入的一个地址值
*/
void create_address()
{
	//用作循环的下标，局部变量，
	int i = 0;

	//输入一个地址，这个地址变量为long类型，全局变量
	printf("please input the addresses of the room you want to inqure: \n");
	printf("addresses %d:", ++i);
	scanf("%ld", &addr);
	printf("\n");

	//用户输入了addr变量，要访问的内存单元大小
	/*
		commit：注意访问越界问题
	*/
	while (addr >= 0)
	{
		//获得访问的内存地址编号，page_num全局变量
		/*
			这里不清楚到底这个函数是访问的功能还是赋值的功能
		*/
		page_num = (int)(addr / 1024);

		/*
			注意这个地方，addr变量存储了用户希望访问的内存位置，这个位置是
			逻辑上内存线性增长的大小
			这个大小和进程的大小进行对比，为了检查是否访问越界。
		*/
		if (addr > precess_size)
		{
			//数组越界
			printf("Adddress %ld Overbounds!!!!!\n", addr);
			//下标自减
			i--;
			//获得一个字符输入？？
			getchar();
			printf("addresses %d:", ++i);
			scanf("%ld", &addr);
			printf("\n");
		}


		//页面调用，该方法完成了对地址的访问
		visit();

		printf("addresses %d:", ++i);
		scanf("%ld", &addr);
		printf("\n");
	}

}

/*
	函数功能：页面调用
*/
void visit()
{
	/*
		局部的变量，声明结构体指针。
		使用该指针获取全局页式内存单元的头指针
	*/
	struct node *p1;
	p1 = pagetable;

	/*
		当一个大型项目在实行的时候，内存中是否存在一个对象或者状态
		很难预料到程序的执行状态
		这个while循环对链表进行了遍历
		但是这个遍历无论是否命中了目标的内存地址都不会有变化，但是指针的
		指向指向了下一个内存单元
		遍历的结果是p1指向最后一个内存单元，但是如果命中了对应的地址的页码，那么，p1就是对应的页码对象
	*/

	while (p1 != Null)
	{
		//pagenum就是用户输入的访问地址的所在页
		if (p1->page == page_num) break;
		p1 = p1->next;
	}

	/*
		实际上p1也可能是程序命中的对应页码
		如果最后一个内存单元的标志位为0
		触发动作change
	*/
	if (p1->flag == 0)
	{
		change(page_num);
	}

	printf("When input Adddress is %ld\n:", addr);
	printf("\n");
	display();



}

/*
	函数功能：页面置换
	这个方法接受一个目标访问的内存地址，也就是页码
	该方法使用了FIFO淘汰页算法
	栈的应用，使用了先进先出的方式
*/
void change(int page_num1)
{
	//声明局部变量
	struct node *p1, *p;
	p1 = pagetable;
	p = pagetable;

	//获得目标页数
	while (p1 != Null)
	{
		if (p1->page == page_num1) break;
		p1 = p1->next;
	}

	if ((rear + 1) % 3 != fris)
	{
		if (num == 0)
		{
			num = 1;
			frame_mang[rear] = page_num1;
			p1->frame = rear;
			p1->flag = 1;
		}
		else
		{
			rear = (rear + 1) % 3;
			frame_mang[rear] = page_num1;
			p1->frame = rear;
			p1->flag = 1;
		}
	}
	else
	{
		while (p != Null)
		{
			if (p->page == frame_mang[fris]) break;
			p = p->next;
		}
		p->frame = -1;
		p->flag = 0;
		fris = (fris + 1) % 3;
		rear = (rear + 1) % 3;
		frame_mang[rear] = page_num1;
		p1->frame = rear;
		p1->flag = 1;
	}


}

/*
	函数功能：打印当前所有页的内容
*/
void display()
{
	int i;
	struct node *p1;
	p1 = pagetable;
	printf("The current Pagetabke:\n");
	printf("         Pagenumber  ");
	printf("  Truenumber  ");
	printf("  Status  \n");
	while (p1 != Null)
	{
		printf("              %d       ", p1->page);
		printf("      %d      ", p1->frame);
		printf("     %d      \n", p1->flag);
		p1 = p1->next;
	}

	printf("The current Frame:\n");
	printf("\n");
	printf("         Truenumber  ");
	printf("  Pagenum  \n");
	for (i = 0; i < 3; i++)
	{
		printf("              %d       ", i);
		printf("      %d      \n", frame_mang[i]);
	}
}