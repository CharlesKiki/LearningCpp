#include <iostream>

using namespace std;

int remove_repeat(int *a, int l)//����ʼ��ַΪa������Ϊl���������ȥ�أ��µĳ����Է���ֵ��ʽ���ء�
{
    int i,j, r=0; //i,jΪѭ���±꣬rΪȥ�غ�Ԫ����������ʼֵΪ0

    for(i = 0; i < l; i ++)
    {
        for(j = 0; j < r; j ++)//����Ƿ��ظ�
            if(a[j] == a[i]) break;
        if(j == r) //û���ظ�Ԫ��
            a[r++] = a[i]; //����ǰԪ�ط�����ȥ�غ������β����������ȥ�غ��������
    }

    return r; //�����µĳ��ȡ�
}

int main()
{
    int num[20] = {0};
    cout << "enter num" << endl;
    cin>>num[0];  //cin>>num;�����޷�ƥ�������
    cout <<num[0]<<" "<<num[1]<<" "<<endl;
    return 0;
}
