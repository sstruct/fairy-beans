//bubbleSort with Name
#include<stdio.h>

struct student
{
    char name[21];
    int score;
};

int main()
{
    struct student a[100],t;
    int i,j,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%s %d",a[i].name,&a[i].score);

    for(i=1;i<=n-1;i++)   //比较第i趟，共需要比较n趟
        for(j=1;j<=n-i;j++)     //每趟比较n-i次
            if(a[j].score<a[j+1].score)
            {
                t=a[j];a[j]=a[j+1];a[j+1]=t;    //交换结构体整体，而不是只交换分数
            }

    for(i=1;i<=n;i++)
        printf("%s %d\n",a[i].name,a[i].score);

    getchar();getchar();
    return 0;
}
