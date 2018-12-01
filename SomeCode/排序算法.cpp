/***********************************************************/
// 程序名称：SwapSort.cpp
// 程序目的：使用库函数实现排序(使用C++库的Sort，vector)
// 程序来源：
// 日期：    2013-9-14 9:28:30
// 作者：    JohnnyHu
/***********************************************************/
//
#include <iostream>
#include <cstdlib>     /* srand(), rand() */
#include <ctime>       /* time() */
//良好的注释习惯，在引用处注明函数
#include <algorithm>
#include <vector>  /*push_back()*/
//vector 容器的用法
//vector<int>v2(init_size,0); 如果预先定义了：intinit_size;他的成员值都被初始化为0；
//注意一个技巧：绝大多数字符参数都是宏定义的
#include <set>

using namespace std;

int main ()
{
    srand(time(NULL));  // 初始化随机数种子
    
    vector<int> vec;
    //这是一个实例化的以整型为单位的vector容器，类似一个数组
    for( int i = 0; i != 20; i++)
        vec.push_back( rand());

    cout << "排序之前: " << endl;
    for(int i = 0; i != 20; i++)    // 原始数据
    {
        if (i!=0 && i%5 == 0 )
            cout << endl;

        cout << vec[i] << "\t";
    }
    cout << endl;

    sort(vec.begin(), vec.end());

    cout << "排序之后: " << endl;
    for(int i = 0; i != 20; i++)    // 排序后
    {
        if (i!=0 && i%5 == 0 )
            cout << endl;

        cout << vec[i] << "\t";
    }

    return 0;

}

http://blog.csdn.net/zeb_perfect/article/details/41312397

http://blog.csdn.net/yuanwenqun2/article/details/6455708

void set(int i)     {        a[i>>SHIFT] |=  (1<<(i&MASK));}
//位运算符有：&(按位与)、|(按位或)、^(按位异或)、~ (按位取反)
void clr(int i)     {        a[i>>SHIFT] &= ~(1<<(i&MASK));}
void test(int i)    { return a[i>>SHIFT] &   (1<<(i&MASK));}