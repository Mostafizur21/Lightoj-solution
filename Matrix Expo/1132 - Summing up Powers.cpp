//(1^K + 2^K + 3^K + ... + N^K) % 2^32
#include<bits/stdc++.h>
#define ll long long
#define mod 4294967296
#define maxN 55

using namespace std;

ll c[maxN][maxN];

int siz;

struct matrix
{
    unsigned int F[maxN][maxN];
};


// multiplies two matrices and returns the result
matrix multiply(matrix a, matrix b)
{

    matrix r;

    for (int i = 0; i < siz; i++)
    {
        for (int j = 0; j < siz; j++)
        {
            ll sum = 0;

            for (int k = 0; k < siz;  k++)
            {
                sum += a.F[i][k] * b.F[k][j];

                sum%=mod;

            }

            r.F[i][j] = sum;
        }
    }

    return r;
}

// returns mat^p
matrix power(matrix mat, ll p)
{
    if (p == 1)
        return mat;

    if (p % 2 == 1)

        return multiply(mat, power(mat, p - 1));

    matrix ret = power(mat, p / 2);

    ret = multiply(ret, ret);

    return ret;
}


void pascal()
{
    for(int i=0; i<maxN; i++)
    {
        c[i][0] = c[i][i] = 1;

        for(int j=1; j<=i-1; j++)
            c[i][j] = c[i-1][j-1]+c[i-1][j];
    }
}

int main()
{

    pascal();

    ll n;

    int test,k;

    scanf("%d",&test);

    for(int t = 1; t<=test; t++)
    {
        scanf("%lld %d",&n,&k);

        siz = k+2;

        ll result = 1;

        if(n>1)
        {

            matrix base;

            for(int i=0; i<siz; i++)
            {
                for(int j=0; j<siz; j++)
                    base.F[i][j] = 0;
            }



            for(int i=0; i<=k; i++)
            {
                for(int j=0; j<=i; j++)
                {
                    base.F[i][j] = c[i][j];
                }
            }

            for(int j=0; j<=k; j++)
                base.F[siz-1][j] = c[k][j];

            base.F[siz-1][siz-1] = 1;

            base = power(base,n-1);

            result = 0;

            for(int j=0; j<siz; j++)
                result=(result+base.F[siz-1][j])%mod;

        }

        cout<<"Case "<<t<<": "<<result<<endl;

    }

    return 0;
}

