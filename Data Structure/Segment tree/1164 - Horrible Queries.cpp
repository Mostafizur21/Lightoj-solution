#include<bits/stdc++.h>
#define mx 100005

using namespace std;

struct info
{
    long long prop,sum;
} tree[mx*4];


void update(long long node,long long b,long long e,long long i,long long j,long long x)
{
    if(i>e||j<b)
        return;

    if(b>=i&&e<=j)
    {
        tree[node].sum+=(e-b+1)*x;
        tree[node].prop += x;
        return;
    }

    long long left = node*2;

    long long right = node*2+1;

    long long mid = (b+e)/2;

    update(left,b,mid,i,j,x);

    update(right,mid+1,e,i,j,x);

    tree[node].sum=tree[left].sum+tree[right].sum+(e-b+1)*tree[node].prop;
}

long long query(long long node,long long b,long long e,long long i,long long j,long long carry=0)
{
    if(i>e||j<b)
        return 0;

    if(b>=i&&e<=j)

        return tree[node].sum+carry*(e-b+1);

    long long left = node*2;

    long long right = node*2+1;

    long long mid = (b+e)/2;

    long long p1 = query(left,b,mid,i,j,carry+tree[node].prop);

    long long p2=query(right,mid+1,e,i,j,carry+tree[node].prop);

    return p1+p2;
}



int main()
{
    long long T,N,C,p,q,v,check;

    scanf("%lld",&T);

    for(int ii=1; ii<=T; ii++)
    {
        cout<<"Case "<<ii<<":"<<endl;

        memset(tree,0,sizeof tree);

        scanf("%lld%lld",&N,&C);

        while(C--)
        {
            scanf("%lld",&check);

            if(!check)
            {
                scanf("%lld%lld%lld",&p,&q,&v);

                update(1,0,N-1,p,q,v);
            }

            else
            {
                scanf("%lld%lld",&p,&q);

                printf("%lld\n",query(1,0,N-1,p,q));
            }
        }
    }

    return 0;
}

