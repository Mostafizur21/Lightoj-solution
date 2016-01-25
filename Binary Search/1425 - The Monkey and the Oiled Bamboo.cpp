#include <bits/stdc++.h>
using namespace std;

long long low,high,mid,number_n,arr[100000+5];

bool cheak;

bool cando(long long k)
{
    if(arr[0]>k)
    {
        cheak = false;

        return false;
    }

    else if(arr[0]==k)
        k--;

    int j;

    for(j =1; j<number_n; j++)
    {
        if((arr[j]-arr[j-1])>k)
        {
            cheak =false;

            break;
        }

        else if((arr[j]-arr[j-1])==k)
        {
            k--;
        }
    }

    if(cheak)

        return true;

    else

        return false;
}

int main()
{
    long long test,result;

    cin>>test;

    for(int i = 1; i<=test; i++)
    {
        cheak = true;

        cin>>number_n;

        for(int j=0; j<number_n; j++)
            cin>>arr[j];

        low = arr[0];

        high = arr[number_n-1];

        mid = (low+high)/2;

        while(1)
        {
            if(cando(mid))
            {
                result = mid;

                high = mid;

                mid = low+(high-low)/2;

                break;
            }

            else
            {
                if(cheak==false)
                {
                    cheak = true;

                    low = mid+1;

                    mid = low+(high-low)/2;
                }

                else
                {
                    high = mid;

                    mid = low+(high-low)/2;
                }

            }
        }

        while(1)
        {
            if(low==mid&&mid==high)

                break;

            if(cando(mid))
            {
                result = mid;

                high = mid;

                mid = low+(high-low)/2;
            }

            else
            {
                if(cheak==false)
                {
                    cheak = true;

                    low = mid+1;

                    mid = low+(high-low)/2;
                }

                else
                {
                    high = mid;

                    mid = low+(high-low)/2;
                }

            }
        }

        cout<<"Case "<<i<<": "<<result<<endl;
    }

    return 0;
}
