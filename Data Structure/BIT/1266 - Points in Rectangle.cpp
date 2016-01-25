#include<bits/stdc++.h>

using namespace std;

int tree[1002][1002];

int maxi;

int update(int x,int y,int val)
{
    while(x<=maxi)
    {
        int temp = y;

        while(temp<=maxi)
        {
            tree[x][temp]+=val;
            //cout<<tree[x][temp]<<endl;
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
    int x_axis[1001],y_axis[1001],test,query,x,y,x1,y1,x2,y2,m;

    maxi = 1000;

    scanf("%d",&test);

    for(int i=1; i<=test; i++)
    {

        for(int j=0; j<=1000; j++)
        {
            x_axis[j] = 0;
            y_axis[j] = 0;

        }

        for(int j=1; j<=1001; j++)
        {
            for(int k=1; k<=1001; k++)
                tree[j][k] = 0;
        }

        printf("Case %d:\n",i);

        scanf("%d",&query);

        /*for(int p=0;p<=10;p++)
        {
            for(int q=0;q<=10;q++)
                cout<<tree[p][q]<<" ";
            cout<<endl;
        }*/

        for(int a=1; a<=query; a++)
        {
            scanf("%d",&m);

            if(m==0)
            {
                scanf("%d%d",&x,&y);

                if(x_axis[x]==0&&y_axis[y]==0)
                {
                    x_axis[x]=1;

                    y_axis[y]=1;

                    update(x+1,y+1,1);

//                    for(int p=1; p<=11; p++)
//                    {
//                        for(int q=1; q<=11; q++)
//                            cout<<tree[p][q]<<" ";
//                        cout<<endl;
//                    }
                }
            }

            else
            {
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);

                int ans = sum(x2+1,y2+1);

                ans-=sum(x1,y2+1);

                ans-=sum(x2+1,y1);

                ans+=sum(x1,y1);

                printf("%d\n",ans);

            }
        }

    }

    return 0;

}
