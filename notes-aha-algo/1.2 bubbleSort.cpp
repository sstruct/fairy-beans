//bubbleSort with Name
#include<stdio.h>

int main()
{
    int a[10001],i,j,t,n;
    scanf("%d",&n);

    for(i=1;i<=n-1;i++)   //i<=n-1，不是固定值了，也不是n
        scanf("%d",&a[i]);

    for(i=1;i<=n;i++)   //同上
        for(j=1;j<=i-1;j++)
        {
            if(a[j]<a[j+1])
            {
                t=a[j];a[j]=a[j+1];a[j+1]=t;
            }
        }

    for(i=1;i<=n;i++)
        printf("%d ",a[i]);
    getchar();getchar();
    return 0;
}
