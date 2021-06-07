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
const int lim   = 100005;

#define all(v)          v.begin(),v.end()
#define sum(v)          accumulate(v.begin(),v.end(),(ll)0)
#define asum(a,n)       accumulate(a,a+n,(ll)0)
#define rev(v)          reverse(v.begin(),v.end());
//  stoi() function - converts string to integer ( Example- int x = stoi(s) )
//  stoll() funtion - converts string to long long ( Example- long long x = stoll(s) )
//  to_string() function - converts integer to string ( Example- string s = to_string(x) )


// Returns 2 powered n number less than or equal to a
int two_power_n_less_equal(int a) {
    int ans = 1;
    while (1)
    {
        if (ans * 2 > a)
            break;
        ans *= 2;
    }
    return ans;
}

// Returns 2 powered n number less than or equal to a
int two_power_n_less_equal_log_method(int a) {
    int l = log(a) / log(2);
    int ans = pow(2, l);
    return ans;
}

// log_a_to_base_b
double logab (int a, int b)
{
    return log(a) / log(b);
}

// Fast Exponentiation - O(log y)
int fpow( int x, int y) {
    int temp;
    if (y == 0)
        return 1;
    temp = fpow(x, y / 2);
    if (y % 2 == 0)
        return (temp * temp) % mod;
    else
        return (x * ( (temp * temp) % mod ) ) % mod;
}

// HCF of two numbers a and b - O(log max(a, b))
int gcd(int a, int b) {
    if (b == 0)return a;
    return gcd(b, a % b);
}

// Returns bool whether n is prime or not - O(sqrt(n))
bool isPrime(int n) {
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}


int modInv(int n, int mod) {
    return fpow(n, mod - 2);
}

// Returns a map with (prime factor, power raised) as key value pairs - O( logn * sqrt(n) )
// Example for 60, it returns a map with { (2,2) , (3,1) , (5,1) }
map<int, int> primeFactors(int n)
{
    map<int, int> mp;
    while (n % 2 == 0)
    {
        if (mp.count(2) == 1)
            mp[2]++;
        else
            mp.insert({2, 1});
        n = n / 2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            if (mp.count(i) == 1)
                mp[i]++;
            else
                mp.insert({i, 1});
            n = n / i;
        }
    }
    if (n > 2)
    {
        if (mp.count(n) == 1)
            mp[n]++;
        else
            mp.insert({n, 1});
    }
    return mp;
}


// Return a binary string of integer a of length 31
string DecimalToBinaryString(int a)
{
    string binary = "";
    int mask = 1;
    for (int i = 0; i < 31; i++)
    {
        if ((mask & a) >= 1)
            binary = "1" + binary;
        else
            binary = "0" + binary;
        mask <<= 1;
    }
    // cout<<binary<<endl;
    return binary;
}

// Returns decimal value of a binary integer
int binaryIntegerToDecimal(int n)
{
    int num = n;
    int dec_value = 0;
    int base = 1;

    int temp = num;
    while (temp) {
        int last_digit = temp % 10;
        temp = temp / 10;
        dec_value += last_digit * base;
        base = base * 2;
    }

    return dec_value;
}

// Function to find factorial of a number n -  O(n)
int factorial( int n)
{
    if (n == 0 or n == 1)
        return 1;
    return n * factorial(n - 1);
}

// Initialized globally the factorial array for nCr function
// const int N1 = 1000001;
// int fac[N1];

// Return the nCr value with  factorial array- O( n )
// int nCr(int n, int r, int mod){

//     if(r == 0)
//         return 1;
//     return (fac[n] * modInverse(fac[r], mod) % mod * modInverse(fac[n - r], mod) % mod) % mod;
// }


void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

// to store edges and weigths as pair
vector < pair < pair<int, int>, int> > v;

// to store the distance of the nodes
int dist[100001];



int32_t main()
{

    fio;

    int n , m, a , b , w;

    // n = no. of nodes, m = no. of edges
    cin >> n >> m;

    // initialising the dist array with very large numbers
    fo(i, 1, n) {
        dist[i] = INT_MAX;
    }


    while (m--) {
        cin >> a >> b >> w;
        // storing as { {edge}, weight }
        v.pb( { {a, b}, w} );
    }

    // Assuming source node to be 1, so distance of source from source node is zero
    dist[1] = 0;

    // n-1 phases of Bellman Ford Algorithm
    for (int i = 0; i < n - 1; i++) {

        // iterating over the edge list
        for (int j = 0; j < v.size(); j++) {


            if (dist[v[j].first.first] < INT_MAX)
                dist[v[j].first.second] = min(dist[v[j].first.second], dist[v[j].first.first] + v[j].second);

            // This is for DIRECTED GRAPHS only.
            // To make it for undirected graph, just uncomment the below if statement.

            // if (dist[v[j].first.second] < INT_MAX)
            //     dist[v[j].first.first] = min(dist[v[j].first.first], dist[v[j].first.second] + v[j].second);

        }
    }

    // Printing the distance of each node from source node
    fo(i, 1, n) {
        if (dist[i] == INT_MAX)
            cout << "INF" << endl;
        else
            cout << dist[i] << endl;
    }





}
