#include <bits/stdc++.h>
#define mx 100005

using namespace std;

int arr[mx];

int min_tree[mx*3],max_tree[mx*3];

void min_build_tree(int node,int b,int e)
{

    if(b==e)
    {
        min_tree[node] = arr[b];
        return;
    }

    int left = node*2;

    int right = node*2+1;

    int mid = (b+e)/2;

    min_build_tree(left,b,mid);

    min_build_tree(right,mid+1,e);

    min_tree[node] = min(min_tree[left],min_tree[right]);

}

int min_query(int node,int b,int e ,int i,int j)
{
    if(i>e||j<b)

        return mx;

    if(b>=i&&e<=j)
    {

        return min_tree[node];

    }

    int left = node*2;

    int right = node*2+1;

    int mid = (b+e)/2;

    int p1 = min_query(left,b,mid,i,j);

    int p2 = min_query(right,mid+1,e,i,j);

    return (min(p1,p2));

}


void max_build_tree(int node,int b,int e)
{

    if(b==e)
    {
        max_tree[node] = arr[b];
        return;
    }

    int left = node*2;

    int right = node*2+1;

    int mid = (b+e)/2;

    max_build_tree(left,b,mid);

    max_build_tree(right,mid+1,e);

    max_tree[node] = max(max_tree[left],max_tree[right]);

}


int max_query(int node,int b,int e ,int i,int j)
{
    if(i>e||j<b)

        return 0;

    if(b>=i&&e<=j)
    {

        return max_tree[node];

    }

    int left = node*2;

    int right = node*2+1;

    int mid = (b+e)/2;

    int p1 = max_query(left,b,mid,i,j);

    int p2 = max_query(right,mid+1,e,i,j);

    return (max(p1,p2));

}

int main()
{
    int n,test,d;

    scanf("%d",&test);

    for(int a = 1; a<=test; a++)
    {

        scanf("%d %d",&n,&d);

        for(int x=1; x<=n; x++)

            scanf("%d",&arr[x]);

        min_build_tree(1,1,n);

        max_build_tree(1,1,n);

        int diff = 0,temp;

        for(int b=1; b<=n&&d<=n; b++)
        {

            temp = max_query(1,1,n,b,d)-min_query(1,1,n,b,d);

            d++;

            if(temp>diff)
                diff = temp;

        }

        printf("Case %d: %d\n",a,diff);

    }

    return 0;
}
