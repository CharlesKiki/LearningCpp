#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <cstring>
 
using namespace std;
const int MAXN = 1000;
int n;
struct Process
{
    int pos;                          //代表第几个输入的进程
    char Process_name[50];            //进程名字，默认最长长度占用50字符
    double Arrival_time;             //进程到达时间
    double Service_time;             //服务时间       进程所需要的时间
    double Start_time;               //服务开始时间
    double End_time;                 //服务结束的时间
    double Priority;                 //优先权，这里面的优先级权是不能修改的！！！
    bool operator < (const Process &a)const
    {
        if(Priority == a.Priority)
            return Arrival_time > a.Arrival_time;
        return Priority < a.Priority;
    }
}process[MAXN];
void Init()
{
    printf("请输入进程的数量：");
    scanf("%d",&n);
    for(int i = 0;i < n;i ++)
    {
        cout<<"请输入第"<<i+1<<"个进程的名字  到达时间  服务时间  优先权"<<endl;
        scanf("%s",process[i].Process_name);
        scanf("%lf",&process[i].Arrival_time);
        scanf("%lf",&process[i].Service_time);
        scanf("%lf",&process[i].Priority);
        process[i].pos = i;
    }
}
bool cmp1(Process &a,Process &b)
{
    return a.Arrival_time < b.Arrival_time;
}
 
void Solve_PPS()
{
    /*
    抢占式优先权调度:如果当前进程在执行时，如果后面出现了一个优先级更高的进程，我们就要暂时停止这个进程，先执行优先权高的程序！！
    */
    printf("抢占式优先权调度:\n");
    priority_queue<Process> que;
    sort(process,process+n,cmp1);
    bool vis[MAXN];      //表示这个进程有没有在完成，完成使用true表示
    Process ans[MAXN];
    double time = max(0.0,process[0].Arrival_time);int index = 0;
    memset(vis,false,sizeof(vis));
    //首先将第一个放到优先队列中！
    que.push(process[0]);vis[process[0].pos] = 1;
    for(int i = 0;i < n;i ++)
    {
        while(!que.empty())
        {
            bool ok = false;
            Process temp = que.top();que.pop();
            //在temp的服务时间中，如果有新的优先权高的进程出现，那么就先执行优先权更高的进程，暂停这一段进程，并且更新这个进程所需要的时间等等
            temp.Start_time = time;temp.End_time = time + temp.Service_time;
            for(int j = 0;j < n;j ++)
            {//在当前优先队列中的优先权永远是要小于当前执行的优先权的，那么我们只需要判断vis为false的就可以了！
                if(!vis[process[j].pos] && process[j].Priority > temp.Priority && process[j].Arrival_time < temp.End_time)
                {
                    ok = true;
                    vis[process[j].pos] = 1;
                    que.push(process[j]);
                    temp.End_time = process[j].Arrival_time;
                    ans[index++] = temp;
                    temp.Service_time = time + temp.Service_time - temp.End_time;//更新当前的服务时间
                    que.push(temp);
                    time = process[j].Arrival_time;
                    break;
                }
            }
            for(int j = 0;j < n;j ++)//将这段时间内时间已经满足要求，但是优先权不是很高的添加到队列中！
            {
                if(!vis[process[j].pos] && process[j].Arrival_time <= temp.End_time)
                {
                    vis[process[j].pos] = 1;
                    que.push(process[j]);
                }
            }
            if(!ok)  //表示这个执行过程中没有打断的其它进程到来
            {
                time += temp.Service_time;
                ans[index++] = temp;
            }
 
        }
        bool flag = false; //判断是否所有的进程都已经完成
        for(int j = 0;j < n;j ++)
            if(!vis[process[j].pos])
            {
                vis[process[j].pos] = 1;
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
    //for(int i= 0;i < index;i ++)
       // cout<<ans[i].Process_name<<"\t"<<ans[i].Arrival_time<<"\t\t"<<ans[i].Service_time<<"\t\t"<<ans[i].Start_time<<"\t\t"<<ans[i].End_time<<endl;
}
int main()
{
    Init();
    Solve_PPS();
    return 0;
}
 
/*
5
1 1 10 80
2 11 15 20
3 21 10 50
4 31 10 120
5 41 10 100
3
A 0 5 1
B 2 2 2
C 3 4 3
*/