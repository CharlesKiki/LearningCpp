#include <iostream>  //文件作用域
using namespace std;

//6.1 直接插入排序算法
void InsertSort(int *a,int n)
//插入排序函数，a为待排序的数组，n为数组中的元素个数
{
	int temp,j;
	for(int i=1;i<n;i++)  //从第二个元素开始比较
	{
		temp=a[i];  //记录当前元素
		for(j=i;j>0 &&temp<a[j-1];j--)  //比较元素并找到插入的位置
		a[j]=a[j-1];
		a[j]=temp;
	}
}
void main()
{
	int arr[]={9,6-3,17,-11,7};
	InsertSort(arr,6); 
	cout<<arr[i]<<" ";
	cout<<endl;
	return 0;                       //需要n(n-1)次最坏情况比较 所以算法复杂度为O（n^2）
}