#include<bits/stdc++.h>

using namespace std;

int main()
{

    int T,n,q,arr[100005],a,b,i,j,left,right,mid,points;

    scanf("%d",&T);

    for(i=1; i<=T; i++)
    {
        scanf("%d%d",&n,&q);

        for(j=0; j<n; j++)
            scanf("%d",&arr[j]);

        printf("Case %d:\n",i);

        for(j=1; j<=q; j++)
        {
            scanf("%d%d",&a,&b);

            points = 0;

            left = 0;

            right = n-1;

            while(left<right)
            {

                mid = left+(right-left)/2;

                if(arr[mid]<a)
                    left = mid+1;

                else
                    right = mid;
            }

            while(arr[left]<a)
                left++;

            int k = left;

            left = 0;

            right = n-1;

            while(left<right)
            {

                mid = left+(right-left)/2;

                if(arr[mid]<b)
                    left = mid+1;

                else
                    right = mid;
            }

            while(arr[left]>b)
                left--;

            printf("%d\n",left-k+1);

        }

    }

    return 0;
}
