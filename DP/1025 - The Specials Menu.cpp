#include<bits/stdc++.h>

using namespace std;

long long dp[61][61],len;

string str;

long long solve(int i,int j)
{
    if(i==j)
        return 1;

    if(i>j)
        return 0;

    if(i>=len||j<0)
        return 0;

    if(dp[i][j]!=-1)
        return dp[i][j];

    if(str[i]==str[j])
        return dp[i][j]=(1+solve(i+1,j-1))+(solve(i,j-1)+solve(i+1,j)-solve(i+1,j-1));

    else
        return dp[i][j] = solve(i,j-1)+solve(i+1,j)-solve(i+1,j-1);
}

int main()
{

    int test;

    cin>>test;

    for(int t=1; t<=test; t++)
    {
        cin>>str;

        len = str.size();

        memset(dp,-1,sizeof dp);

        printf("Case %d: %lld\n",t,solve(0,len-1));

    }

    return 0;

}
