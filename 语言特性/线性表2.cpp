//带表头结点的单向链表
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
struct NODE {
    int          data;
    struct NODE *next;
} H,*head,*p,*q,*q1,*s1,*s2,*s3,*s4,*s;
int i,j,k,n,t,m;
int main() {
    srand(time(NULL));
 
    //填写头节点数据
    H.data=-1;
    H.next=NULL;
    head=&H;
 
    //创建10个节点的单链表
    p=head;
    for (i=0;i<10;i++) {
        q=(struct NODE *)malloc(sizeof(struct NODE));
        if (NULL==q) return 1;
        q->data=rand()%100;//填写0..99的随机值
        q->next=NULL;
        p->next=q;
        p=q;
    }
 
    //输出整个单链表
    s=head->next;
    while (1) {
        if (NULL==s) {
            printf("\n");
            break;
        }
        printf("%02d->",s->data);
        s=s->next;
    }
 
    //将值为5的结点插入到单链表的第k个结点前
    k=3;
    n=0;
    p=head;
    while (1) {
        if (NULL==p) {
            break;
        }
        n++;
        if (k==n) {
            q=(struct NODE *)malloc(sizeof(struct NODE));
            if (NULL==q) return 1;
            q->data=5;
            q->next=p->next;
            p->next=q;
            break;
        }
        p=p->next;
    }
 
    //输出整个单链表
    s=head->next;
    while (1) {
        if (NULL==s) {
            printf("\n");
            break;
        }
        printf("%02d->",s->data);
        s=s->next;
    }
 
    //删除第k个节点
    k=5;
    n=0;
    p=head;
    while (1) {
        if (NULL==p) {
            break;
        }
        n++;
        if (k==n) {
            q=p->next;
            if (q) {
                p->next=q->next;
                free(q);
            }
            break;
        }
        p=p->next;
    }
 
    //输出整个单链表
    s=head->next;
    while (1) {
        if (NULL==s) {
            printf("\n");
            break;
        }
        printf("%02d->",s->data);
        s=s->next;
    }
 
    //从小到大排序
    for (p=head;p!=NULL && p->next!=NULL;p=p->next) {
        for (q=p->next;q!=NULL && q->next!=NULL;q=q->next) {
            if (p->next->data > q->next->data) {
 
                //交换data
//              printf("swap %02d %02d\n",p->next->data,q->next->data);
//              t=p->next->data;p->next->data=q->next->data;q->next->data=t;
 
                //或者
 
                //交换next
//              printf("swap %02d %02d\n",p->next->data,q->next->data);
                s1=p->next;
                s2=p->next->next;
                s3=q->next;
                s4=q->next->next;
 
                if (s2!=s3) {
                     p->next=s3;
                    s3->next=s2;
                     q->next=s1;
                    s1->next=s4;
                } else {
                     p->next=s3;
                    s3->next=s1;
                           q=s3;
                    s1->next=s4;
                }
 
                //输出整个单链表
//              s=head->next;
//              while (1) {
//                  if (NULL==s) {
//                      printf("\n");
//                      break;
//                  }
//                  printf("%02d->",s->data);
//                  s=s->next;
//              }
//              getchar();
            }
        }
    }
 
    //输出整个单链表
    s=head->next;
    while (1) {
        if (NULL==s) {
            printf("\n");
            break;
        }
        printf("%02d->",s->data);
        s=s->next;
    }
 
    //将整个链表逆序
    if (head->next!=NULL && head->next->next!=NULL) {
        p=head->next;
        q=p->next;
        p->next=NULL;
        while (1) {
            q1=q->next;
            q->next=p;
            p=q;
            q=q1;
            if (NULL==q) break;
        }
        head->next=p;
    }
 
    //输出整个单链表
    s=head->next;
    while (1) {
        if (NULL==s) {
            printf("\n");
            break;
        }
        printf("%02d->",s->data);
        s=s->next;
    }
 
    //将单链表中前 m 个结点和后 n 个结点进行互换,m+n为链表总长10
    m=4;
    n=6;
    k=0;
    p=head;
    while (1) {
        if (NULL==p) {
            break;
        }
        k++;
        if (m+1==k) {
            q=p;
        }
        s=p;
        p=p->next;
    }
    s1=head->next;
    head->next=q->next;
    s->next=s1;
    q->next=NULL;
 
    //输出整个单链表
    s=head->next;
    while (1) {
        if (NULL==s) {
            printf("\n");
            break;
        }
        printf("%02d->",s->data);
        s=s->next;
    }
 
    //释放所有节点
    p=head->next;
    while (1) {
        if (NULL==p) {
            break;
        }
        q=p->next;
        free(p);
        p=q;
    }
 
    return 0;
}