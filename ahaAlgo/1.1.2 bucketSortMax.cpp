
#include<stdio.h>

int main()
{
    int book[10001],i,j,t,n;
    for(i=0;i<=1000;i++)    //���MҪ��0�_ʼ��ʼ��
        book[i]=0;

    scanf("%d",&n); //��Ҫ�����ֵĔ���
    for(i=1;i<=n;i++)   //ѭ�h�x�딵��; i��1�_ʼ
    {
        scanf("%d",&t); //&���@�Y��?
        book[t]++;
    }

    for(i=1000;i>=1;i--)
        for(j=1;j<=book[i];j++)
            printf("%d ",i);

    getchar();getchar();
    return 0;
}

//&���� 1. ȡ��ַ�� int *p=&a ȡa�ĵ�ַ��ֵ��ָ�����p��
//      2.
//      3.
//
