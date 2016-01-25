#include<bits/stdc++.h>
#define pp1 pair<int,pair<int,int> >
#define pp pair<int,int>
#define mx 100005

using namespace std;

struct info
{
    int sum;
} tree[mx*3];

void make(int node,int st,int ed)
{
    if(st==ed)
    {
        tree[node].sum = 1;
        return;
    }
    int mid = (st+ed)/2;
    make(2*node,st,mid);
    make(2*node+1,mid+1,ed);
    tree[node].sum = tree[2*node].sum+tree[2*node+1].sum;
}

void update(int node,int st,int ed,int i)
{
    if(i>ed||i<st) return;
    if(st==i&&ed==i)
    {
        tree[node].sum = 0;
        return;
    }
    int mid = (st+ed)/2;
    update(2*node,st,mid,i);
    update(2*node+1,mid+1,ed,i);
    tree[node].sum = tree[2*node].sum+tree[2*node+1].sum;
}

int query(int node,int st,int ed,int i,int j)
{
    if(i>ed||j<st) return 0;
    if(st>=i&&ed<=j)
        return tree[node].sum;
    int mid = (st+ed)/2;
    return query(node*2,st,mid,i,j)+query(node*2+1,mid+1,ed,i,j);
}

int arr[100005],prev[100005];

int main()
{
    int T,N,q,i,j,a,b;
    vector<pp1>v;
    vector<pp>result;
    scanf("%d",&T);
    for(int ii=1; ii<=T; ii++)
    {
        v.clear();
        result.clear();

        printf("Case %d:\n",ii);

        scanf("%d %d",&N,&q);

        for(int t=1; t<=N; t++)
        {
            scanf("%d",&arr[t]);
            prev[arr[t]]=0;
        }

        memset(tree,0,sizeof tree);

        make(1,1,N);

        for(int t=1; t<=q; t++)
        {
            scanf("%d %d",&a,&b);
            v.push_back(make_pair(b,make_pair(a,t)));
        }
        sort(v.begin(),v.end());

        int idx=0;

        for(int t=1; t<=N; t++)
        {
            //cout<<"T "<<t<<endl;
            if(prev[arr[t]])
            {
                update(1,1,N,prev[arr[t]]);
            }

            prev[arr[t]]=t;

            while(v[idx].first==t)
            {
                result.push_back(make_pair(v[idx].second.second,query(1,1,N,v[idx].second.first,v[idx].first)));
                idx++;
            }

        }

        sort(result.begin(),result.end());

        for(int i=0; i<q; i++)
            printf("%d\n",result[i].second);

    }

    return 0;

}
