#include <bits/stdc++.h>

using namespace std;

int p[100+5],rank[100+5],p1[100+5],rank1[100+5];

struct data_min
{
    int a,b,c;

    bool operator<(const data_min &p)const
    {
        return c>p.c;
    }

} dt;

struct data_max
{
    int a,b,c;

    bool operator<(const data_max &p)const
    {
        return c<p.c;
    }

} dt1;

int Find(int x)
{
    if(x==p[x])
        return x;

    else
        return p[x] = Find(p[x]);
}

int Find1(int x)
{
    if(x==p1[x])
        return x;

    else
        return p1[x] = Find1(p1[x]);
}

int Union(int a,int b)
{
    if(rank[a]<rank[b])

        p[a] = Find(b);

    else
    {
        p[b] = Find(a);

        if(rank[a] ==rank[b])

            rank[a]++;
    }
}

int Union1(int a,int b)
{
    if(rank1[a]<rank1[b])

        p1[a] = Find1(b);

    else
    {
        p1[b] = Find1(a);

        if(rank1[a] ==rank1[b])

            rank1[a]++;
    }
}

int main()
{
    int test;

    int node,edge;

    scanf("%d",&test);

    for(int t=1; t<=test; t++)
    {

        scanf("%d",&node);

        priority_queue<data_min>pq;

        priority_queue<data_max>pq1;

        node++;

        int start,end,cost;

        while(scanf("%d %d %d",&start,&end,&cost))
        {
            if(start==0&&end==0&&cost==0)
                break;

            dt.a = start;

            dt.b = end;

            dt.c = cost;

            dt1.a = start;

            dt1.b = end;

            dt1.c = cost;

            p[start] = start;

            p[end] = end;

            rank[start] = 0;

            rank[end] = 0;

            pq.push(dt);

            p1[start] = start;

            p1[end] = end;

            rank1[start] = 0;

            rank1[end] = 0;

            pq1.push(dt1);

        }

        int total_cost = 0,cnt = 0;

        while(!pq.empty())
        {

            if(cnt == node-1)
                break;

            int x,y,z;

            x = pq.top().a;

            y = pq.top().b;

            z = pq.top().c;

            int PA = Find(x);

            int PB = Find(y);

            if(PA!=PB)
            {
                cnt++;

                total_cost+=z;

                Union(PA,PB);
            }

            pq.pop();

        }

        cnt = 0;

        while(!pq1.empty())
        {

            if(cnt == node-1)
                break;

            int x,y,z;

            x = pq1.top().a;

            y = pq1.top().b;

            z = pq1.top().c;

            int PA = Find1(x);

            int PB = Find1(y);

            if(PA!=PB)
            {
                cnt++;

                total_cost+=z;

                Union1(PA,PB);
            }

            pq1.pop();

        }

        if(total_cost%2==0)
            printf("Case %d: %d\n",t,total_cost/2);

        else
            printf("Case %d: %d/2\n",t,total_cost);


    }

    return 0;

}
