#include<bits/stdc++.h>

using namespace std;

bool check;

struct node
{
    bool endmark;

    node *next[10+1];

    node()
    {
        endmark = false;

        for(int i=0; i<10; i++)

            next[i]=NULL;
    }

}*root;

void insert(char *str,int len)
{
    node *curr = root;

    bool temp = false;

    for(int i=0; i<len; i++)
    {
        int id = str[i]-'0';

        if(curr->next[id]==NULL)
        {
            curr->next[id] = new node();

            temp = true;
        }

        curr = curr->next[id];

        if(curr->endmark)

            check = true;

    }

    if(!temp)

        check = true;

    curr->endmark = true;
}

void del(node *cur)
{
    for(int i=0; i<10; i++)
    {
        if(cur->next[i])
            del(cur->next[i]);
    }

    delete(cur);
}



int main()
{
    int test,n,cas=1;

    cin>>test;

    while(test--)
    {

        check = false;

        root = new node();

        cin>>n;

        for(int i=1; i<=n; i++)
        {
            char str[12];

            cin>>str;

            insert(str,strlen(str));
        }

        if(check)

            cout<<"Case "<<cas++<<": NO"<<endl;

        else

            cout<<"Case "<<cas++<<": YES"<<endl;

        del(root);

    }


    return 0;
}
