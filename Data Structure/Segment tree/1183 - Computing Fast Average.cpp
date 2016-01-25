#include<bits/stdc++.h>
#define mx 100005
#define ll long long

using namespace std;

struct info
{
    ll prop,sum;
} tree[mx*3];


void pushdown(int node,int from,int to)
{
    if(tree[node].prop!=-1)
    {
        ll mid = (from+to)/2;

        tree[2*node].sum = (mid-from+1)*tree[node].prop;

        tree[2*node+1].sum = (to-mid)*tree[node].prop;

        tree[2*node].prop = tree[node].prop;

        tree[2*node+1].prop = tree[node].prop;

        tree[node].prop = -1;

    }
}


void pushup(int node)
{
    tree[node].sum = tree[2*node].sum+tree[2*node+1].sum;
}


void update(ll node,ll b,ll e,ll i,ll j,ll x)
{
    if(i>e||j<b)
        return;

    if(b>=i&&e<=j)
    {
        tree[node].sum = (e-b+1)*x;
        tree[node].prop = x;
        return;
    }

    pushdown(node,b,e);

    ll mid = (b+e)/2;

    update(2*node,b,mid,i,j,x);

    update(2*node+1,mid+1,e,i,j,x);

    pushup(node);

}


ll query(ll node,ll b,ll e,ll i,ll j)
{

    if(i>e||j<b)
        return 0;

    if(b>=i&&e<=j)
        return tree[node].sum;

    pushdown(node,b,e);

    ll mid = (b+e)/2;

    ll p=0;

    p+= query(node*2,b,mid,i,j);

    p+=query(node*2+1,mid+1,e,i,j);

    pushup(node);

    return p;

}


int main()
{

    ll T,N,q,i,j,v,check;

    scanf("%lld",&T);

    for(int ii=1; ii<=T; ii++)
    {
        cout<<"Case "<<ii<<":"<<endl;

        for(int i=0; i<=mx*3; i++)
        {
            tree[i].sum = 0;
            tree[i].prop = -1;
        }

        scanf("%lld%lld",&N,&q);

        while(q--)
        {
            scanf("%lld",&check);

            if(check==1)
            {
                scanf("%lld%lld%lld",&i,&j,&v);

                update(1,0,N-1,i,j,v);

            }

            else
            {
                scanf("%lld%lld",&i,&j);

                ll sum = query(1,0,N-1,i,j);

                ll range = j-i+1;

                ll GCD = __gcd(range,sum);

                sum/=GCD;

                range/=GCD;

                if(range==1)
                    printf("%lld\n",sum);

                else if(sum)
                    printf("%lld/%lld\n",sum,range);

                else
                    printf("0\n");

            }

        }

    }

    return 0;

}
