#include<bits/stdc++.h>
using namespace std;
#define siz 11
#define pii pair<int,int>

char ar[siz][siz];

int N,k,mov,cnt,x,y,food;

//4 Direction
int row[]= {1,0,-1,0};
int col[]= {0,1,0,-1};

int mat[siz][siz];


void bfs(int s_r,int s_c)
{

    bool check =false;

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

            if(tx>=0&&tx<N&&ty>=0&&ty<N&&ar[tx][ty]!='#'&&mat[tx][ty]==0)
            {
                 mat[tx][ty] = mat[top.first][top.second]+1;
                if(ar[tx][ty]=='.')
                {
                    //cout<<"NO"<<endl;
                    q.push(pii(tx,ty));
                }

                else if(ar[tx][ty]-'A'==cnt)
                {
                    //cout<<"YES"<<endl;
                    x = tx,y=ty;
                    food++;
                    check=true;
                    mov+=mat[tx][ty];
                   // cout<<ar[tx][ty]<<" "<<mat[tx][ty]<<endl;
                    ar[tx][ty]='.';
                    break;

                }
                //if(ar[tx][ty]=='.')


            }
        }
        if(check)
            break;

    }

    while(!q.empty())
        q.pop();

}


int main()
{
    int a,test;

    scanf("%d",&test);

    for(a=1; a<=test; a++)
    {

        k=mov=cnt=food=0;

        scanf("%d",&N);

        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
            {
                scanf(" %c",&ar[i][j]);

                if(ar[i][j]>='A'&&ar[i][j]<='Z')
                    k++;

                if(ar[i][j]=='A')
                    x=i,y=j;
            }

        ar[x][y]='.';

        for(int i=2; i<=k; i++)
        {
            memset(mat,0,sizeof mat);

            cnt++;

            bfs(x,y);

            //cout<<food<<" "<<mov<<" "<<x<<" "<<y<<endl;
        }

        if(food!=k-1)
            printf("Case %d: Impossible\n",a);

        else
            printf("Case %d: %d\n",a,mov);

    }

    return 0;

}
