#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{

    int test,n,arr[105],sum,pos_door;

    scanf("%d",&test);

    for(int t=1; t<=test; t++)
    {
        scanf("%d",&n);

        sum=pos_door=0;

        for(int i=0; i<n; i++)
        {
            scanf("%d",&arr[i]);
            sum+=abs(arr[i]);
            if(arr[i]>0)
                pos_door++;
        }

        if(!pos_door)
            printf("Case %d: inf\n",t);

        else
        {
            int GCD = __gcd(sum,pos_door);

            printf("Case %d: %d/%d\n",t,sum/GCD,pos_door/GCD);
        }
    }

    return 0;
}
