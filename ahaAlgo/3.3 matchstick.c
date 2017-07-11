//火柴棍等式

#include<stdio.h>

//int count(int x)
//{
//    int num=0;
//    int f[10]={6,2,5,5,4,5,6,3,7,6};
//    while(x/10!=0)
//    {
//        num+=count(x%10);     //迭代也可以，但是复杂度更高
//        x=x/10;
//    }
//    num+=f[x];
//    return num;
//}


int fun(int n)
{
    int num=0;
    int f[10]={6,2,5,5,4,5,6,3,7,6};
    while(n/10!=0)
    {
        num+=f[n%10];
        n=n/10;
    }
    num+=f[n];
    return num;
}

int main()
{
    int a,b,c,n,sum=0;
    scanf("%d",&n);
    for(a=0;a<=1111;a++)
    {
        for(b=0;b<=1111;b++)
        {
            c=a+b;      //这个条件不能少
            if(fun(a)+fun(b)+fun(c)==n-4)       //若成功找出一组解，sum+1
            {
                printf("%d %d %d\n",a,b,c);
                sum++;
            }
        }
    }
    printf("%d",sum);
    return 0;
}
