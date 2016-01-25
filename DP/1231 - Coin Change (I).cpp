#include<bits/stdc++.h>
#define mod 100000007

using namespace std;

int coin[51];

int times[51];

int n,K;

long long dp[51][1001];

/*int call(int i,int amount)
{
    if(i>=n)
    {
        if(amount==0)
            return 1;
        else
            return 0;
    }

    if(dp[i][amount]!=-1)
        return dp[i][amount];

    int ret1=0,ret2=0;

    for(int j=1; j<=times[i]; j++)
    {
        if(amount-j*coin[i]>=0)
            ret1=(ret1+call(i+1,amount-j*coin[i]))%mod;
    }



    ret2 = call(i+1,amount);

    return dp[i][amount] = (ret1+ret2)%mod;
}*/


int main()
{

    int T;

    cin>>T;

    for(int a=1; a<=T; a++)
    {
        memset(dp,0,sizeof(dp));

        cin>>n>>K;

        for(int j=1; j<=n; j++)
            cin>>coin[j];

        for(int j=1; j<=n; j++)
            cin>>times[j];

        for(int i=0; i<=n; i++)
            dp[i][0] = 1;

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=K; j++)
            {
                for(int k=0; k<=times[i]; k++)
                {
                    int temp = j-k*coin[i];

                    if(temp<0)
                        break;

                    dp[i][j]=(dp[i][j]+dp[i-1][temp])%mod;
                }
            }
        }

        //cout<<"Case "<<a<<": "<<call(0,K)<<endl;

        cout<<"Case "<<a<<": "<<dp[n][K]<<endl;
    }

    return 0;
}

