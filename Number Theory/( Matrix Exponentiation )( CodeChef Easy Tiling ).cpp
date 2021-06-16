/*
    Author      : SHIVAM SAHU
    Institution : IIT PATNA
    Country     : INDIA
*/

#include<bits/stdc++.h>
using namespace std;

#define int             long long

#define f(i,n)          for(int i=0;i<n;i++)
#define F(i,a,n)        for(int i=a;i<n;i++)
#define fo(i,a,b)       for(int i=a;i<=b;i++)
#define arrin(a,n)      for(int i=0;i<n;i++)cin>>a[i]
#define arrout(a,n)     for(int i=0;i<n;i++)cout<<a[i]<<" "
#define print2d(a,n,m)  for(int i=0;i<n;i++){for(int j=0;j<m;j++)cout<<a[i][j]<<" ";cout<<"\n";}
#define w(x)            int x; cin>>x; while(x--)

const int mod   = 1000000007;
const int lim   = 1000006;    // lim = 10^6 + 6

// Input matrix
int a[101][101];

// Identity Matrix
int id[101][101];

// Transition matrix
int trans[101][101];
const int N = 101;

// Function for matrix multiplication
void matmul(int A[][101], int B[][101], int m) {

    // Matrix for storing the product result of two matrix
    int res[m + 1][m + 1];

    fo(i, 1, m) {
        fo(j, 1, m) {
            res[i][j] = 0;
            fo(k, 1, m) {
                int tmp = (A[i][k] * B[k][j]) % mod;
                res[i][j] = (res[i][j] + tmp) % mod;
            }
        }
    }

    // Copying the results
    fo(i, 1, m) {
        fo(j, 1, m) {
            A[i][j] = res[i][j];
        }
    }
}

int getfib(int n, int a, int b) {

    // Transition matrix for fibonacci series is [[0,1],[1,1]]
    trans[1][1] = 0;
    trans[2][2] = trans[1][2] = trans[2][1] = 1;

    // Identity matrix ( matrix in which the final results get stored )
    id[1][1] = id[2][2] = 1;
    id[2][1] = id[1][2] = 0;

    // coz we have to calculate n-1 th power of the transition matrix
    n--;

    while (n) {
        if (n % 2 == 1) {
            matmul(id, trans, 2);
            n--;
        }
        else {
            n /= 2;
            matmul(trans, trans, 2);
        }
    }

    int ans = (a * id[1][1] + b * id[2][1]) % mod;

    return ans;
}

int32_t main()
{

    w(t) {
        int n, a, b;
        a=1;
        b=2;
        cin >>  n;

        if (n == 1)
            cout << a % mod << endl;
        else if (n == 2)
            cout << b % mod << endl;
        else
            cout << getfib(n, a, b) << endl;

    }
}
