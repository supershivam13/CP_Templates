#include<bits/stdc++.h>
#define lli long long int
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
#define mod 1000000007
using namespace std;


// p(31) is a prime number that reduces collisions.

// Example Calculation 
// For "abc": 'a' = 1, 'b' = 2, 'c' = 3 
// Hash = ( 1 × 31^0 ) + ( 2 × 31^1 ) + ( 3 × 31^2 ) mod(10^9 +7) 
//      = ( 1×31^0 )+( 2×31^1 )+( 3×31^2 )mod(10^9 +7)
//      = 1 + 62 + 2883 
//      = 1 + 62 + 2883 
//      = 2946

lli getHash(string key)
{
    lli ans = 0;

    // p should be >= |char set| ( p >= 26 )
    lli p = 31;  //p(31) is a prime number that reduces collisions.

    lli p_power = 1;   // as initially, p^0 = 1

    for (char ch : key)
    {
        // a = 1, b = 2, c = 3, etc.
        ans += (ch - 'a' + 1) * p_power) % mod;
        p_power = (p_power * p) % mod;
    }

    return value;
}

int main()
{
    string key;
    cin >> key;

    cout << "Key : " << key << " Hash : " << getHash(key) << endl;
}
