//����

#include<stdio.h>
int a[10001],n;     //ȫ�ֱ���

void quicksort(int left, int right)
{
    int i,j,t,temp;
    if(left>right)
        return;

    temp=a[left];
    i=left;
    j=right;
    while(i!=j)
    {
        while(a[j]>=temp && i<j)    //<= >= Ҫȫ��
            j--;
        while(a[i]<=temp && i<j)
            i++;
        if(i<j)     //if ��while���棬�ܼ򵥰� -> ÿ�˲�ֹһ������Ҫ������
        {
            t=a[i];a[i]=a[j];a[j]=t;
        }
    }

    a[left]=a[i];
    a[i]=temp;

    quicksort(left,i-1);
    quicksort(i+1,right);
    return;
}

int main()
{
    int i,j,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    quicksort(1,n);

    printf("%d ",a[1]);     //��i=1�ֳ���д
    for(i=2;i<=n;i++)
    {
        if(a[i]!=a[i-1])
            printf("%d ",a[i]);
    }
    getchar();getchar();
    return 0;
}


