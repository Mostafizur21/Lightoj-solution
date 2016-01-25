#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int>pp;
vector<pp>v;

int main()
{
    int test,s,t,n,processing;

    scanf("%d",&test);

    for(int a=1; a<=test; a++)
    {
        scanf("%d",&n);

        v.clear();

        processing=0;

        for(int i=1; i<=n; i++)
        {
            scanf("%d %d",&s,&t);

            v.push_back(make_pair(s,1));
            v.push_back(make_pair(t,2));

        }

        sort(v.begin(),v.end());

        int ans=0;

        for(int i=0; i<v.size(); i++)
        {
            if(v[i].second==1)
                processing++;
            else
                processing--;
            if(processing<0)
                processing=0;
            ans = max(ans,processing);
        }

        printf("Case %d: %d\n",a,ans);

    }

    return 0;

}
