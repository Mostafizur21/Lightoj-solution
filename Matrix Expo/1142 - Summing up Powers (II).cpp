//m+m^2+m^3+m^3+.........+m^p
#include<bits/stdc++.h>
#define mod 10
#define maxN 35
#define ll long long

using namespace std;

int siz;

struct matrix
{
    ll F[maxN][maxN];
} I;


void print(matrix base)
{
    for(int i=0; i<siz; i++)
    {
        for(int j=0; j<siz; j++)
        {
            printf("%lld",base.F[i][j]);
        }

        printf("\n");
    }
}

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


matrix addition(matrix a, matrix b)
{

    for (int i = 0; i < siz; i++)
    {
        for (int j = 0; j < siz; j++)
        {

            a.F[i][j]+=b.F[i][j];

            a.F[i][j]%=mod;
        }
    }

    return a;
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


matrix sum(matrix mat,ll p)
{
    if(p==1)
        return mat;

    if(p%2==1)
    {
        matrix tmp = sum(mat,p-1);

        matrix mul = multiply(mat,tmp);

        return addition(mat,mul);

    }

    else
    {
        matrix temp = sum(mat,p/2);

        matrix POW = power(mat,p/2);

        matrix add = addition(POW,I);

        return multiply(add,temp);

    }
}

int main()
{

    ll test,n,k,x;

    scanf("%lld",&test);

    for(int t=1; t<=test; t++)
    {
        scanf("%lld %lld",&n,&k);

        siz = n;

        matrix base;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==j)
                    I.F[i][j] = 1;

                else
                    I.F[i][j] = 0;
            }
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                scanf("%lld",&x);

                base.F[i][j] = x%mod;
            }
        }

        base = sum(base,k);

        printf("Case %d:\n",t);

        print(base);

    }

    return 0;
}
