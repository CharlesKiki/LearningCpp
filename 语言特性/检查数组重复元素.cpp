#include <iostream>

using namespace std;

int remove_repeat(int *a, int l)//对起始地址为a，长度为l的数组进行去重，新的长度以返回值形式返回。
{
    int i,j, r=0; //i,j为循环下标，r为去重后元素总数，初始值为0

    for(i = 0; i < l; i ++)
    {
        for(j = 0; j < r; j ++)//检查是否重复
            if(a[j] == a[i]) break;
        if(j == r) //没有重复元素
            a[r++] = a[i]; //将当前元素放置与去重后数组的尾部，并增加去重后的总数。
    }

    return r; //返回新的长度。
}

int main()
{
    int num[20] = {0};
    cout << "enter num" << endl;
    cin>>num[0];  //cin>>num;报错，无法匹配的输入
    cout <<num[0]<<" "<<num[1]<<" "<<endl;
    return 0;
}
