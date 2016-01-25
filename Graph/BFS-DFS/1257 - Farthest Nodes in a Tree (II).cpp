#include<bits/stdc++.h>

using namespace std;

#define mx 30005

typedef pair<int,int>ppp;
vector<ppp>graph[mx];
int dist[mx],dist2[mx];

bool visit[mx];

int node,from,dest,cost;


void bfs(int source)
{

    queue <int>q;

    q.push(source);

    dist[source] = 0;

    visit[source] = true;

    while(!q.empty())
    {
        int top = q.front();

        q.pop();

        for(int i=0; i<graph[top].size(); i++)
        {
            int v = graph[top][i].first;

            if(!visit[v])
            {
                visit[v]=true;

                dist[v] = dist[top]+graph[top][i].second;

                q.push(v);
            }
        }

    }

}


void bfs2(int source)
{

    queue <int>q;

    q.push(source);

    dist2[source] = 0;

    visit[source] = true;

    while(!q.empty())
    {
        int top = q.front();

        q.pop();

        for(int i=0; i<graph[top].size(); i++)
        {
            int v = graph[top][i].first;

            if(!visit[v])
            {
                visit[v]=true;

                dist2[v] = dist2[top]+graph[top][i].second;

                q.push(v);
            }
        }

    }

}

int main()
{

    int test;

    scanf("%d",&test);

    for(int t=1; t<=test; t++)
    {
        scanf("%d",&node);

        for(int i=1; i<node; i++)
        {
            scanf("%d %d %d",&from,&dest,&cost);

            graph[from].push_back(ppp(make_pair(dest,cost)));
            graph[dest].push_back(ppp(make_pair(from,cost)));

        }

        memset(visit,false, sizeof visit);

        bfs(0);

        int maxi=-1,far_node;

        for(int i=0; i<node; i++)
        {
            if(dist[i]>maxi)
                maxi=dist[i],far_node=i;
        }

        memset(visit,false, sizeof visit);

        bfs(far_node);

        maxi=-1;

        for(int i=0; i<node; i++)
        {
            if(dist[i]>maxi)
                maxi=dist[i],far_node=i;
        }

        memset(visit,false, sizeof visit);

        bfs2(far_node);

        for(int i=0; i<=node; i++)
            graph[i].clear();

        printf("Case %d:\n",t);

        for(int i=0; i<node; i++)
            printf("%d\n",max(dist[i],dist2[i]));

    }

    return 0;
}
