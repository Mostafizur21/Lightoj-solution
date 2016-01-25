#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll mod=10007;

ll n,test,a,b,c;

ll F[4][4];

/*
 * function to multiply two matrices
 */
void multiply(ll F[4][4], ll M[4][4])
{
    ll N[4][4];

    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            ll sum=0;

            for(int k=0; k<4; k++)
            {
                sum+=F[i][k]*M[k][j];

                sum%=mod;
            }

            sum%=mod;

            N[i][j] = sum;
        }
    }


    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
            F[i][j] = N[i][j];
    }
}

/*
 * function to calculate power of a matrix
 */
void power(ll F[4][4], int n)
{
    if (n == 0 || n == 1)
        return ;

    ll M[4][4];

    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
            M[i][j] = 0;

    M[0][0] = a;

    M[0][2] = b;

    M[0][3] = 1;

    M[1][0] = 1;

    M[2][1] = 1;

    M[3][3] = 1;

    power(F, n / 2);

    multiply(F, F);

    if (n % 2 != 0)
        multiply(F, M);
}

/*
 * function that returns nth Fibonacci number
 */
ll fibo_matrix(ll n)
{

    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
            F[i][j] = 0;

    F[0][0] = a;

    F[0][2] = b;

    F[0][3] = 1;

    F[1][0] = 1;

    F[2][1] = 1;

    F[3][3] = 1;

    power(F, n);

}

int main()
{
    cin>>test;

    for(int i=1; i<=test; i++)
    {

        cin>>n>>a>>b>>c;

        if(n<=2)
            cout<<"Case "<<i<<": 0"<<endl;

        else
        {
            fibo_matrix(n-2);

            cout<<"Case "<<i<<": "<<((F[0][3]*c)%mod)<<endl;
        }

    }

    return 0;
}
