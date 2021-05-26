//深度优先搜索

#include<stdio.h>
int a[10],book[10],n;

void dfs(int step)
{
    int i;
    if(step==n+1)       //站在第n+1个盒子前，表面前n个盒子已经放好数字
    {
        for(i=1;i<=n;i++)
            printf("%d",a[i]);
        printf("\n");
        return;         //返回之前的一步，即最近一次调用dfs函数的地方 ？？？
    }
    for(i=1;i<=n;i++)
    {
        if(book[i]==0)      //判断牌是否已经被使用
        {
            a[step]=i;      //将牌放到盒子里
            book[i]=1;      //做好使用标记
            dfs(step+1);        //递归到下一个盒子
            book[i]=0;      //将刚才尝试的牌收回
        }
    }
    return;
}

int main()
{
    scanf("%d",&n);
    dfs(1);
    return 0;
}
