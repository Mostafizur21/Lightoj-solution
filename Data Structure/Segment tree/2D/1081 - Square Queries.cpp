#include <bits/stdc++.h>
#define mx 505

using namespace std;

int arr[mx][mx],tree[mx*3][mx*3],N,R1,R2,C1,C2,val[mx];


void build_tree_of_node(int prev_node,int curr_node,int b,int e)
{
    if(b==e)
    {
        tree[prev_node][curr_node] = val[b];
        return;
    }

    int left = curr_node*2;

    int right = curr_node*2+1;

    int mid = (b+e)/2;

    build_tree_of_node(prev_node,curr_node*2,b,mid);

    build_tree_of_node(prev_node,curr_node*2+1,mid+1,e);

    tree[prev_node][curr_node] = max(tree[prev_node][left],tree[prev_node][right]);

}


void build_tree(int node,int b,int e)
{

    for(int i=1; i<=N; i++)
    {
        val[i] = arr[i][b];

        for(int j=b; j<=e; j++)
            val[i] = max(val[i],arr[i][j]);
    }

    build_tree_of_node(node,1,1,N);

    if(b==e) return;

    int mid = (b+e)/2;

    build_tree(node*2,b,mid);

    build_tree(node*2+1,mid+1,e);

}


int again_query(int prev_node,int curr_node,int b,int e)
{
    if(R1>e||R2<b) return 0;

    if(b>=R1&&e<=R2)
        return tree[prev_node][curr_node];

    int mid = (b+e)/2;

    return max(again_query(prev_node,curr_node*2,b,mid),again_query(prev_node,curr_node*2+1,mid+1,e));

}


int query(int node,int b,int e)
{
    if(C1>e||C2<b) return 0;

    if(b>=C1&&e<=C2)
        return again_query(node,1,1,N);

    int mid = (b+e)/2;

    return max(query(node*2,b,mid),query(node*2+1,mid+1,e));

}


int main()
{
    int test,Q,S;

    scanf("%d",&test);

    for(int a = 1; a<=test; a++)
    {

        scanf("%d %d",&N,&Q);

        for(int i=1; i<=N; i++)
        {
            for(int j=1; j<=N; j++)
                scanf("%d",&arr[i][j]);
        }

        build_tree(1,1,N);

        printf("Case %d:\n",a);

        while(Q--)
        {

            scanf("%d %d %d",&R1,&C1,&S);

            R2 = R1+S-1;

            C2 = C1+S-1;

            printf("%d\n",query(1,1,N));

        }

    }

    return 0;

}
