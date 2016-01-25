#include<bits/stdc++.h>

using namespace std;

int main()
{

    int test,x1,x2,y1,y2,x3,y3,x4,y4,a,b,c,d;

    cin>>test;

    for(int i=1; i<=test; i++)
    {
        cin>>x1>>y1>>x2>>y2>>x3>>y3;

        x4 = x3-x2;

        x4+=x1;

        y4 = y3-y2;

        y4+=y1;

        a = x2-x1;

        b = y2-y1;

        c = x4-x1;

        d = y4-y1;

        int e = a*d-b*c;

        e = abs(e);

        cout<<"Case "<<i<<": "<<x4<<" "<<y4<<" "<<e<<endl;

    }

    return 0;

}
