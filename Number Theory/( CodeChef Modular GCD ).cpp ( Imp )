/*
    Author      : SHIVAM SAHU
    Institution : IIT PATNA
    Country     : INDIA
*/

#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;

// PRAGMA reduces execution time a little
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("O3")
#pragma GCC target ("avx")

// The typedef is used to give data type a new name
// #define in C is a directive which is used to #define alias(shortcuts)
typedef long long ll;
typedef long double ld;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

#define f(i,n)          for(int i=0;i<n;i++)
#define F(i,a,n)        for(int i=a;i<n;i++)
#define fo(i,a,b)       for(int i=a;i<=b;i++)
#define arrin(a,n)      for(int i=0;i<n;i++)cin>>a[i]
#define arrout(a,n)     for(int i=0;i<n;i++)cout<<a[i]<<" "
#define print2d(a,n,m)  for(int i=0;i<n;i++){for(int j=0;j<m;j++)cout<<a[i][j]<<" ";cout<<"\n";}
#define w(x)            int x; cin>>x; while(x--)

#define ff              first
#define ss              second
#define int             long long
#define double          long double
#define eb              emplace_back
#define pb              push_back
#define pf              push_front
#define popb            pop_back
#define popf            pop_front
#define mp              make_pair
#define rt              return
#define br              break
#define ct              continue
#define elif            else if

#define dbg             cout<<"\nhuehue\n"
#define sayy            cout<<"YES\n"
#define sayn            cout<<"NO\n"
#define debug(a)        cerr << #a << ": " << a << endl


#define pii             pair<int,int>  // ( p.first , p.second )
#define pss             pair<string,string>

#define mii             map<int,int> // ( insert(key,value), begin(), end(), size(), empty() )
#define mci             map<char, int>
#define msi             map<string, int>
#define mss             map<string, string>
#define umii            unordered_map<int,int>
// Itertating over a map m ==>> for( auto i : m ){ cout<<i.first<<" "<<i.second<<endl; }

#define vi              vector<int>  // ( size(), resize(), begin(), end(), empty() )
#define vb              vector<bool>
#define vii             vector<pair<int,int>>
#define vvi             vector<vector<int>>

#define si              set<int>  // stores in ascending order // ( insert(), size(), empty(), begin(), end() )
#define sid             set<int, greater<int> >  // stores in descending order
#define sii             set<pair<int,int>>

#define li              list <int> // ( pb(), pf(), popb(), popf(), reverse(), sort(), empty(), size(),
//  remove(), front(), back() insert() )

#define maxheap         priority_queue<int>  // by default, max heap ( push(), pop(), top(), empty(), size() )
#define minheap         priority_queue<int,vi,greater<int>>  // min heap ( push(), pop(), top(), empty(), size() )


#define setbits(x)      __builtin_popcountll(x) // return the count of set bits
#define startzeroes(x)  __builtin_clzll(x) //return the count the leading zeros of the integer(clz=count leading zero’s)
#define endzeroes(x)    __builtin_ctzll(x) // used to count the trailing zeros of the given integer(ctz = count trailing zeros)

#define ps(x,y)         fixed<<setprecision(y)<<x  // (always prefer double) works with float and double..ps(x,y)=x with y digits after decimal
#define dma(a,n,type)   type *a=new type[n];  // dynamic memory allocation (Example : type*a = new int[n]; )

const int inf   = numeric_limits<int>::max();
const double pi = 3.1415926535898;
const int mod   = 1000000007;
const int lim   = 1000006;    // lim = 10^6 + 6

#define all(v)          v.begin(),v.end()
#define sum(v)          accumulate(v.begin(),v.end(),(ll)0)
#define asum(a,n)       accumulate(a,a+n,(ll)0)
#define rev(v)          reverse(v.begin(),v.end());
//  stoi() function - converts string to integer ( Example- int x = stoi(s) )
//  stoll() funtion - converts string to long long ( Example- long long x = stoll(s) )
//  to_string() function - converts integer to string ( Example- string s = to_string(x) )


// CONCEPT -
// Instead of calculating (a^n + b^n) and finding the gcd,
// Since gcd is the greatest common divisor of both the numbers,
// we are finding the potential candidates for final answer using the second number(a-b)
// and then, finding the largest of them which completely divides (a^n+b^n)

// Since (a-b) can be upto maximum of 10^12, all its divisors(potential candidates) can be found
// in O(sqrt(n))...i.e within 10^6




// Fast Exponentiation - O(log n) modulo m
int fpow2(int a, int n, int m) {

    int res = 1;

    while (n) {
        if (n % 2 == 1) {
            res = ((res % m) * (a % m)) % m;
            n--;
        }
        else {
            a = ((a % m) * (a % m)) % m;
            n /= 2;
        }
    }

    return res % m;
}



int result(int a, int b, int n) {

    // if a==b, then result = gcd(a^n + b^n, a-b) = gcd(a^n + b^n,0) = (a^n + b^n)
    if (a == b)
        return (fpow2(a, n, mod) + fpow2(b, n, mod)) % mod;

    // Second number
    int num = a - b;

    // potential candidate initially
    int ans = 1;

    for (int i = 1; i * i <= num; i++) {

        // if num is divisble by i, only then check for the divisibility of (a^n + b^n)
        if (num % i == 0) {

            // calculating a^n modulo i and b^n modulo i, then adding both under modulo i
            int tmp = (fpow2(a, n, i) + fpow2(b, n, i)) % i;

            // if tmp==0, then (a^n + b^n) is divisible by i
            if (tmp == 0)
                ans = max(ans, i);

            // if num is divisible by i, then num is also divisble by (num/i),
            // so checking for (num/i) also

            tmp = (fpow2(a, n, num / i) + fpow2(b, n, num / i)) % (num / i);

            // if tmp==0, then (a^n + b^n) is divisible by i
            if (tmp == 0)
                ans = max(ans, num / i);

        }

    }

    return ans % mod;
}


int32_t main()
{
    fio;

    w(t) {

        int a, b, n;
        cin >> a >> b >> n;

        cout << result(a, b, n) << endl;
    }
}




