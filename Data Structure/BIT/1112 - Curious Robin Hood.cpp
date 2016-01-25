#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int tree[100000+5];

int query(int idx)
{
    int sum = 0;
    while(idx>0)
    {
        sum+=tree[idx];
        idx-=idx&(-idx);
    }
    return sum;
}

int update(int idx,int x,int n)
{
    while(idx<=n)
    {
        tree[idx]+=x;
        idx+=idx&(-idx);
    }
}

int main()
{
    int T,n,q,arr[100000+5],i,j,v,check;

    scanf("%d",&T);

    for(int a=1; a<=T; a++)
    {
        memset(tree,0,sizeof(tree));

        printf("Case %d:\n",a);

        scanf("%d %d",&n,&q);

        for(int k=1; k<=n; k++)
        {
            scanf("%d",&arr[k]);
            update(k,arr[k],n);
        }

        for(int b=1; b<=q; b++)
        {
            scanf("%d",&check);

            if(check==1)
            {
                scanf("%d",&i);

                printf("%d\n",arr[i+1]);

                update(i+1,-arr[i+1],n);

                arr[i+1]=0;
            }

            else if(check==2)
            {
                scanf("%d%d",&i,&v);

                arr[i+1]+=v;

                update(i+1,v,n);
            }


            else
            {
                scanf("%d%d",&i,&j);

                int upper = query(j+1);

                int lower = query(i);

                printf("%d\n",upper-lower);
            }
        }
    }
    return 0;
}
