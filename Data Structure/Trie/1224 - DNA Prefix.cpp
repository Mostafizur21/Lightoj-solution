#include<bits/stdc++.h>

using namespace std;

map<char,int>mp;

int maxi,len;

char str[52];

struct node
{
    node *next[4];

    int counter[4];

    node()
    {

        for(int i=0; i<4; i++)
        {
            next[i]=NULL;

            counter[i] = 0;
        }

    }

}*root;

void insert()
{
    node *curr = root;

    for(int i=0; i<len; i++)
    {
        int id = mp[str[i]];

        curr->counter[id]++;

        maxi = max(maxi,((i+1)*curr->counter[id]));

        if(curr->next[id]==NULL)
            curr->next[id] = new node();

        curr = curr->next[id];

    }
}

void del(node *cur)
{
    for(int i=0; i<4; i++)
    {
        if(cur->next[i])
            del(cur->next[i]);
    }

    delete(cur);
}


int main()
{
    int test,n;

    mp['A'] = 0;

    mp['C'] = 1;

    mp['G'] = 2;

    mp['T'] = 3;

    scanf("%d",&test);

    for(int t=1; t<=test; t++)
    {

        maxi = 0;

        root = new node();

        scanf("%d",&n);

        for(int i=1; i<=n; i++)
        {

            scanf("%s",&str);

            len = strlen(str);

            insert();

        }

        printf("Case %d: %d\n",t,maxi);

        del(root);

    }

    return 0;
}
