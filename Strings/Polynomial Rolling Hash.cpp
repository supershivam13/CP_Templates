#include<bits/stdc++.h>
#define lli long long int
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
#define mod 1000000007
using namespace std;


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

int main()
{
    string key;
    cin >> key;

    cout << "Key : " << key << " Hash : " << getHash(key) << endl;
}
