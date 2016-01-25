#include<bits/stdc++.h>

using namespace std;

int main()
{

    int test;

    double Ox,Oy,Ax,Ay,Bx,By,r,theta,a,b,c;

    cin>>test;

    for(int i=1; i<=test; i++)
    {
        cin>>Ox>>Oy>>Ax>>Ay>>Bx>>By;

        a = sqrt((Ox-Bx)*(Ox-Bx)+(Oy-By)*(Oy-By));

        b = sqrt((Ox-Ax)*(Ox-Ax)+(Oy-Ay)*(Oy-Ay));

        c = sqrt((Ax-Bx)*(Ax-Bx)+(Ay-By)*(Ay-By));

        theta = (a*a+b*b-c*c)/(2.0*a*b);

        printf("Case %d: %.10lf\n",i,acos(theta)*a);

    }

    return 0;
}

