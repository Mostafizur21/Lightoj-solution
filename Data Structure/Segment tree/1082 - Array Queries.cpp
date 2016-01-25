#include <bits/stdc++.h>
#define mx 100005

using namespace std;

int arr[mx];

int tree[mx*3];

void build_tree(int node,int b,int e)
{

    if(b==e)
    {
        tree[node] = arr[b];
        return;
    }

    int left = node*2;

    int right = node*2+1;

    int mid = (b+e)/2;

    build_tree(left,b,mid);

    build_tree(right,mid+1,e);

    tree[node] = min(tree[left],tree[right]);

}

int query(int node,int b,int e ,int i,int j)
{
    if(i>e||j<b)

        return mx;

    if(b>=i&&e<=j)
    {

        return tree[node];

    }

    int left = node*2;

    int right = node*2+1;

    int mid = (b+e)/2;

    int p1 = query(left,b,mid,i,j);

    int p2 = query(right,mid+1,e,i,j);

    return (min(p1,p2));


}

/*void update(int node,int b,int e,int i,int newvalue)
{

    if(i>e||i<b)

        return;

    if(b>=i&&e<=i)
    {
        tree[node]  =newvalue;

        return;

    }

    int left = node*2;

    int right = node*2+1;

    int mid = (b+e)/2;

    update(left,b,mid,i,newvalue);

    update(right,mid+1,e,i,newvalue);

    tree[node] = tree[left]+tree[right];

}*/

int main()
{
    int n,test,q,i,j;

    scanf("%d",&test);

    for(int a = 1; a<=test; a++)
    {

        scanf("%d %d",&n,&q);

        for(int x=1; x<=n; x++)

            scanf("%d",&arr[x]);

        build_tree(1,1,n);


        printf("Case %d:\n",a);

        for(int b=1; b<=q; b++)
        {

            scanf("%d %d",&i,&j);

            printf("%d\n",query(1,1,n,i,j));

        }

    }

    return 0;
}
