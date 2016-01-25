#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test,N,i,j,k,m,n,p,q;
    char c[105];
    scanf("%d",&test);
    for(i=1; i<=test; i++)
    {
        m=q=0;
        scanf("%d",&n);
        getchar();
        for(p=0; p<n; p++)
            scanf("%c",&c[p]);
        for(j=0; c[j]!='\0'; j++)
        {
            if(c[j]=='.'&&c[j+2]=='.'&&j+2<n)
            {
                m++;
                j+=2;
            }
            else if(c[j]=='.'&&c[j+1]=='.'&&c[j+2]=='#'&&j+2<n)
            {
                m++;
                j+=2;
            }
            else if(c[j]=='.'&&j==n-1)
            {
                m++;
            }
            else if(c[j]=='.'&&c[j+1]=='.'&&j+1==n-1)
            {
                m++;
                j++;
            }
            else if(c[j]=='.'&&c[j+1]=='#'&&c[j+2]=='#'&&j+2<n)
            {
                m++;
                j+=2;
            }
            else if(c[j]=='.'&&c[j+1]=='#'&&j+1==n-1)
            {
                m++;
                j++;
            }
            else
                continue;
        }
        printf("Case %d: %d\n",i,m);
    }
    return 0;
}

