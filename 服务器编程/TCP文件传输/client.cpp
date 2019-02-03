#include "WinSock.h"   
#include "windows.h"   
#include "stdio.h"   
#pragma comment(lib,"wsock32.lib")   
   
#define RECV_PORT 2000   
#define SEND_PORT 3000   
#define MAX_FILESIZE 32*1024   
   
SOCKET sock;   
sockaddr_in ServerAddr;
   
struct Filedata   
{   
    char ffname[30];   
    char ffdata[MAX_FILESIZE];   
    int len;   
}DataPacket;   
   
DWORD StartSock()   
{   
    WSADATA WSAData;   
    if(WSAStartup(MAKEWORD(2,2),&WSAData)!=0)   
    {   
        printf("sock init fail!\n");   
        return (-1);   
    }   
           
    ServerAddr.sin_family      = AF_INET;   
    ServerAddr.sin_port        = htons(RECV_PORT);   
    ServerAddr.sin_addr.s_addr = inet_addr("127.0.0.1");   
   
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
   
    return (1);   
}   
   
void CallServer()   
{   
    CreateSocket();   
    while(connect(sock,(struct sockaddr*)&ServerAddr,sizeof(ServerAddr)) == SOCKET_ERROR)   
        printf("Connect...\n");   
}   
   
DWORD GetFile(char *fname)   
{   
    int    i;   
    FILE   *fp;   
    int    Filesize;   
    int    count;   
    int    total = 0;   
    char   buffer[100];   
    char   Senddata[MAX_FILESIZE];   
   
    fp = fopen(fname,"r");   
    if(fp == NULL)   
    {   
        printf("cannot open file\n");   
        return (0);   
    }   
   
    i = 0;   
    Filesize =0;   
   
    memset(Senddata,0,MAX_FILESIZE);   
    while(!feof(fp))   
    {   
        count = fread(buffer,sizeof(char),100,fp);   
        if(ferror(fp))   
        {   
            printf("read file error");   
            break;   
        }   
        Filesize += count;   
   
        if(Filesize > MAX_FILESIZE)   
        {   
            printf("your file is too big\n");   
            fclose(fp);   
            return (0);   
        }   
        memcpy(&Senddata[i],buffer,count);   
        i += count;   
    }   
   
    fclose(fp);   
    Senddata[i] = '\0';   
    strcpy(DataPacket.ffname,fname);   
    memcpy(DataPacket.ffdata,Senddata,Filesize);   
    DataPacket.len = Filesize;   
    printf("%s %d\n",DataPacket.ffname,DataPacket.len);   
    return (1);   
}   
   
DWORD TCPSendPacket(struct Filedata Packet)   
{   
    int length;   
    length = send(sock,(char*)&Packet,sizeof(DataPacket),0);   
    if(length <= 0)   
    {   
        printf("send Filedata error\n");   
        closesocket(sock);   
        WSACleanup();   
        return (-1);   
    }   
    return (1);   
}   
   
int main()   
{   
    char sendfilename[30];   
    StartSock();   
    CallServer();   
    printf("connect ok!\n");   
    while(1)   
    {   
        printf("Input your filename to send:\n");   
        scanf("%s", sendfilename);   
        if(strcmp(sendfilename, "exit") == 0)   
        {   
            break;   
        }   
        if(GetFile(sendfilename) == 0)   
            continue;   
        TCPSendPacket(DataPacket);   
    }   
    closesocket(sock);   
    return 0;   
}   
   