#include<bits/stdc++.h>

using namespace std;

int main()
{
    int T,n,arr[105],i,swp;

    cin>>T;

    for(i=1; i<=T; i++)
    {
        cin>>n;

        for(int j=0; j<n; j++)
            cin>>arr[j];

        swp=0;

        for(int j=0; j<n; j++)
        {
            int temp = arr[j];

            int ind=0;

            for(int k=j+1; k<n; k++)
            {
                if(temp>arr[k])
                {
                    temp  = arr[k];
                    ind = k;
                }
            }

            if(temp!=arr[j])
            {
                swp++;

                arr[ind] = arr[j];

                arr[j] = temp;

            }
        }

        cout<<"Case "<<i<<": "<<swp<<endl;
    }

    return 0;
}

