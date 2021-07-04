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
lli dp[1000001];
lli inv[1000001];

// Fast Exponentiation - O(log y)
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


lli getHash(string key)
{
    lli value = 0;

    // p should be >= |char set|
    lli p = 31;

    // as initially, p^0 = 1
    lli p_power = 1;

    for (char ch : key)
    {
        // a = 1, b = 2, c = 3, etc.
        value = (value + (ch - 'a' + 1) * p_power) % mod;
        p_power = (p_power * p) % mod;
    }

    return value;
}


// returns hash value of substring in O(1)
lli substringHash(int L , int R)
{
    int result = dp[R];

    if (L > 0) result = (result - dp[L - 1] + mod) % mod;

    result = (result * inv[L]) % mod;

    return result;
}



int main()
{
    string haystack , needle;
    int n , L , R , answer;

    // since no. of test cases is not given, so running a while until there is some input
    while (cin >> n)
    {
        // input needle string and haystack string
        cin >> needle;
        cin >> haystack;

        // Gettin the hash value of the needle
        lli needleHash = getHash(needle);

        // PREPROCESSING ( O(NlogN) )
        init(haystack);

        // Sliding window technique ( window of size needle.length() ) with Hash value to compare in O(1)
        for (L = 0 , R = needle.size() - 1; R < haystack.size(); L++ , R++)
        {
            if (needleHash == substringHash(L , R))
                cout << L << endl;
        }

        cout << endl;
    }
}

