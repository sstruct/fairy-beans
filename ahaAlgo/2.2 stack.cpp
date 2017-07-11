//栈
#include<stdio.h>
#include<string.h>

int main()
{
    char a[101],s[101];     //此处stack是char类型！
    int i,len,mid,next,top;

    gets(a);
    len=strlen(a);
    mid=len/2-1;        //mid是字符串的中点，为什么要减1？比如9个字符

    top=0;      //栈的初始化
    for(i=0;i<=mid;i++)
        s[++top]=a[i];

    if(len%2==0)
        next=mid+1;
    else
        next=mid+2;

    for(i=next;i<=len-1;i++)
    {
        if(a[i]!=s[top])        //a[i]表示从中点右侧开始
            break;
        top--;
    }

    if(top==0)
        printf("YES");
    else
        printf("NO");
    return 0;

}
