//�����������

#include<stdio.h>
int a[10],book[10],n;

void dfs(int step)
{
    int i;
    if(step==n+1)       //վ�ڵ�n+1������ǰ������ǰn�������Ѿ��ź�����
    {
        for(i=1;i<=n;i++)
            printf("%d",a[i]);
        printf("\n");
        return;         //����֮ǰ��һ���������һ�ε���dfs�����ĵط� ������
    }
    for(i=1;i<=n;i++)
    {
        if(book[i]==0)      //�ж����Ƿ��Ѿ���ʹ��
        {
            a[step]=i;      //���Ʒŵ�������
            book[i]=1;      //����ʹ�ñ��
            dfs(step+1);        //�ݹ鵽��һ������
            book[i]=0;      //���ղų��Ե����ջ�
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
