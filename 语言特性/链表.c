动态数组类型 链表（动态数据类型） 链表的存在意义

静态 首地址+偏移量
用结构指针构成链表
（利用结构变量按需动态分配）

节点类型定义
节点特点：结构类型
struct stu
{
	unsigned num;  //date
	float score;
	struct stu *next;  //定义递归指针
}

创建单向链表
定义节点的结构类型，说明表头指针
按照结构的大小分配一块内存区域
将该区域的首地址赋给一个头指针
继续分配一块内存区域
将该区域的首地址分配给前一个节点的指针变量
继续上述过程，直到链表的尾


注意通用的动态储存分配函数 malloc
释放内存函数 
void free（void *p）
注意成对使用 防止内存泄露
/*
*对链表的综合操作
*功能有建立，排序，插入，删除，输出
*/
#include<stdio.h>
#include<malloc.h>
typedef int ElemType;
typedef struct NodeType
{
ElemType data;
struct NodeType *next;
} NodeType,*LinkType;
LinkType create()
{//建立链表，返回链表的首地址,头结点没有数据
LinkType head,p1,p2;
head=(LinkType)malloc(sizeof(NodeType));
p1=head;
while(p1->data!=0)//当data=0时链表结束
{
p2=p1;
p1=(LinkType)malloc(sizeof(NodeType));
printf("Enter student's information:\ndata=");
scanf("%d",&p1->data);
p2->next=p1;
}
p2->next=NULL;
free(p1);
return(head);
}
void output(LinkType head)
{//链表的输出，接收链表的首地址
head=head->next;
while(head!=NULL)
{
printf("data=%d\n",head->data);
head=head->next;
}
}
LinkType sort(LinkType head)
{//链表排序，接收链表首地址，返回链表首地址
LinkType ph,p1;
ElemType temp;
ph=head->next;
p1=head->next;
while(p1->next!=NULL)//冒泡法
{
ph=head;
while(ph->next!=NULL)
{
if(ph->data>ph->next->data)//按data由小到大排序
{
temp=ph->data;
ph->data=ph->next->data;
ph->next->data=temp;
}
ph=ph->next;
}
p1=p1->next;
}
return(head);
}
LinkType del(LinkType head)
{//删除结点,接收链表的首地址，返回链表的首地址
ElemType DelData;
LinkType ph,p;
ph=head->next;
printf("Enter the data you want to del:\nDelData=");
scanf("%d",&DelData);
while(ph!=NULL && ph->data!=DelData)//寻找要删除的结点
{
p=ph;
ph=ph->next;
}
if(ph==NULL)//没有找到要删除的结点
{
printf("Enter error!\n");
return(head);
}
else
{
if(ph==head->next)//删除头结点
{
head->next=ph->next;
}
else//删除其它结点
{
p->next=ph->next;
}
}
free(ph);
return(head);
}
LinkType insert(LinkType head)
{//插入结点，接收链表首地址，返回链表首地址
LinkType ph,p,insert,temp;
insert=(LinkType)malloc(sizeof(NodeType));
printf("Enter the data you want to insert:\ndata=");
scanf("%d",&insert->data);
ph=head->next;
while(ph!=NULL && ph->data < insert->data)//寻找插入的位置
{
p=ph;
ph=ph->next;
}
if(head->next->data > insert->data)//插入头部
{
temp=head->next;
head->next=insert;
insert->next=temp;
}
else//插入到其它地方
{
p->next=insert;
insert->next=ph;
}
return(head);
}
void main()
{
LinkType head;
head=create();
output(head);
printf("\n\n");
head=sort(head);
output(head);
printf("\n\n");
head=del(head);
output(head);
printf("\n\n");
head=insert(head);
output(head);
}

需要知识 结构类型指针