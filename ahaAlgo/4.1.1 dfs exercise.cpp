//dfs 解决 等式成立问题

#include<stdio.h>
int a[10],book[10],total;

void dfs(int step)
{
    int i;
    if(step==10)        //边界条件
    {
        if(a[1]*100+a[2]*10+a[3]+a[4]*100+a[5]*10+a[6]==a[7]*100+a[8]*10+a[9])
        {
            total++;
            printf("%d%d%d %d%d%d %d%d%d\n",a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],a[9]);
        }
        return;
    }

    for(i=1;i<=9;i++)       //深度搜索
    {
        if(book[i]==0)
        {
            a[step]=i;
            book[i]=1;
            dfs(step+1);
            book[i]=0;
        }
    }
    return;
}

int main()
{
    dfs(1);
    printf("%d ",total/2);      //注意除以2
    return 0;
}
