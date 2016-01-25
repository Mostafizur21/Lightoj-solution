#include<bits/stdc++.h>
#define eps 1e-12

using namespace std;

int main()
{

    int test;

    double a,b,c,rati,DE,AE,low,mid,high,s,d;

    cin>>test;

    for(int i=1; i<=test; i++)
    {

        cin>>c>>b>>a>>rati;

        s = a+b+c;

        s/=2.0;

        double ABC = sqrt(s*(s-a)*(s-b)*(s-c));

        low = 0.0;

        high = c;

        while(low+eps<high)
        {

            mid = (low+high)/2.0;

            d = mid/c;

            AE = d*b;

            DE = d*a;

            s = mid+DE+AE;

            s/=2.0;

            double ADE = sqrt(s*(s-mid)*(s-DE)*(s-AE));

            double BCDE = ABC-ADE;

            double temp = ADE/BCDE;

            if(temp<rati)
                low = mid;

            else
                high =mid;

        }

        printf("Case %d: %.10lf\n",i,low);

    }

    return 0;
}
