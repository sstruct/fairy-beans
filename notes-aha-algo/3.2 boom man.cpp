//枚举 之 最佳炸弹人
//暂时无法运行通过

#include<stdio.h>

int main()
{
    char a[20][21];
    int i,j,sum,map=0,p,q,x,y,n,m;
    scanf("%d %d",&n,&m);

    for(i=0;i<=n-1;i++)
        scanf("%s",a[i]);

//    for(i=0;i<=n-1;i++)
//        printf("%s\n",a[i]);

    for(i=0;i<=n-1;i++)
    {
        for(j=0;j<=m-1;j++)
        {
            if(a[i][j]=='.')
            {
                sum=0;
                x=i;y=j;
                while(a[x][y]!='#')
                {
                    if(a[x][y]=='G')
                        sum++;
                    x--;
                }

                x=i;y=j;
                while(a[x][y]!='#')
                {
                    if(a[x][y]=='G')
                        sum++;
                    x++;
                }

                x=i;y=j;
                while(a[x][y]!='#')
                {
                    if(a[x][y]=='G')
                        sum++;
                    y--;
                }
                x=i;y=j;
                while(a[x][y]!='#')
                {
                    if(a[x][y]=='G')
                        sum++;
                    y++;
                }

                if(sum>map)
                {
                    map=sum;
                    p=i;
                    q=j;
                }
            }
        }
    }
    printf("%d %d %d\n",p,q,map);
    getchar();getchar();
    return 0;

}
