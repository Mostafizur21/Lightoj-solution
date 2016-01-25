#include<bits/stdc++.h>

using namespace std;

int substring,n,m,prefix[1000001];

char text[1000001],pattern[1000001];

void compute_prefix()
{

    int k=0;

    prefix[1]=0;

    for(int i=2; i<=m; i++)
    {
        while(k>0&&pattern[k+1]!=pattern[i])
            k = prefix[k];

        if(pattern[k+1]==pattern[i])
            k++;

        prefix[i]=k;

    }

}


void KMP_match()
{

    int q=0;

    for(int i=1; i<=n; i++)
    {
        while(q>0&&pattern[q+1]!=text[i])
            q = prefix[q];

        if(pattern[q+1]==text[i])
            q++;

        if(q==m)
        {
            substring++;

            q = prefix[q];
        }
    }
}


int main()
{

    int test;

    scanf("%d",&test);

    for(int t=1; t<=test; t++)
    {

        substring=0;

        scanf("%s %s",text+1,pattern+1);

        m=strlen(pattern+1);
        n = strlen(text+1);

        compute_prefix();

        KMP_match();

        printf("Case %d: %d\n",t,substring);

    }

    return 0;
}

