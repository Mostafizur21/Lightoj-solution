#include<bits/stdc++.h>
#define clr(arr, key) memset(arr, key, sizeof arr)

#define MAX 100010

using namespace std;

int trie[MAX][52],last,cnt[MAX],len;

void add(char *str)
{
    int i, id, cur = 0;

    int len = strlen(str);

    for(i = 0; i<len; i++)
    {
        if(str[i]>='a'&&str[i]<='z')
            id = str[i] - 'a'+26;

        else
            id = str[i]-'A';

        if(trie[cur][id] == -1)
        {
            trie[cur][id] = ++last;

            clr(trie[last], -1);

            cnt[last] = 0;

        }
        cur = trie[cur][id];
    }

    cnt[cur]++;


}

int get(char *str)
{
    int id, i, cur = 0;

    len = strlen(str);

    for(i=0; i<len; i++)
    {
        if(str[i]>='a'&&str[i]<='z')
            id = str[i] - 'a'+26;

        else
            id = str[i]-'A';

        if(trie[cur][id] == -1)
            return 0;

        cur = trie[cur][id];
    }

    return cnt[cur];

}

int main()
{

    int n,m,len,test;

    char str[MAX];

    char ch[MAX];

    scanf("%d",&test);

    for(int t = 1; t<=test; t++)
    {

        clr(trie[0], -1);

        last = 0;

        scanf("%d", &n);

        while(n--)
        {
            scanf("%s", str);

            len = strlen(str);

            if(len>2)
                sort(str + 1, str + len - 1);

            add(str);

        }

        printf("Case %d:\n",t);

        scanf("%d", &m);

        getchar();

        while(m--)
        {
            gets(ch);

            int result=1;

            int in=0;

            int temp = strlen(ch);

            for(int i=0; i<temp; i++)
            {
                if(ch[i]==' ')
                {
                    str[in] = '\0';

                    len = strlen(str);

                    if(len>2)
                        sort(str + 1, str + len - 1);
                    if(len)
                        result*=get(str);

                    in=0;

                }

                else
                    str[in++] = ch[i];
            }

            str[in] = '\0';

            len = strlen(str);

            if(len>2)
                sort(str + 1, str + len - 1);

            if(len)
                result*=get(str);

            printf("%d\n",result);

        }

    }

    return 0;
}
