#include <bits/stdc++.h>

using namespace std;

int dist[105][105],N;

void intial()
{

    for(int i=1; i<=100; i++)
        for(int j=1; j<=100; j++)
        {
            if(i==j)
                dist[i][j]=0;
            else
                dist[i][j]=10000000,dist[j][i]=10000000;
        }
}

void floyed_warshall()
{

    for(int k=1; k<=N; k++)
        for(int i=1; i<=N; i++)
            for(int j=1; j<=N; j++)
                if(dist[i][j]>(dist[i][k]+dist[k][j]))
                    dist[i][j] = dist[i][k]+dist[k][j];
}

int main()
{

    int test,M,source,dest,u,v,weight;

    scanf("%d",&test);

    for(int t=1; t<=test; t++)
    {

        scanf("%d %d",&N,&M);

        source = 1,dest = N;

        intial();

        for(int i=1; i<=M; i++)
        {
            scanf("%d %d %d",&u,&v,&weight);

            if(dist[u][v]>weight)
                dist[u][v] = weight;

            if(dist[v][u]>weight)
                dist[v][u] = weight;
        }

        floyed_warshall();

        printf("Case %d: ",t);

        if(dist[1][N]==10000000)
            printf("Impossible\n");

        else
            printf("%d\n",dist[1][N]);

    }

    return 0;
}

