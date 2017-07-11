//list
////=========等号和赋值要区分开!
#include<stdio.h>
#include<stdlib.h>

//创建结构体：链表节点
struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *head,*p,*q,*t;
    int i,n,a;
    scanf("%d",&n);
    head=NULL;      //头指针初始化为空
    for(i=1;i<=n;i++)       //循环读入n个数
    {
        scanf("%d",&a);
        p=(struct node *)malloc(sizeof(struct node));       //申请动态空间，并用临时指针p指向这个节点
        p->data=a;      //将数据存入当前节点的data域中
        p->next=NULL;       //设置当前节点的后继指针指向空，也就是当前节点的下一个节点为空
        if(head==NULL)      //=========等号和赋值要区分开
            head=p;     //如果这是第一个创建的节点，则将头指针指向这个节点
        else
            q->next=p;      //否则，将上一个节点的后继指针指向当前节点
        q=p;        //指针q也指向当前节点
    }

    scanf("%d",&a);     //读入待插入的数
    t=head;     //从链表头部开始遍历
    while(t!=NULL)      //当没有到达链表尾部的时候循环
    {
        if(t->next==NULL || t->next->data>a)
        //如果当前结点是最后一个节点或者下一个结点的值大于待插入数的时候插入
        {
            p=(struct node *)malloc(sizeof(struct node));       //动态申请空间，用于存放新增节点
            p->data=a;      //将数据赋给p的data域
            p->next=t->next;        //新增节点p的后继指针指向当前节点的指针指向的后继结点
            t->next=p;      //当前节点后继指针指向新增节点
            break;      //插入完毕退出循环
        }
        t=t->next;      //继续下一个节点
    }

    //输出链表中的所有数
    t=head;
    while(t!=NULL)
    {
        printf("%d ",t->data);
        t=t->next;
    }
    return 0;
}



