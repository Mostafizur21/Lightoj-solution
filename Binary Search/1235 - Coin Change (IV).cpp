#include<bits/stdc++.h>
#define ll long long

using namespace std;

vector<ll>v1,v2;

ll arr[20];

void makequery(ll ind,ll i,ll value)
{
    v1.push_back(value);

    if(i>=ind) return;

    makequery(ind,i+1,value+0);

    makequery(ind,i+1,value+arr[i]);

    makequery(ind,i+1,value+arr[i]*2);

}


void makequery1(ll ind,ll i,ll value)
{
    v2.push_back(value);

    if(i>=ind) return;

    makequery1(ind,i+1,value+0);

    makequery1(ind,i+1,value+arr[i]);

    makequery1(ind,i+1,value+arr[i]*2);

}


int main()
{

    ll n,k,test;

    scanf("%lld",&test);

    for(int t=1; t<=test; t++)
    {
        scanf("%lld %lld",&n,&k);

        for(int i= 0; i<n; i++)
            scanf("%lld",&arr[i]);

        v1.clear();

        v2.clear();

        makequery(n/2,0,0);

        makequery1(n,n/2,0);

        sort(v2.begin(),v2.end());

        ll len = v2.size();

        bool check = false;

        ll len2=v1.size();

        for(int i=0; i<len2; i++)
        {
            ll m = k-v1[i];

            if(m<0)
                continue;

            ll low=0,high=len-1,mid;

            while(low<high)
            {
                mid = low+(high-low)/2;

                if(m==v2[mid])
                {
                    check = true;
                    break;
                }

                if(m<v2[mid])
                    high = mid-1;

                else
                    low = mid+1;
            }

            if(v2[low]==m)
                check = true;

            if(check)
                break;
        }

        if(check)
            printf("Case %d: Yes\n",t);

        else
            printf("Case %d: No\n",t);

    }

    return 0;
}
