#include "WinSock.h"   
#include "windows.h"   
#include "stdio.h"   
#pragma comment(lib,"wsock32.lib")   
   
#define RECV_PORT 2000   
#define SEND_PORT 3000   
#define MAX_FILESIZE 32*1024   
   
SOCKET sock,sock1;   
sockaddr_in ServerAddr; 
sockaddr_in ClientAddr;
   
struct Filedata   
{   
    char ffname[30];   
    char ffdata[MAX_FILESIZE];   
    int len;   
}DataPacket;   
   
int Addrlen;   
   
DWORD StartSock()   
{   
    WSADATA WSAData;   
    if(WSAStartup(MAKEWORD(2,2),&WSAData)!=0)   
    {   
        printf("sock init fail!\n");   
        return (-1);   
    }   
    return (1);   
}   
   
DWORD CreateSocket()   
{   
    sock = socket(AF_INET,SOCK_STREAM,0);   
    if(sock == SOCKET_ERROR)   
    {   
        printf("sock create fail!\n");   
        WSACleanup();   
        return (-1);   
    }   
       
    ServerAddr.sin_family      = AF_INET;   
    ServerAddr.sin_port        = htons(RECV_PORT);   
    ServerAddr.sin_addr.s_addr = htonl(INADDR_ANY);   
   
    if(bind(sock,(struct sockaddr*)&ServerAddr,sizeof(struct sockaddr_in))==SOCKET_ERROR)   
    {   
        printf("sock bind fail!");   
        return (-1);   
    }   
    return (1);   
}   
   
DWORD WriteFile(char *fname,char *fdata,int flen)   
{   
    int i = 0;   
    FILE *fp;   
    fp = fopen(fname,"w");   
    if(fp == NULL)   
    {   
        printf("cannot open this file\n");   
    }   
    for(i=0; i<flen; i++)   
    {   
        fputc(fdata[i],fp);   
    }   
    fclose(fp);   
    return (1);   
}   
   
DWORD ConnectProcess()   
{   
    Addrlen = sizeof(sockaddr_in);   
    if(listen(sock,5) < 0)   
    {   
        printf("Listen error");   
        return (-1);   
    }   
    printf("Listen...\n");   
    while(1)   
    {   
        sock1 = accept(sock,(struct sockaddr FAR *)&ClientAddr,&Addrlen);   
        while(1)   
        {   
            memset(DataPacket.ffname,0,30);   
            memset(DataPacket.ffdata,0,MAX_FILESIZE);   
            DataPacket.len = 0;   
            if(recv(sock1,(char*)&DataPacket,sizeof(DataPacket),0) <= 0)   
            {   
                break;   
            }   
            printf("Has received file:%s,length is %d",DataPacket.ffname, DataPacket.len);   
            WriteFile(DataPacket.ffname, DataPacket.ffdata, DataPacket.len);   
            printf("\n");   
        }   
    }   
}   
   
int main()   
{   
    if(StartSock() == -1)   
    {   
        return (-1);   
    }   
    if(CreateSocket() == -1)   
    {   
        return (-1);   
    }   
    if(ConnectProcess() == -1)   
    {   
        return (-1);   
    }   
    return (1);   
}   
   