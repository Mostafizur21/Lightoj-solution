#include <bits/stdc++.h>
#define pi 2*acos(0.0)

using namespace std;

int main()
{

    int test;

    double redious;

    cin>>test;

    for(int i=1;i<=test;i++)
    {

        cin>>redious;

        printf("Case %d: %.2lf\n",i,((4*redious*redious)-(pi*redious*redious)));

    }

    return 0;

}
