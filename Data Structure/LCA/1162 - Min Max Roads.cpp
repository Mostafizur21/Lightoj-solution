//  Mafi, KUET 2K11

#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long ull;

#define sc1(n) scanf("%d",&n)
#define sc2(a,b) scanf("%d %d",&a,&b)
#define sc3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define sl1(n) scanf("%lld",&n)
#define sl2(a,b) scanf("%lld %lld",&a,&b)
#define sl3(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define mem(v,val) memset(v,val,sizeof v)
#define sz(v) v.size()
#define REVERSE(v) reverse(v.begin(),v.end())
#define all(v) v.begin(),v.end()
#define pb push_back
#define ff first
#define ss second
#define MP make_pair
#define pp pair<int,int>
#define pp1 pair<int,pair<int,int> >
#define pp2 pair<pair<int,int>,int >

#define rep(i,n) for(i=1;i<=n;i++)
#define Rep(i,n) for(i=0;i<n;i++)
#define For(i,a,b) for(i=a;i<=b;i++)

#define INF INT_MAX
#define MAXN 100006
#define modu 1000000007
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)

#define read() freopen("input.txt","r",stdin);
#define write() freopen("output.txt","w",stdout);

const double pi=acos(-1.0);

//int row[]={1,0,-1,0};int col[]={0,1,0,-1}; //4 Direction
//int row[]={1,1,0,-1,-1,-1,0,1};int col[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int row[]={2,1,-1,-2,-2,-1,1,2};int col[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction

ll leap(ll x)
{
    if((x%4==0&&x%100!=0)||x%400==0) return 1;
    return 0;
}

ll nCr(ll n, ll r)
{
    if(r==0) return 1;
    else return nCr(n-1,r-1)*n/r;
}

ll mod(ll N,ll M)//N%M
{
    ll temp = N/M;
    N-=temp*M;
    return N;
}

ll bigmod(ll N,ll M,ll MOD) //(N^M)%MOD
{
    if(M==0) return 1;
    if((M/2)*2==M)
    {
        ll ret = bigmod(N,M/2,MOD);
        return ((ret%MOD)*(ret%MOD))%MOD;
    }
    else return ((N%MOD)*bigmod(N,M-1,MOD)%MOD)%MOD;
}

ll modinverse(ll a,ll m)  //a*x=1(mod m)
{
    return bigmod(a,m-2,m);
}

struct Euclid
{
    ll x,y,d;
    Euclid() {};
    Euclid(ll xx,ll yy,ll dd)
    {
        x = xx, y = yy, d = dd;
    }
};

Euclid Extended_gcd(ll a, ll b)// input a,b Output x,y,d;ax+by = d,d=gcd(a,b)
{
    if(!b)
        return Euclid(1,0,a);
    Euclid e = Extended_gcd(b,a%b);
    return Euclid(e.y,e.x-a/b*e.y,e.d);
}

#define count_bit(x)    __builtin_popcountll(x) //number of 1 in binary of x; __builtin_popcount=int,__builtin_popcountl=long int,__builtin_popcountll=long long int
ll Set(ll N,ll pos)
{
    return N|(1LL<<pos);
}
ll reset(ll N,ll pos)
{
    return N&~(1LL<<pos);
}
ll check(ll N,ll pos)
{
    return (N&(1LL<<pos));
}

#define mx 100005

int p[mx],rank[mx];

typedef pair<int,int>ppp;

vector<ppp>graph[mx];

int level[mx];
int parent[mx][20];
int max_dist[mx][20];
int min_dist[mx][20];
int first_parent[mx];
int dist[mx];

bool visit[mx];

struct node
{
    int mini,maxi;
} min_max_dist;

void bfs(int source)
{

    queue <int>q;

    q.push(source);

    dist[source] = 0;//graph[source][0].second;

    first_parent[source] = source;

    level[source] = 0;

    visit[source] = 1;

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

                first_parent[v] = top;

                level[v] = level[top]+1;

                dist[v] = graph[top][i].second;

                q.push(v);
            }
        }

    }

}

void lca_init(int N)
{
    memset(parent,-1,sizeof(parent));

    int i,j;

    for(i=1; i<=N; i++)
        parent[i][0]=first_parent[i],max_dist[i][0] = dist[i],min_dist[i][0]=dist[i];

    for(j=1; (1<<j)<=N; j++)
        for(i=1; i<=N; i++)
            if(parent[i][j-1]!=-1)
                parent[i][j] = parent[parent[i][j-1]][j-1],max_dist[i][j] = max(max_dist[i][j-1],max_dist[parent[i][j-1]][j-1]),min_dist[i][j] = min(min_dist[i][j-1],min_dist[parent[i][j-1]][j-1]);

}



int lca_query(int x,int y)
{
    int temp,i;

    int log=1;

    int maxi=0,mini=mx;

    if(level[x]<level[y])
    {
        temp = x;
        x = y;
        y = temp;
    }

    while(1)
    {
        int next = log+1;

        if((1<<next)>level[x])
            break;

        log++;
    }

    for(i=log; i>=0; i--)
        if(level[x]-(1<<i)>=level[y])
        {
            maxi = max(maxi,max_dist[x][i]);
            mini = min(mini,min_dist[x][i]);
            x = parent[x][i];
        }

    if(x==y)
    {
        min_max_dist.mini = mini;
        min_max_dist.maxi = maxi;
        return 0;
    }

    for(i=log; i>=0; i--)
    {
        if(parent[x][i]!=-1&&parent[x][i]!=parent[y][i])
        {
            maxi = max(maxi,max(max_dist[x][i],max_dist[y][i]));
            mini = min(mini,min(min_dist[x][i],min_dist[y][i]));
            x = parent[x][i];
            y = parent[y][i];

        }
    }
    maxi = max(maxi,max(dist[x],dist[y]));
    mini = min(mini,min(dist[x],dist[y]));

    min_max_dist.mini = mini;
    min_max_dist.maxi = maxi;
    return 0;

}

int main()
{
    int test,t,i;
    int node;
    sc1(test);
    rep(t,test)
    {
        sc1(node);
        int start,end,cost;
        rep(i,node-1)
        {
            sc3(start,end,cost);

            graph[start].pb(ppp(make_pair(end,cost)));

            graph[end].pb(ppp(make_pair(start,cost)));

        }

        memset(visit,false,sizeof visit);

        bfs(1);

        lca_init(node);

        /*cout<<endl;
        cout<<endl;
        for(int i=1; i<=node; i++)
            for(int j=0; j<graph[i].size(); j++)
                cout<<i<<" "<<graph[i][j].first<<" "<<graph[i][j].second<<endl;
        for(int i=1; i<=node; i++)
            cout<<dist[i]<<ends;
        cout<<endl;
        cout<<endl;*/

        int query;

        sc1(query);

        printf("Case %d:\n",t);

        while(query--)
        {
            sc2(start,end);

            if(start>end)
            {
                int temp = start;
                start = end;
                end = temp;
            }

            lca_query(start,end);

            printf("%d %d\n",min_max_dist.mini,min_max_dist.maxi);
        }

        for(int i=0; i<=node; i++)
            graph[i].clear();
    }

    return 0;

}

