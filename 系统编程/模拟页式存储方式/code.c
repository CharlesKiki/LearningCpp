#include<stdio.h>
#include<stdlib.h>
#define Null 0

/*
	数据结构定义：
*/
struct node
{
	int page;
	int frame;
	int flag;
        struct node *next;
}*pagetable;



int frame_mang[3];
int rear=0,fris=0,num=0;
long precess_size;
int page_length;
long addr;
int page_num;

void create_pagetable();
void create_address();
void visit();
void change();
void display();

/*
	函数功能：测试用例
*/
main()
{	
	pagetable=Null;
 	
 	create_pagetable();
 	create_address();
 	
  	
  	
}

/*
	函数功能：
*/
void create_pagetable()
{	
        int i;
        struct node *p,*p1;

        p=Null;
        p1=Null;
        printf("please input the size of your process:");
        scanf("%ld", &precess_size);
	printf("\n");

        page_length=(int)(precess_size/1024);
        if(precess_size%1024!=0)
	{ 
		page_length=page_length+1;
	}

  	printf("page_length is :%d\n",page_length);

  	for(i=0;i<page_length;i++)
	{
  		p=(struct node*)malloc(sizeof(struct node));
  		p->flag=0;
 		p->page=i;
  		p->frame=-1;
		p->next=Null;

  		if(pagetable==Null)
  		{
			pagetable=p;
			p1=p;
		}
  		else
  		{
			p1->next=p;
			p1=p;
		}
  	} 
   
}
/*
	函数功能：
*/
void create_address()
{	int i=0;
   	
   	
   	
   	
   	printf("please input the addresses of the room you want to inqure: \n");
  	printf("addresses %d:",++i);
   	scanf("%ld",&addr);
   	printf("\n");

   	while(addr>=0){
        	page_num=(int)(addr/1024);

		if(addr>precess_size)
		{
         		printf("Adddress %ld Overbounds!!!!!\n",addr);
			i--;
         		getchar();
   			printf("addresses %d:",++i);
			scanf("%ld",&addr);
			printf("\n");
		}
		
		

                visit();
        	
        	printf("addresses %d:",++i);
		scanf("%ld",&addr);
		printf("\n");
   	}

}

/*
	函数功能：
*/
void visit()
{  	  	struct node *p1;
   		p1=pagetable;
		

		while(p1!=Null)
       		{
			if(p1->page==page_num) break;
			p1=p1->next;
		}

		if(p1->flag==0)
		{
			change(page_num);
		}

        	printf("When input Adddress is %ld\n:",addr);
		printf("\n");
        	display();
		
   	
   
} 

/*
	函数功能：
*/
void change(int page_num1)
{  	struct node *p1,*p;
   	p1=pagetable;
	p=pagetable;
   	while(p1!=Null)
       	{
		if(p1->page==page_num1) break;
		p1=p1->next;
	}
	if((rear+1)%3!=fris)
	{
		if(num==0)
		{
			num=1;
			frame_mang[rear]=page_num1;
			p1->frame=rear;
   			p1->flag=1;
		}
		else
		{	rear=(rear+1)%3;
			frame_mang[rear]=page_num1;
			p1->frame=rear;
   			p1->flag=1;
		}
	}
	else
	{	
		while(p!=Null)
       		{
			if(p->page==frame_mang[fris]) break;
			p=p->next;
		}
		p->frame=-1;
		p->flag=0;
		fris=(fris+1)%3;
		rear=(rear+1)%3;
		frame_mang[rear]=page_num1;
		p1->frame=rear;
   		p1->flag=1;
	}
 
   	
}

/*
	函数功能：
*/
void display()
{ 	int i;
	struct node *p1;
  	p1=pagetable;
	printf("The current Pagetabke:\n");
  	printf("         Pagenumber  ");
  	printf("  Truenumber  ");
  	printf("  Status  \n");
  	while(p1!=Null)
	{
  		printf("              %d       ",p1->page);
  		printf("      %d      ",p1->frame);
  		printf("     %d      \n",p1->flag);
		p1=p1->next;
  	}

	printf("The current Frame:\n");
	printf("\n");
	printf("         Truenumber  ");
  	printf("  Pagenum  \n");
	for(i=0;i<3;i++)
	{
		printf("              %d       ",i);
  		printf("      %d      \n",frame_mang[i]);
	}
}