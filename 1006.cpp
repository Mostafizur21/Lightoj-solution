#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>

using namespace std;

long long int a, b, c, d, e, f,dp[10000+100];

int fn( long long int n )
 {
    if( n == 0 ){ return (a % 10000007);}
    if( n == 1 ) {return (b % 10000007);}
    if( n == 2 ) {return (c % 10000007);}
    if( n == 3 ) {return (d % 10000007);}
    if( n == 4 ) {return (e % 10000007);}
    if( n == 5 ){ return (f % 10000007);}
    if(dp[n]!=-1) return dp[n];
    else
    {
        dp[n] = ( fn(n-1) + fn(n-2) + fn(n-3) + fn(n-4) + fn(n-5) + fn(n-6) ) % 10000007;
        return dp[n];
    }
}
int main()
{
    long long int n, caseno = 0, cases;
    cin>>cases;
    while( cases-- )
    {
        memset(dp,-1,sizeof(dp));
        cin>>a>>b>>c>>d>>e>>f>>n;
        cout<<"Case "<<++caseno<<": "<<fn(n)<<endl;
    }
    return 0;
}
