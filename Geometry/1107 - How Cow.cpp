#include<bits/stdc++.h>

using namespace std;

int main()
{

    int test,x1,x2,y1,y2,x,y,M;

    cin>>test;

    for(int i=1; i<=test; i++)
    {
        cin>>x1>>y1>>x2>>y2;

        cin>>M;

        cout<<"Case "<<i<<":"<<endl;

        while(M--)
        {
            cin>>x>>y;

            if((x>x1&&x<x2)&&(y>y1&&y<y2))
                cout<<"Yes"<<endl;

            else
                cout<<"No"<<endl;
        }

    }

    return 0;

}

