#include<bits/stdc++.h>
#define ll long long

using namespace std;

vector<ll>v1,v2;

ll arr[35],mid,n;

void makequery(ll pos,ll sum)
{

    if(pos>mid)
    {
        v1.push_back(sum);

        return;
    }

    makequery(pos+1,sum+arr[pos]);

    makequery(pos+1,sum);

}


void makequery1(ll pos,ll sum)
{

    if(pos>n)
    {
        v2.push_back(sum);

        return;
    }

    makequery1(pos+1,sum+arr[pos]);

    makequery1(pos+1,sum);

}


int main()
{

    ll test,weight,total;

    scanf("%lld",&test);

    for(int t=1; t<=test; t++)
    {
        scanf("%lld %lld",&n,&weight);

        for(int i= 1; i<=n; i++)
            scanf("%lld",&arr[i]);

        v1.clear();

        v2.clear();

        total=0;

        mid = n/2;

        makequery(1,0);

        makequery1(mid+1,0);

        sort(v2.begin(),v2.end());

        for(int i=0;i<v1.size();i++)
            total+=upper_bound(v2.begin(),v2.end(),weight-v1[i])-v2.begin();

        /*ll len = v2.size();

        ll len2=v1.size();

        for(int i=0; i<len2; i++)
        {
            ll m = weight-v1[i];

            if(m<0)
                continue;

            ll low=0,high=len-1,mid;

            while(low<high)
            {
                mid = low+(high-low)/2;

                if(v2[mid]<m)
                    low = mid+1;

                else
                    high = mid;
            }

            while(v2[low]>m)
                low--;

            total+=low+1;
        }*/

        printf("Case %d: %lld\n",t,total);

    }

    return 0;

}
