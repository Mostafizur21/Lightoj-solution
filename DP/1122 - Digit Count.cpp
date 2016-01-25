#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll dp[11][11];

int m,n,arr[10];

ll solve(int pos,int prev_digit)
{

    //cout<<pos<<" "<<prev_digit<<endl;

    if(pos==n)
        return 1;

    if(dp[pos][prev_digit]!=-1)
        return dp[pos][prev_digit];

    ll res=0;

    for(int i=0; i<m; i++)
    {
        if(!prev_digit||abs(prev_digit-arr[i])<=2)
            res+=solve(pos+1,arr[i]);
    }

    return dp[pos][prev_digit]=res;

}

int main()
{

    int test;

    scanf("%d",&test);

    for(int t=1; t<=test; t++)
    {
        scanf("%d %d",&m,&n);

        for(int i=0; i<m; i++)
            scanf("%d",&arr[i]);

        memset(dp,-1,sizeof dp);

        printf("Case %d: %d\n",t,solve(0,0));

    }

    return 0;
}
