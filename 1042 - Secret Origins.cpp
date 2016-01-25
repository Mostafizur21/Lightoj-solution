#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long test,N,i,result,lowerbit,leftbit,changebit,rightbit;
    cin>>test;
    for(i=1; i<=test; i++)
    {
        cin>>N;

        lowerbit = N & -N;

        leftbit = N + lowerbit;

        changebit = N ^ leftbit;

        rightbit = (changebit/lowerbit) >>2;

        printf("Case %lld: %lld\n",i,(leftbit | rightbit));
    }
    return 0;
}
