//枚举法 -- 有序的尝试所有可能

//枚举法 -- 有序的尝试所有可能

#include<stdio.h>

int main()
{
    int a[10],i,total=0,book[10],sum;
    for(a[1]=1;a[1]<=9;a[1]++)
        for(a[2]=1;a[2]<=9;a[2]++)
            for(a[3]=1;a[3]<=9;a[3]++)
                for(a[4]=1;a[4]<=9;a[4]++)
                    for(a[5]=1;a[5]<=9;a[5]++)
                        for(a[6]=1;a[6]<=9;a[6]++)
                            for(a[7]=1;a[7]<=9;a[7]++)
                                for(a[8]=1;a[8]<=9;a[8]++)
                                    for(a[9]=1;a[9]<=9;a[9]++)
                                    {
                                        for(i=1;i<=9;i++)       //初始化book数组
                                            book[i]=0;
                                        for(i=1;i<=9;i++)       //如果出现某个数字就标记为1
                                            book[a[i]]=1;

                                        sum=0;
                                        for(i=1;i<=9;i++)       //统计出现了多少个不同的数
                                            sum+=book[i];
                                        if(sum==9 && a[1]*100+a[2]*10+a[3]+a[4]*100+a[5]*10+a[6] == a[7]*100+a[8]*10+a[9])
                                        {
                                            total++;
                                            printf("%d%d%d%d%d%d%d%d%d\n",a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],a[9]);
                                        }
                                    }

    printf("%d",total/2);       //左边两个加数可互换
    getchar();getchar();
    return 0;
}


