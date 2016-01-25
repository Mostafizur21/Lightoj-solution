#include <bits/stdc++.h>

using namespace std;

vector<char>v;

void print()
{
    for(int a=0; a<v.size(); a++)
        cout<<v[a];

    cout<<endl;

}

int main()
{
    int T,N,K,i,j,m;

    cin>>T;

    for(i=1; i<=T; i++)
    {
        v.clear();

        m=1;

        cin>>N>>K;

        char c;

        for(j=0; j<N; j++)
        {
            c = 65+j;

            v.push_back(c);

        }

        cout<<"Case "<<i<<":"<<endl;

        print();

        if(m<K)
            while(next_permutation(v.begin(),v.end()))
            {
                m++;

                print();

                if(m==K)
                    break;
            }

    }

    return 0;
}
