//queue struct

//´æÒÉ

#include<stdio.h>
struct queue
{
    int data[1000];
    int head;
    int tail;
};

int main()
{
    struct queue q;
    int i;
    q.head=1;
    q.tail=3;
    for(i=1;i<=3;i++)
    {
        scanf("%d",&q.data[q.tail]);
        q.tail++;
    }
    while(q.head<q.tail)
    {
        printf("%d ",q.data[q.head]);
        q.head++;
        q.data[q.tail]=q.data[q.head];
        q.tail++;
        q.head++;
    }
    return 0;
}
