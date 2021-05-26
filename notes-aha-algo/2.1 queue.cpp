//╤сап

#include<stdio.h>

int main()
{
    int q[102]={0,6,5,3,2,1,5,4,5,9},head,tail;
    head=1;
    tail=10;

    while(head<tail)        //while, for 后面没有分号！
    {
        printf("%d ",q[head]);
        head++;

        q[tail]=q[head];
        tail++;
        head++;
    }
    getchar();getchar();
    return 0;
}


//#include<stdio.h>
//
//int main()
//{
//    int q[102]={0,6,5,3,2,1,5,4,5,9},head,tail;
//    head=1;
//    tail=10;
//
//    while(head<tail)
//    {
//        printf("%d ",q[head]);
//        head++;
//
//        q[tail]=q[head];
//        tail++;
//        head++;
//    }
//
//    getchar();getchar();
//    return 0;
//}
