#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000
#define endl '\n'
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;

using namespace std;
lli ar[100001];

int main()
{
    lli t , n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        REP(i , n) cin >> ar[i];

        lli cnt;
        lli res = 0;


        for (lli i = 1; i <= n; i++)
        {
            // COUNTING NUMBER OF SUBARRAYS IN WHICH I-TH ELEMENT APPEARS (1-BASED INDEX)
            cnt = (i) * (n - i + 1);

            // if any element appears odd time(property of XOR operator) , only then it will be taken in result
            if (cnt % 2) res ^= ar[i];
        }

        cout << res << endl;
    }
}
