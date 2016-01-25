#include<bits/stdc++.h>

using namespace std;

int substring,m,prefix[1000001];

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


int KMP_match()
{

    int q=0;

    for(int i=1; i<=m; i++)
    {
        while(q>0&&pattern[q+1]!=text[i])
            q = prefix[q];

        if(pattern[q+1]==text[i])
            q++;

    }

    return q;
}


int main()
{

    int test;

    scanf("%d",&test);

    for(int t=1; t<=test; t++)
    {

        substring=INFINITY;

        scanf("%s",text+1);

        m = strlen(text+1);

        for(int i=m; i>=1; i--)
            pattern[m-i+1] = text[i];

        compute_prefix();

        printf("Case %d: %d\n",t,2*m-KMP_match());

    }

    return 0;
}
