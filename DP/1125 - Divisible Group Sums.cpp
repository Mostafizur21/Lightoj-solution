#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll dp[201][11][20];

int M,N,D,arr[201];

ll solve(int pos,int tot,int remainder)
{

    if(tot==M)
        return ((remainder)?0:1);

    if(pos>=N)
        return 0;

    ll &res=dp[pos][tot][remainder];

    if(res!=-1)
        return res;

    res=0;

    res+=solve(pos+1,tot+1,((remainder+arr[pos])%D+D)%D);
    res+=solve(pos+1,tot,remainder);

    return res;

}

int main()
{

    int test,Q;

    scanf("%d",&test);

    for(int t=1; t<=test; t++)
    {

        scanf("%d %d",&N,&Q);

        for(int i=0; i<N; i++)
            scanf("%d",&arr[i]);

        printf("Case %d:\n",t);

        while(Q--)
        {

            scanf("%d %d",&D,&M);

            memset(dp,-1,sizeof dp);

            printf("%lld\n",solve(0,0,0));
        }

    }

    return 0;
}
