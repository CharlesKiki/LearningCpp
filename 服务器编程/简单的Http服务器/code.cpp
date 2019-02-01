/*
    1.这个简单的例子使用了系统库的方法和结构。
    2.Step1 在服务器端机器做Socket初始化，绑定端口
      Step2 开始While(1)循环服务器逻辑
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/sendfile.h>
#include<fcntl.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<assert.h>
#include<unistd.h>
#include<string.h>

/*
    绑定端口号
*/
const int port = 8888;

/*
    主线程
*/
int main(int argc,char *argv[])
{
    //Pip传参
    if(argc<0)
    {
        printf("need two parameter\n");
        return 1;
    }

    //socket参数
    int sock;
    //连接参数
    int connfd;
    //声明socket结构
    struct sockaddr_in sever_address;
    bzero(&sever_address,sizeof(sever_address));
    sever_address.sin_family = PF_INET;
    sever_address.sin_addr.s_addr = htons(INADDR_ANY);
    sever_address.sin_port = htons(8888);
 
    //该方法返回int类型值
    sock = socket(AF_INET,SOCK_STREAM,0);
 
    //函数原型assert()
    assert(sock>=0);
 
    //函数原型bing()
    int ret = bind(sock, (struct sockaddr*)&sever_address,sizeof(sever_address));
    assert(ret != -1);
 
    //函数原型listen()
    ret = listen(sock,1);
    assert(ret != -1);

    //服务器循环开始
    while(1)
    {
        struct sockaddr_in client;
        socklen_t client_addrlength = sizeof(client);
        connfd = accept(sock, (struct sockaddr*)&client, &client_addrlength);
        if(connfd<0)
        {
            printf("errno\n");
        }
        else{
                char request[1024];
                recv(connfd,request,1024,0);
                request[strlen(request)+1]='\0';
                printf("%s\n",request);
                printf("successeful!\n");
                char buf[520]="HTTP/1.1 200 ok\r\nconnection: close\r\n\r\n";//HTTP响应
                int s = send(connfd,buf,strlen(buf),0);//发送响应
                //printf("send=%d\n",s);
                int fd = open("hello.html",O_RDONLY);//消息体
                sendfile(connfd,fd,NULL,2500);//零拷贝发送消息体
                close(fd);
                close(connfd);
        }
    }
    return 0;
}