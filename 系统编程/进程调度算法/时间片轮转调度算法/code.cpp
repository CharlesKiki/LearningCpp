#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 1000;//假设能够容纳的进程最多的个数
 
struct Process
{
    int pos;                          //代表第几个输入的进程
    char Process_name[50];            //进程名字，默认最长长度占用50字符
    double Arrival_time;             //进程到达时间
    double Service_time;             //服务时间       进程所需要的时间
    double Start_time;               //服务开始时间
    double End_time;                 //服务结束的时间
    double Turnaround_time;          //周转时间    进程结束的时间-进程到达时间
    double Weight_Turnaround_time;   //带权周转时间       周转时间 / 服务时间
}process[MAXN];
double every_time;
int n;
 
void Init()
{
    printf("请输入时间片的时间:");
    scanf("%lf",&every_time);
    printf("请输入进程的数量：");
    scanf("%d",&n);
    for(int i = 0;i < n;i ++)
    {
        cout<<"请输入第"<<i+1<<"个进程的名字  到达时间  服务时间"<<endl;
        scanf("%s",process[i].Process_name);
        scanf("%lf",&process[i].Arrival_time);
        scanf("%lf",&process[i].Service_time);
        process[i].pos = i;
    }
}
bool cmp1(const Process &a,const Process &b)
{
    return a.Arrival_time < b.Arrival_time;
}
 
void Solve_TSRA()
{
    /*
    时间片轮转算法：
    */
    printf("时间片轮转算法:\n");
    queue<Process> que;
    sort(process,process+n,cmp1);
    bool vis[MAXN];      //表示这个进程有没有在完成，完成使用true表示
    Process ans[MAXN];
    double time = max(0.0,process[0].Arrival_time);int index = 0;
    memset(vis,false,sizeof(vis));
    que.push(process[0]);vis[process[0].pos] = 1;
    for(int i = 0;i < n;i ++)
    {
        while(!que.empty())
        {
            Process temp = que.front();   que.pop();
            temp.Start_time = time;
            temp.End_time = temp.Service_time >= every_time ? time + every_time : time + temp.Service_time;
            for(int j = 0;j < n;j ++)
                if(!vis[process[j].pos] && process[j].Arrival_time <= temp.End_time)
                {
                    vis[process[j].pos] = 1;
                    que.push(process[j]);
                }
            if(temp.Service_time > every_time)
            {
                temp.Service_time -= every_time;
                que.push(temp);
                time += every_time;
            }
            else
                time += temp.Service_time;       //这里面的时间都是有联系的，所以不用再次更新time
            ans[index++] = temp;             //将顺序存储到最终的答案序列中
        }
        bool flag = false; //判断是否所有的进程都已经完成
        for(int j = 0;j < n;j ++)
            if(!vis[process[j].pos])
            {
                que.push(process[j]);//将一个时间最靠前的添加到队列中
                time = process[j].Arrival_time;   //这里就要更新time了，因为这里的时间和上面的有些脱节！
                flag = true;break;
            }
        if(!flag) break;
    }
    printf("进程的运行顺序为：\n");
    printf("%s",ans[0].Process_name);
    for(int i = 1;i < index;i ++)
        printf("-->%s",ans[i].Process_name);
    printf("\n");
    printf("name\tarrive_time\tservice_time\tstart_time\tend_time\n");
    for(int i= 0;i < index;i ++)
        printf("%s\t%.2lf\t\t%.2lf\t\t%.2lf\t\t%.2lf\n",ans[i].Process_name,ans[i].Arrival_time,ans[i].Service_time,ans[i].Start_time,ans[i].End_time);
//    for(int i= 0;i < index;i ++)
//        cout<<ans[i].Process_name<<"\t"<<ans[i].Arrival_time<<"\t\t"<<ans[i].Service_time<<"\t\t"<<ans[i].Start_time<<"\t\t"<<ans[i].End_time<<endl;
}
int main()
{
    Init();
    Solve_TSRA();
    return 0;
}