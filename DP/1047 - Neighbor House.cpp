#include<bits/stdc++.h>

using namespace std;

int main()
{

    int test,R,G,B,dp[22][3],n;

    cin>>test;

    for(int t=1;t<=test;t++)
    {
        cin>>n;

        dp[0][0]=dp[0][1]=dp[0][2]=0;

        for(int i=1;i<=n;i++)
        {
            cin>>R>>G>>B;

            dp[i][0]=min(dp[i-1][1],dp[i-1][2])+R;
            dp[i][1]=min(dp[i-1][0],dp[i-1][2])+G;
            dp[i][2]=min(dp[i-1][1],dp[i-1][0])+B;


        }

        printf("Case %d: %d\n",t,min(dp[n][0],min(dp[n][1],dp[n][2])));

    }

    return 0;
}
