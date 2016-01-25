#include<bits/stdc++.h>

using namespace std;

int main()
{
    int x,y,N,m,indx;

    string s1,s2;

    int test;

    scanf("%d",&test);

    for(int t=1; t<=test; t++)
    {
        indx=0;

        map<int,int>indegree;

        map<int,int>visited;

        map<string,int>map1;

        vector<int>v[10005];

        scanf("%d",&m);

        for(int i=0; i<m; i++)
        {
            cin>>s1>>s2;

            if(!map1[s1])
            {
                map1[s1] = ++indx;

            }

            if(!map1[s2])
            {
                map1[s2] = ++indx;

            }

            v[map1[s1]].push_back(map1[s2]);

            indegree[map1[s2]]++;

        }

        queue<int>q;

        for(int i=1; i<=indx; i++)
        {
            if(!indegree[i])
                q.push(i);
        }

        int cnt=0;

        while(!q.empty())
        {
            int u = q.front();

            q.pop();

            cnt++;

            for(int i=0; i<v[u].size(); i++)
            {
                indegree[v[u][i]]--;

                if(!indegree[v[u][i]])
                    q.push(v[u][i]);
            }
        }

        if(cnt!=indx)
            printf("Case %d: No\n",t);

        else
            printf("Case %d: Yes\n",t);

    }

    return 0;

}
