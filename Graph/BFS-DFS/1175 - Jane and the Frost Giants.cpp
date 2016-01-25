#include<bits/stdc++.h>
using namespace std;
#define siz 201
#define pii pair<int,int>

char ar[siz][siz];

int R,C,mov,cnt,j_x,j_y,f_x,f_y;

//4 Direction
int row[]= {1,0,-1,0};
int col[]= {0,1,0,-1};

int mat[siz][siz];

int mat_fair[siz][siz];

vector<pii>fair,fair2,joni,joni2;

void bfs_for_fair(int s_r,int s_c)
{
    for(int k=0; k<4; k++)
    {
        int tx = s_r+row[k];
        int ty = s_c+col[k];

        if(tx>=0&&tx<R&&ty>=0&&ty<C&&ar[tx][ty]!='#'&&mat_fair[tx][ty]==0)
        {
            mat_fair[tx][ty] = 1;
            fair2.push_back(pii(tx,ty));

        }
    }
}

void bfs()
{

    bool check =false;

    while(joni.size()>0)
    {

        for(int i=0; i<fair.size(); i++)
        {
            pii value_x_y =fair[i];

            int x = value_x_y.first;
            int y = value_x_y.second;

            bfs_for_fair(x,y);
        }

        fair.clear();

        fair = fair2;

        fair2.clear();

        for(int i=0; i<joni.size(); i++)
        {
            pii top =joni[i];

            for(int k=0; k<4; k++)
            {
                int tx = top.first+row[k];
                int ty = top.second+col[k];

                if((ar[tx][ty]=='.'&&mat_fair[tx][ty]==0)&&(tx==0||tx==R-1||ty==0||ty==C-1)&&mat[tx][ty]==0)
                {

                    mat[tx][ty] = mat[top.first][top.second]+1;
                    mov = mat[tx][ty]+1;
                    check = true;
                    break;

                }

                else if(tx>=0&&tx<R&&ty>=0&&ty<C&&ar[tx][ty]!='#'&&mat[tx][ty]==0&&mat_fair[tx][ty]==0)
                {
                    mat[tx][ty] = mat[top.first][top.second]+1;

                    joni2.push_back(pii(tx,ty));

                }
            }

        }

        joni.clear();
        joni = joni2;
        joni2.clear();

        /*for(int i=0; i<R; i++)
        {
            for(int j=0; j<C; j++)
                cout<<mat_fair[i][j]<<" ";
            cout<<endl;
        }

        cout<<endl;

        for(int i=0; i<R; i++)
        {
            for(int j=0; j<C; j++)
                cout<<mat[i][j]<<" ";
            cout<<endl;
        }

        cout<<endl;*/

        if(check)
            break;

    }
}

int main()
{
    int a,test;

    scanf("%d",&test);

    for(a=1; a<=test; a++)
    {

        mov=-1;

        scanf("%d %d",&R,&C);

        fair.clear();
        fair2.clear();
        joni.clear();
        joni2.clear();

        for(int i=0; i<R; i++)
            for(int j=0; j<C; j++)
            {
                scanf(" %c",&ar[i][j]);

                if(ar[i][j]=='J')
                    j_x=i,j_y=j;

                if(ar[i][j]=='F')
                {
                    fair.push_back(pii(i,j));
                }

            }

        memset(mat,0,sizeof mat);
        memset(mat_fair,0,sizeof mat_fair);

        for(int i=0; i<fair.size(); i++)
        {
            pii value_x_y =fair[i];

            int x = value_x_y.first;
            int y = value_x_y.second;

            mat_fair[x][y]=1;
        }

        if(j_x==0||j_x==R-1||j_y==0||j_y==C-1)
        {
            printf("Case %d: 1\n",a);
            continue;
        }

        joni.push_back(pii(j_x,j_y));

        bfs();

        if(mov==-1)
            printf("Case %d: IMPOSSIBLE\n",a);

        else
            printf("Case %d: %d\n",a,mov);


    }

    return 0;

}
