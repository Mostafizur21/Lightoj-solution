#include<bits/stdc++.h>

using namespace std;

int main()
{

    int test;

    double a,b,c,d,e,f,s,tri_area,height,parallelogram_area,area;

    cin>>test;

    for(int i=1; i<=test; i++)
    {
        cin>>a>>b>>c>>d;

        e = b;

        f = a-c;

        s = f+e+d;

        s = s/2.0;

        tri_area = sqrt(s*(s-f)*(s-e)*(s-d));

        height = (tri_area*2.0)/f;

        parallelogram_area = c*height;

        area = tri_area+parallelogram_area;

        if(area<0)
            area*=-1.0;

        printf("Case %d: %lf\n",i,area);

    }

    return 0;

}
