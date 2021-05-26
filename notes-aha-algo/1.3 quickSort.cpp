//quickSort
#include<stdio.h>
int a[101],n;

void quicksort(int left, int right)
{
    int i,j,t,temp;
    if(left>right)      //if 后面不需要分号；先判断传入参数是否合格
        return;

    temp=a[left];       //设定基准值
    i=left;     //left,right 是固定值，且后面递归仍需使用，所以要设临时变量i,j
    j=right;
    while(i!=j)     //条件设置为i!=j，不能是i<j，因为在while内部循环中还存在while，将会出现冲突
    {
        while(a[j]>=temp && i<j)
            j--;
        while(a[i]<=temp && i<j)
            i++;
        if(i<j)
        {
            t=a[i];a[i]=a[j];a[j]=t;    //交换的时候 t-i-i-j-j-t,是一个循环
        }
    }

    //将基准数归位，也就是交换基准数和中间数的位置
    a[left]=a[i];   //把中间位置的值赋到最左边的原基准数
    a[i]=temp;      //把原基准数赋到中间位置

    quicksort(left,i-1);
    quicksort(i+1,right);
    return;
}

int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);

    quicksort(1,n);

    for(i=1;i<=n;i++)
        printf("%d ",a[i]);

    getchar();getchar();
    return 0;
}
