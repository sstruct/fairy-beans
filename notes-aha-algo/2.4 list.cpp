//list
////=========�Ⱥź͸�ֵҪ���ֿ�!
#include<stdio.h>
#include<stdlib.h>

//�����ṹ�壺����ڵ�
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
    head=NULL;      //ͷָ���ʼ��Ϊ��
    for(i=1;i<=n;i++)       //ѭ������n����
    {
        scanf("%d",&a);
        p=(struct node *)malloc(sizeof(struct node));       //���붯̬�ռ䣬������ʱָ��pָ������ڵ�
        p->data=a;      //�����ݴ��뵱ǰ�ڵ��data����
        p->next=NULL;       //���õ�ǰ�ڵ�ĺ��ָ��ָ��գ�Ҳ���ǵ�ǰ�ڵ����һ���ڵ�Ϊ��
        if(head==NULL)      //=========�Ⱥź͸�ֵҪ���ֿ�
            head=p;     //������ǵ�һ�������Ľڵ㣬��ͷָ��ָ������ڵ�
        else
            q->next=p;      //���򣬽���һ���ڵ�ĺ��ָ��ָ��ǰ�ڵ�
        q=p;        //ָ��qҲָ��ǰ�ڵ�
    }

    scanf("%d",&a);     //������������
    t=head;     //������ͷ����ʼ����
    while(t!=NULL)      //��û�е�������β����ʱ��ѭ��
    {
        if(t->next==NULL || t->next->data>a)
        //�����ǰ��������һ���ڵ������һ������ֵ���ڴ���������ʱ�����
        {
            p=(struct node *)malloc(sizeof(struct node));       //��̬����ռ䣬���ڴ�������ڵ�
            p->data=a;      //�����ݸ���p��data��
            p->next=t->next;        //�����ڵ�p�ĺ��ָ��ָ��ǰ�ڵ��ָ��ָ��ĺ�̽��
            t->next=p;      //��ǰ�ڵ���ָ��ָ�������ڵ�
            break;      //��������˳�ѭ��
        }
        t=t->next;      //������һ���ڵ�
    }

    //��������е�������
    t=head;
    while(t!=NULL)
    {
        printf("%d ",t->data);
        t=t->next;
    }
    return 0;
}



