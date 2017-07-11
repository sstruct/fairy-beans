//深度优先搜索找出最短路径
//break 和 continue： break 是终止循环而执行循环后面的语句，continue是跳过循环体中的余下部分直接开始下一次循环


#include<stdio.h>
int n,m,p,q,min=999999;
int a[51][51],book[51][51];

void dfs(int x,int y,int step)
{
    int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
    int tx,ty,k;

    if(x==p && y==q)
    {
        if(step<min)
            min=step;
        return;
    }

    for(k=0;k<=3;k++)
    {
        tx=x+next[k][0];
        ty=y+next[k][1];

        if(tx<1 || tx>n ||ty<1 ||ty>n)
            continue;
        if(a[tx][ty]==0 && book[tx][ty]==0)
        {
            book[tx][ty]=1;
            dfs(tx,ty,step+1);
            book[tx][ty]=0;
        }
    }
    return;
}

int main()
{
    int i,j,startx,starty;
    scanf("%d %d",&a[i][j]);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    scanf("%d %d %d %d",&startx,&starty,&p,&q);


    book[startx][starty]=1;
    dfs(startx,starty,0);
    printf("%d",min);

    return 0;
}
