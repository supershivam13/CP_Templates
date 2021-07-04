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

// to store the pre calculated hash of whole string
lli dp[1000001];

// to store the modulo invese of p^i at the i-th index
lli inv[1000001];

// Fast-Exponentiation
lli fpow( int x, int y) {
    lli temp;
    if (y == 0)
        return 1;
    temp = fpow(x, y / 2);
    if (y % 2 == 0)
        return (temp * temp) % mod;
    else
        return (x * ( (temp * temp) % mod ) ) % mod;
}


// Pre-processing the hash values of the string and the modulo inverses of p^i is getting in the inv array
void init(string input_string)
{
    lli p = 31;

    // as initially p^0 = 1
    lli p_power = 1;

    inv[0] = 1;
    dp[0] = (input_string[0] - 'a' + 1);


    for (int i = 1; i < input_string.size(); i++)
    {
        char ch = input_string[i];

        p_power = (p_power * p) % mod;
        inv[i] = fpow(p_power , mod - 2);

        dp[i] = (dp[i - 1] + (ch - 'a' + 1) * p_power) % mod;
    }
}

// Getting the hash value of substring in O(1)
lli substringHash(int L , int R)
{
    int result = dp[R];

    if (L > 0) result -= dp[L - 1];

    result = (result * inv[L]) % mod;

    return result;
}

int main()
{
    string input_string;
    int tc , L , R;

    cin >> input_string;

    // preprocessing in O( NlogN )
    init(input_string);

    // number of test cases
    cin >> tc;

    REP(i , tc)
    {
        // L, R are 0-based indexed
        cin >> L >> R;
        // Hash value of substring in O(1)
        cout << substringHash(L , R) << endl;
    }
}

