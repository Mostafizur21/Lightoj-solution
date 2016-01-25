#include<bits/stdc++.h>

using namespace std;

int dp[105][105];

string s;

int solve(int x,int y)
{
    if(x>=y)
        return 0;

    if(dp[x][y]!=-1)
        return dp[x][y];

    if(s[x]==s[y])
        dp[x][y] = solve(x+1,y-1);

    else
        dp[x][y]=  min(solve(x+1,y),solve(x,y-1))+1;

    return dp[x][y];

}

int main()
{
    int test;

    cin>>test;

    for(int i=1; i<=test; i++)
    {

        memset(dp,-1,sizeof dp);

        cin>>s;

        int len = s.size();

        cout<<"Case "<<i<<": "<<solve(0,len-1)<<endl;

    }

    return 0;
}
