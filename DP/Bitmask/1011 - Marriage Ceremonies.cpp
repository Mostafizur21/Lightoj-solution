#include<bits/stdc++.h>

using namespace std;

int Set(int N,int pos)
{
    return N=N|(1<<pos);
}

int reset(int N,int pos)
{
    return N=N|~(1<<pos);
}

bool check(int N,int pos)
{
    return (bool)(N&(1<<pos));
}

int arr[17][17],n;

int dp[17][1<<16+1];

bool visit[17][1<<16+1];


int solve(int row,int mask)
{
    if(mask==(1<<n)-1)
        return 0;

    if(row>n)
        return 0;

    if(visit[row][mask])
        return dp[row][mask];

    visit[row][mask]=true;

    int maxi=0;

    for(int i=1; i<=n; i++)
    {
        if(check(mask,i-1)==0)
        {
            int res=arr[row][i]+solve(row+1,Set(mask,i-1));
            maxi = max(maxi,res);
        }

    }

    return dp[row][mask] = maxi;
}


int main()
{
    int test;

    scanf("%d",&test);

    for(int t=1; t<=test; t++)
    {
        memset(visit,false,sizeof visit);

        scanf("%d",&n);

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
                scanf("%d",&arr[i][j]);
        }

        printf("Case %d: %d\n",t,solve(1,0));

    }

    return 0;
}
