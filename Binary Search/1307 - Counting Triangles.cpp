#include<bits/stdc++.h>

using namespace std;

int main()
{

    long long arr[2000+5],i,j,a,N,test,x,result,sum,left,right,mid;

    cin>>test;

    for(x=1; x<=test; x++)
    {
        result = 0;

        cin>>N;

        for(i=0; i<N; i++)
            cin>>arr[i];

        sort(arr,arr+N);

        for(i=0; i<N-2; i++)
        {

            for(j=i+1; j<N-1; j++)
            {
                sum = arr[i]+arr[j];

                left = j+1;

                right = N-1;

                while(left<right)
                {
                    mid = left+(right-left)/2;

                    if(arr[mid]<sum)
                        left = mid+1;

                    else
                        right = mid;
                }

                while(arr[left]>=sum)
                    left--;

                result+=left-j;

            }

        }

        cout<<"Case "<<x<<": "<<result<<endl;

    }

    return 0;
}

