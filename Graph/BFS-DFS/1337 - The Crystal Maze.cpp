#include<bits/stdc++.h>
using namespace std;
#define siz 501
#define pii pair<int,int>

char ar[siz][siz];

int cnt,M,N,visit[siz][siz],result[siz][siz];

vector<int>v[2];

//4 Direction
int row[]= {1,0,-1,0};
int col[]= {0,1,0,-1};


void bfs(int s_r,int s_c)
{

    queue <pii>q;

    q.push(pii(s_r,s_c));

    visit[s_r][s_c]=1;

    v[0].push_back(s_r);
    v[1].push_back(s_c);


    while(!q.empty())
    {
        pii top = q.front();

        q.pop();

        for(int k=0; k<4; k++)
        {
            int tx = top.first+row[k];
            int ty = top.second+col[k];

            if(tx>=0&&tx<M&&ty>=0&&ty<N&&ar[tx][ty]!='#'&&visit[tx][ty]==0)
            {

                if(ar[tx][ty]=='C')
                    cnt++;

                visit[tx][ty] = 1;

                v[0].push_back(tx);
                v[1].push_back(ty);

                q.push(pii(tx,ty));

            }
        }

    }

}


int main()
{
    int a,test,Q,x,y;

    scanf("%d",&test);

    for(a=1; a<=test; a++)
    {

        scanf("%d %d %d",&M,&N,&Q);

        for(int i=0; i<M; i++)
            for(int j=0; j<N; j++)
                scanf(" %c",&ar[i][j]);

        printf("Case %d:\n",a);

        memset(visit,0,sizeof visit);

        for(int i=0; i<M; i++)
        {
            for(int j=0; j<N; j++)
            {
                if(ar[i][j]=='.'&&!visit[i][j])
                {
                    cnt=0;

                    bfs(i,j);

                    for(int k=0; k<v[0].size(); k++)
                    {
                        int r = v[0][k];
                        int c = v[1][k];

                        result[r][c] = cnt;
                    }

                    v[0].clear();
                    v[1].clear();

                }
            }
        }

        for(int i=0; i<Q; i++)
        {

            scanf("%d %d",&x,&y);

            printf("%d\n",result[x-1][y-1]);

        }

    }

    return 0;

}
