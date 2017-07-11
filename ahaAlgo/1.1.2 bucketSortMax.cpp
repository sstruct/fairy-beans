
#include<stdio.h>

int main()
{
    int book[10001],i,j,t,n;
    for(i=0;i<=1000;i++)    //數組要從0開始初始化
        book[i]=0;

    scanf("%d",&n); //需要排序數字的數量
    for(i=1;i<=n;i++)   //循環讀入數據; i從1開始
    {
        scanf("%d",&t); //&在這裏是?
        book[t]++;
    }

    for(i=1000;i>=1;i--)
        for(j=1;j<=book[i];j++)
            printf("%d ",i);

    getchar();getchar();
    return 0;
}

//&符号 1. 取地址符 int *p=&a 取a的地址赋值到指针变量p上
//      2.
//      3.
//
