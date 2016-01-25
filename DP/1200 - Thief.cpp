#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#define MAX_N 101
#define MAX_W 10005

using namespace std;

int n;

int dp[MAX_N+1][MAX_W+1];

int weight[MAX_N+1];

int cost[MAX_N+1];
int need[MAX_N+1];

int CAP;

int func(int i,int w)
{
    if(i==n+1)
        return 0;

    if(dp[i][w]!=-1)
        return dp[i][w];

    int profit1=0,profit2=0;

    if(w+weight[i]<=CAP)
        profit1=cost[i]+func(i,w+weight[i]);

    profit2=func(i+1,w);

    dp[i][w]=max(profit1,profit2);

    return dp[i][w];
}

int main()
{
    int test,sum,x,y,tot;

    scanf("%d",&test);

    for(int m=1; m<=test; m++)
    {
        tot=0;

        scanf("%d %d",&n,&CAP);

        for(int i=1; i<=n; i++)
        {
            scanf("%d %d %d",&cost[i],&need[i],&weight[i]);
            tot+=need[i]*weight[i];
        }

        if(tot>CAP)
            printf("Case %d: Impossible\n",m);
        else
        {
            CAP-=tot;

            memset(dp,-1,sizeof(dp));

            printf("Case %d: %d\n",m,func(1,0));

        }

    }

    return 0;

}
