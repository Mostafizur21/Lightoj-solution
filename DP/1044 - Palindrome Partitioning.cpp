#include<bits/stdc++.h>

using namespace std;

string str;

int minPalPartion()
{
    int len = str.size();

    int c[1005];

    bool p[1005][1005];

    for(int i=0; i<len; i++)
        p[i][i] = true;

    for(int L=2; L<=len; L++)
    {
        for(int i=0; i<len-L+1; i++)
        {
            int j = i+L-1;

            if(L==2)
                p[i][j] = (str[i]==str[j]);

            else
                p[i][j] = (str[i]==str[j])&&p[i+1][j-1];
        }
    }

    for(int i=0; i<len; i++)
    {
        if(p[0][i]==true)
            c[i] = 0;

        else
        {
            c[i] = INT_MAX;

            for(int j=0; j<i; j++)
            {
                if(p[j+1][i]==true &&1+c[j]<c[i])
                    c[i] = 1+c[j];
            }
        }
    }

    return c[len-1];

}


int main()
{

    int test;

    cin>>test;

    for(int i=1; i<=test; i++)
    {

        cin>>str;

        cout<<"Case "<<i<<": "<<minPalPartion()+1<<endl;

    }

    return 0;

}

