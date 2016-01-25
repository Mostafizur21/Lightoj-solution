#include<bits/stdc++.h>

using namespace std;

int c[1000+5],n,m;

int check(int temp)
{
    int cnt=0,sum=0;

    for(int i=0; i<n; i++)
    {
        sum+=c[i];

        if(sum>temp)
        {
            sum = c[i];
            cnt++;
        }

        else if(sum==temp)
        {
            cnt++;
            sum=0;
        }
    }
    if(sum>temp)
        return false;

    if(sum>0&&sum<=temp)
        cnt++;

    if(cnt<=m)
        return true;

    return false;
}


int main()
{

    int test,left,right,mid;

    cin>>test;

    for(int i=1; i<=test; i++)
    {

        cin>>n>>m;

        left = right = 0;

        for(int j=0; j<n; j++)
        {
            cin>>c[j];

            right+=c[j];

            if(c[j]>left)
                left = c[j];
        }


        while(left<right)
        {
            mid = (left+right)/2;

            if(check(mid))

                right = mid;

            else
                left = mid+1;

        }

        cout<<"Case "<<i<<": "<<left<<endl;

    }

    return 0;
}

