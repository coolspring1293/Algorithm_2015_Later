//
//  main.cpp
//  DP.记忆化搜索状态压缩
//
//  Created by Kieran Will on 12/25/15.
//  Copyright © 2015 Kieran Will. All rights reserved.
//

/**记忆化搜索+状态DP**/
#include <iostream>
#include<cstdio>
#include<cstring>

using namespace std;
#define maxn 1051001
#define inf 0x7fffffff

int n;
int a[22];
int sum[maxn];
int dp[maxn];

int read()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    memset(dp,-1,sizeof(dp));//便于区分哪个状态未进行处理
    dp[0]=0;//根据题目,当没有怪物时,消耗为0
    return 1;
}


int DFS(int s)//根据状态进行搜索,状态用2进制表示,某一位上为1,说明对应的阳台有怪物
{
    if(dp[s]!=-1)
        return dp[s];
    dp[s]=inf;
    for(int i=0;i<n;i++)
    {
        if(s&(1<<i))//若i位置有怪物,就以i为射击中点,枚举i
        {
            int tmp=s;
            tmp&=~(1<<((i-1+n)%n));//一枪射掉连续的三个阳台 , 这是去掉第一个
            tmp&=~(1<<i);   //这是第二个
            tmp&=~(1<<((i+1)%n));//这是第三个
            int res=0;
            for(int j=0;j<n;j++)
                if(tmp&(1<<j))//将剩余位置的怪物数量加起来,就是消耗的血量
                    res+=a[j];
            dp[s]=min(dp[s],res+DFS(tmp));//dp取枚举之后的最小值
        }
    }
    return dp[s];
}

void print()
{
    printf("%d\n",DFS((1<<n)-1));
}

int main()
{
    read();
    print();
    return 0;
}