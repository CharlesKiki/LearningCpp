/***********************************************************/
// �������ƣ�SwapSort.cpp
// ����Ŀ�ģ�ʹ�ÿ⺯��ʵ������(ʹ��C++���Sort��vector)
// ������Դ��
// ���ڣ�    2013-9-14 9:28:30
// ���ߣ�    JohnnyHu
/***********************************************************/
//
#include <iostream>
#include <cstdlib>     /* srand(), rand() */
#include <ctime>       /* time() */
//���õ�ע��ϰ�ߣ������ô�ע������
#include <algorithm>
#include <vector>  /*push_back()*/
//vector �������÷�
//vector<int>v2(init_size,0); ���Ԥ�ȶ����ˣ�intinit_size;���ĳ�Աֵ������ʼ��Ϊ0��
//ע��һ�����ɣ���������ַ��������Ǻ궨���
#include <set>

using namespace std;

int main ()
{
    srand(time(NULL));  // ��ʼ�����������
    
    vector<int> vec;
    //����һ��ʵ������������Ϊ��λ��vector����������һ������
    for( int i = 0; i != 20; i++)
        vec.push_back( rand());

    cout << "����֮ǰ: " << endl;
    for(int i = 0; i != 20; i++)    // ԭʼ����
    {
        if (i!=0 && i%5 == 0 )
            cout << endl;

        cout << vec[i] << "\t";
    }
    cout << endl;

    sort(vec.begin(), vec.end());

    cout << "����֮��: " << endl;
    for(int i = 0; i != 20; i++)    // �����
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
//λ������У�&(��λ��)��|(��λ��)��^(��λ���)��~ (��λȡ��)
void clr(int i)     {        a[i>>SHIFT] &= ~(1<<(i&MASK));}
void test(int i)    { return a[i>>SHIFT] &   (1<<(i&MASK));}