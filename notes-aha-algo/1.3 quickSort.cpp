//quickSort
#include<stdio.h>
int a[101],n;

void quicksort(int left, int right)
{
    int i,j,t,temp;
    if(left>right)      //if ���治��Ҫ�ֺţ����жϴ�������Ƿ�ϸ�
        return;

    temp=a[left];       //�趨��׼ֵ
    i=left;     //left,right �ǹ̶�ֵ���Һ���ݹ�����ʹ�ã�����Ҫ����ʱ����i,j
    j=right;
    while(i!=j)     //��������Ϊi!=j��������i<j����Ϊ��while�ڲ�ѭ���л�����while��������ֳ�ͻ
    {
        while(a[j]>=temp && i<j)
            j--;
        while(a[i]<=temp && i<j)
            i++;
        if(i<j)
        {
            t=a[i];a[i]=a[j];a[j]=t;    //������ʱ�� t-i-i-j-j-t,��һ��ѭ��
        }
    }

    //����׼����λ��Ҳ���ǽ�����׼�����м�����λ��
    a[left]=a[i];   //���м�λ�õ�ֵ��������ߵ�ԭ��׼��
    a[i]=temp;      //��ԭ��׼�������м�λ��

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
