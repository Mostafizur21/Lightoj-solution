#include<bits/stdc++.h>
using namespace std;
#define siz 25
#define pii pair<int,int>

char ar[siz][siz];

int M,N;

//4 Direction
int row[]= {1,0,-1,0};
int col[]= {0,1,0,-1};

int mat[siz][siz];


void bfs(int s_r,int s_c)
{

    bool check = false;

    queue <pii>q;

    q.push(pii(s_r,s_c));

    while(!q.empty())
    {
        pii top = q.front();

        q.pop();

        for(int k=0; k<4; k++)
        {
            int tx = top.first+row[k];
            int ty = top.second+col[k];

            if(tx>=0&&tx<M&&ty>=0&&ty<N&&ar[tx][ty]!='#'&&ar[tx][ty]!='m'&&mat[tx][ty]==0)
            {

                mat[tx][ty] = mat[top.first][top.second]+1;

                if(ar[tx][ty]=='h')
                {
                    check = true;
                    break;
                }

                q.push(pii(tx,ty));

            }
        }

        if(check)
            break;

    }

}


int main()
{
    int a,test,x,y;

    scanf("%d",&test);

    for(a=1; a<=test; a++)
    {

        int maxi = 0;

        scanf("%d %d",&M,&N);

        for(int i=0; i<M; i++)
            for(int j=0; j<N; j++)
            {
                scanf(" %c",&ar[i][j]);

                if(ar[i][j]=='h')
                    x=i,y=j;
            }


        for(int i=0; i<M; i++)
        {
            for(int j=0; j<N; j++)
            {
                if(ar[i][j]=='a'||ar[i][j]=='b'||ar[i][j]=='c')
                {
                    memset(mat,0,sizeof mat);

                    bfs(i,j);

                    if(maxi<mat[x][y])
                        maxi = mat[x][y];

                }
            }

        }

        printf("Case %d: %d\n",a,maxi);

    }

    return 0;

}
