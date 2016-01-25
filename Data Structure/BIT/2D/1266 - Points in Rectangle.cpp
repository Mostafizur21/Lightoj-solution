#include<bits/stdc++.h>

using namespace std;

int tree[1005][1005];
bool check[1005][1005];

int maxi;

int update(int x,int y,int val)
{
    while(x<=maxi)
    {
        int temp = y;

        while(temp<=maxi)
        {
            tree[x][temp]+=val;

            temp+=temp&-temp;
        }
        x+=x&-x;
    }
}

int sum(int x,int y)
{
    int result=0;

    while(x>0)
    {
        int temp = y;
        while(temp>0)
        {

            result+=tree[x][temp];
            temp-=temp&-temp;
        }
        x-=x&-x;
    }
    return result;
}

int main()
{
    int test,query,x,y,x1,y1,x2,y2,m;

    maxi = 1001;

    scanf("%d",&test);

    for(int i=1; i<=test; i++)
    {
        memset(tree,0,sizeof tree);

        memset(check,0,sizeof check);

        printf("Case %d:\n",i);

        scanf("%d",&query);

        for(int a=1; a<=query; a++)
        {
            scanf("%d",&m);

            if(m==0)
            {
                scanf("%d%d",&x,&y);

                x++;//as BIT start index at 1 not 0
                y++;

                if(!check[x][y])
                {
                    check[x][y] = true;

                    update(x,y,1);
                }
            }

            else
            {
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);

                x1++;
                x2++;
                y1++;
                y2++;

                int ans = sum(x2,y2);

                ans-=sum(x1-1,y2);

                ans-=sum(x2,y1-1);

                ans+=sum(x1-1,y1-1);

                printf("%d\n",ans);

            }
        }

    }

    return 0;

}
