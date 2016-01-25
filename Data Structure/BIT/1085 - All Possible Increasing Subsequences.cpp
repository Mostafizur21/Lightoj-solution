#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

ll tree[100001],n;

ll query(ll idx)
{
    ll sum = 0;

    while(idx>0)
    {
        sum+=tree[idx];

        if(sum>mod)
        {
            ll temp = sum/mod;

            sum-=temp*mod;
        }

        idx-=idx&(-idx);
    }

    return sum;

}


ll update(ll idx,ll x)
{

    while(idx<=n)
    {

        tree[idx]+=x;

        if(tree[idx]>mod)
        {
            ll temp = tree[idx]/mod;

            tree[idx]-=temp*mod;
        }

        idx+=idx&(-idx);

    }

}


int main()
{
    ll q,arr[100001],ind;

    int T;

    map<ll,ll>mp;

    map<ll,ll>::iterator it;

    scanf("%d",&T);

    for(int a=1; a<=T; a++)
    {
        mp.clear();

        memset(tree,0,sizeof(tree));

        ind = 1;

        scanf("%lld",&n);

        for(int i=0; i<n; i++)
        {
            scanf("%lld",&arr[i]);

            mp[arr[i]];

        }

        for(it=mp.begin(); it!=mp.end(); it++)
            it->second = ind++;

        ll sum=0,tot,pos;

        for(int k=1; k<=n; k++)
        {

            pos = mp[arr[k-1]];

            tot = query(pos-1)+1;

            update(pos,tot);

            sum+=tot;

            if(sum>mod)
            {
                ll temp = sum/mod;

                sum-=temp*mod;
            }

        }

        printf("Case %d: %lld\n",a,sum);

    }

    return 0;

}

