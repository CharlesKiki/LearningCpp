#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
	/*
		commit：
				查询序号为m的学生的四门课程的成绩
		函数声明(仅仅是声明)：
				该方法返回float类型值，接受一个函数指针，一个int类型
	*/
	float *find(float (*p)[4],int student_id);
	//二维数组
	float score[][4]={{50,51,52,55},{70,70,40,80},{77,99,88,67}};
	/*
		cimmit：只要指针返回类型和函数返回类型一样就可以赋值
	*/
	float *functionpoint=NULL;
	int index,studentID;

	cout<<"Please enter the ID you want to search:(Only 1 2 3)";
	cin>>studentID;
	//初始化函数指针，返回为一维数组指针，指向一个学生成绩
	functionpoint=find(score,studentID);
	for(index=0 ;index<4 ;index++)
	{
		cout<<*(functionpoint + index)<<" "<<endl;
	}
	system("PAUSE");
	return 0;
}
/*
	函数功能：
			该函数返回二维数组的一维index
	commit：
			p是float类型
			p是指向二维数组的指针，加*取一维数组的指针
			float (*p)[4] 中(*p)相当于[index]
	函数定义：
			参数1：函数数组
			参数2：int 类型
	
*/
float *find(float (*p)[4],int student_id)
{
	
	float *functionpoint=NULL;
	//这句话返回了实际上的二维数组值
	functionpoint=*(p+student_id);
	return functionpoint;
}