#include<iostream>
#include<sstream>
#include<vector>
#include<string>
#include<utility>
#include<complex>
#include<stack>
#include<map>
#include<queue>
#include<algorithm>
#include<set>
#include<deque>
#include<list>
#include<stdexcept>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<ctime>

using namespace std;

int main()
{
    int T;
    long long Q,first,last,middle;
    scanf("%d",&T);
    for(int i=1; i<=T; i++)
    {
        scanf("%lld",&Q);

        first = Q*4;

        last = Q*5;

        long long temp;

        while(first<last)
        {
            middle = first+(last-first)/2;

            //cout<<first<<" "<<last<<endl;

            temp = 0;

            for(int j=5; j<=middle; j*=5)
            {
                temp+=middle/j;
            }

            if(temp<Q)
                first = middle+1;

            else
                last = middle;
        }

        temp = 0;

        for(int j=5; j<=first; j*=5)
            temp+=first/j;

        if(temp == Q)

            printf("Case %d: %lld\n",i,first);

        else

            printf("Case %d: impossible\n",i);
    }
    return 0;
}
