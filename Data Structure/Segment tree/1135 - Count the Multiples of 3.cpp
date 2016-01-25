#include<bits/stdc++.h>
#define mx 100005

using namespace std;

struct info
{
    int prop,zero,one,two;
} tree[mx*3];

void make(int node,int st,int ed)
{
    if(st==ed)
    {
        tree[node].zero = 1;
        tree[node].one = tree[node].two = tree[node].prop=0;
        return;
    }
    int mid = (st+ed)/2;
    make(2*node,st,mid);
    make(2*node+1,mid+1,ed);
    tree[node].zero = tree[2*node].zero+tree[2*node+1].zero;
    tree[node].one = tree[2*node].one+tree[2*node+1].one;
    tree[node].two = tree[2*node].two+tree[2*node+1].two;
}

void update(int node,int st,int ed,int i,int j)
{
    if(i>ed||j<st) return;
    if(st>=i&&ed<=j)
    {
        tree[node].prop++;
        swap(tree[node].zero,tree[node].one);
        swap(tree[node].zero,tree[node].two);
        return;
    }
    int mid = (st+ed)/2;
    update(2*node,st,mid,i,j);
    update(2*node+1,mid+1,ed,i,j);
    tree[node].zero = tree[2*node].zero+tree[2*node+1].zero;
    tree[node].one = tree[2*node].one+tree[2*node+1].one;
    tree[node].two = tree[2*node].two+tree[2*node+1].two;
    if(tree[node].prop%3==1)
    {
        swap(tree[node].zero,tree[node].one);
        swap(tree[node].zero,tree[node].two);
    }
    else if(tree[node].prop%3==2)
    {
        swap(tree[node].zero,tree[node].two);
        swap(tree[node].zero,tree[node].one);
    }
}

int query(int node,int st,int ed,int i,int j,int flag)
{
    if(i>ed||j<st) return 0;
    if(st>=i&&ed<=j)
    {
        if(flag%3==0) return tree[node].zero;
        else if(flag%3==1) return tree[node].two;
        else if(flag%3==2) return tree[node].one;
    }
    int mid = (st+ed)/2;
    return query(node*2,st,mid,i,j,flag+tree[node].prop)+query(node*2+1,mid+1,ed,i,j,flag+tree[node].prop);
}

int main()
{

    int T,N,q,i,j,v,check;

    scanf("%d",&T);

    for(int ii=1; ii<=T; ii++)
    {
        cout<<"Case "<<ii<<":"<<endl;

        scanf("%d %d",&N,&q);

        memset(tree,0,sizeof tree);

        make(1,0,N-1);

        while(q--)
        {
            scanf("%d",&check);

            if(check==0)
            {
                scanf("%d %d",&i,&j);

                update(1,0,N-1,i,j);

            }

            else
            {
                scanf("%d %d",&i,&j);

                int sum = query(1,0,N-1,i,j,0);

                printf("%d\n",sum);

            }

        }

    }

    return 0;

}
