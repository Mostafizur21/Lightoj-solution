#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct matrix
{
    ll F[6][6];

    int row, col;
};

ll mod,a1,b1,c1,a2,b2,c2,f[3],g[3];

// multiplies two matrices and returns the result
matrix multiply(matrix a, matrix b)
{

    matrix r;

    r.row = a.row;

    r.col = b.col;

    for (int i = 0; i < r.row; i++)
    {
        for (int j = 0; j < r.col; j++)
        {
            ll sum = 0;

            for (int k = 0; k < a.col;  k++)
            {
                sum += a.F[i][k] * b.F[k][j];

                sum %= mod;
            }

            r.F[i][j] = sum;
        }
    }

    return r;
}

// returns mat^p
matrix power(matrix mat, int p)
{

    if (p == 1)
        return mat;

    if (p % 2 == 1)

        return multiply(mat, power(mat, p - 1));

    matrix ret = power(mat, p / 2);

    ret = multiply(ret, ret);

    return ret;
}

int main()
{
    int tcase;

    cin >> tcase;

    for(int i=1; i<=tcase; i++)
    {
        cin>>a1>>b1>>c1;

        cin>>a2>>b2>>c2;

        for(int j=0; j<3; j++)
            cin>>f[j];

        for(int j=0; j<3; j++)
            cin>>g[j];

        cin>>mod;

        a1=a1%mod;

        b1=b1%mod;

        c1=c1%mod;

        a2=a2%mod;

        b2=b2%mod;

        c2=c2%mod;

        int mul_matrix[6];

        mul_matrix[0] = f[2];

        mul_matrix[1] = f[1];

        mul_matrix[2] = f[0];

        mul_matrix[3] = g[2];

        mul_matrix[4] = g[1];

        mul_matrix[5] = g[0];


        matrix mat;

        mat.row = mat.col = 6;

        for(int k=0; k<6; k++)
            mul_matrix[k] = mul_matrix[k]%mod;

        int queries,q;

        cin>>queries;

        printf("Case %d:\n", i);

        while(queries--)
        {
            cin>>q;

            if(q<=2)
                cout<<f[q]%mod<<" "<<g[q]%mod<<endl;

            else
            {

                for(int i=0; i<6; i++)
                    for(int j=0; j<6; j++)
                        mat.F[i][j] = 0;

                mat.F[0][0] = a1;

                mat.F[0][1] = b1;

                mat.F[0][5] = c1;

                mat.F[1][0] = 1;

                mat.F[2][1] = 1;

                mat.F[3][2] = c2;

                mat.F[3][3] = a2;

                mat.F[3][4] = b2;

                mat.F[4][3] = 1;

                mat.F[5][4] = 1;

                mat = power(mat,q-2);

                ll ans=0,ans2=0;

                for(int j=0; j<6; j++)
                {
                    ans = (ans+(mat.F[0][j]*mul_matrix[j]))%mod;

                    ans2 = (ans2+(mat.F[3][j]*mul_matrix[j]))%mod;
                }

                cout<<ans<<" "<<ans2<<endl;

            }
        }

    }

    return 0;
}
