#define _CRT_SECURE_NO_WARNINGS                 //消除VS警告
#include <stdio.h> 
int main() 
{ 
int a,b; 
freopen("E:\\GitHubSpace\\LearningCpp\\语言特性\\IO和缓冲区\\输入输出重定向\\in.txt","r",stdin);    //输入重定向，输入数据将从in.txt文件中读取 
freopen("E:\\GitHubSpace\\LearningCpp\\语言特性\\IO和缓冲区\\输入输出重定向\\out.txt","w",stdout);  //输出重定向，输出数据将保存在out.txt文件中 
while(scanf("%d %d",&a,&b)!=EOF) 
printf("%d\n",a+b); 
fclose(stdin);  //关闭文件 
fclose(stdout); //关闭文件 
return 0; 
}