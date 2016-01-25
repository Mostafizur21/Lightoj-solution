#include<bits/stdc++.h>

using namespace std;

int dp[51][51][51],len1,len2,len3;

string s1,s2,s3;

int solve(int x,int y,int z)
{

    if(x==len1||y==len2||z==len3)
        return 0;

    if(dp[x][y][z]!=-1)
        return dp[x][y][z];

    if(s1[x]==s2[y]&&s2[y]==s3[z])
    {
        return dp[x][y][z]=1+solve(x+1,y+1,z+1);
    }

    else
        return dp[x][y][z]=max(solve(x,y+1,z),max(solve(x,y,z+1),max(solve(x,y+1,z+1),max(solve(x+1,y,z),max(solve(x+1,y,z+1),solve(x+1,y+1,z))))));
}

int main()
{

    int test;

    cin>>test;

    for(int t=1; t<=test; t++)
    {
        cin>>s1;
        cin>>s2;
        cin>>s3;

        memset(dp,-1,sizeof dp);

        len1 = s1.size();
        len2 = s2.size();
        len3 = s3.size();

        printf("Case %d: %d\n",t,solve(0,0,0));

    }

    return 0;
}
