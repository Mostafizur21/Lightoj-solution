#include<bits/stdc++.h>
#define mx 100005
#define ll int
using namespace std;

struct info
{
    ll prop;
} tree[mx*3];

ll T,N,C,p,q,bit;

void query(ll node,ll b,ll e,ll i,ll j,ll carry)
{

    //cout<<node<<" "<<b<<" "<<e<<" "<<carry<<endl;

    if(i>e||j<b)
        return;

    if(b==i&&e==j)
    {
        // cout<<"Carry "<<carry<<" "<<node<<ends<<tree[node].prop<<" "<<(tree[node].prop^carry)<<endl;

        bit =  tree[node].prop^carry;
        return;
    }

    ll left = node*2;

    ll right = node*2+1;

    ll mid = (b+e)/2;

    query(left,b,mid,i,j,tree[node].prop^carry);

    query(right,mid+1,e,i,j,tree[node].prop^carry);

}


void update(ll node,ll b,ll e,ll i,ll j,ll carry)
{
    //cout<<node<<" "<<b<<" "<<e<<" "<<carry<<endl;
    if(i>e||j<b)
        return;

    if(b>=i&&e<=j)
    {
        //cout<<"Carry "<<carry<<" "<<node<<endl;
        tree[node].prop^=carry;
        return;
    }

    ll left = node*2;

    ll right = node*2+1;

    ll mid = (b+e)/2;

    update(left,b,mid,i,j,carry);

    update(right,mid+1,e,i,j,carry);

}


int main()
{

    scanf("%d",&T);

    string s;

    char ch;

    for(int cas=1; cas<=T; cas++)
    {

        memset(tree,0,sizeof tree);

        cin>>s;

        N = s.size();

        //cout<<s<<" "<<N<<endl;

        scanf("%d",&C);

        getchar();

        printf("Case %d:\n",cas);

        while(C--)
        {
            scanf("%c",&ch);

            if(ch=='I')
            {
                scanf("%d%d",&p,&q);

                update(1,1,N,p,q,1);

//                for(int i=1;i<=30;i++)
//                    cout<<tree[i].prop<<ends;
//                cout<<endl;

            }

            else
            {
                scanf("%d",&p);

                query(1,1,N,p,p,0);

                //cout<<"BIT "<<bit<<endl;

                if(bit)
                {
                    //  cout<<"IN"<<endl;
                    if(s[p-1]=='0')
                        printf("1\n");

                    else
                        printf("0\n");
                }

                else
                    printf("%c\n",s[p-1]);
            }

            getchar();
        }

    }

    return 0;

}

