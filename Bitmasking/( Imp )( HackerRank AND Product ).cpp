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

int32_t main()
{

    w(t) {

        int a, b;
        cin >> a >> b;

        if (a == b)
            cout << a << endl;
        else {

            // d is the number of elements in the range [a,b]
            int d = b - a + 1;
            int ans = 0;

            f(i, 32) {

                // for i-th bit, if d > 2^i, it means it is more than the 1(set-bit) pack,
                // and will be having atleast one zero bit, which will make the i-th bit zero in result as well
                // so no need to do anything in this case
                if (d > (1 << i))
                    continue;
                else {
                    // for i-th bit, if the range d lies completely in between the 1(set-bit) pack
                    // then the i-th bit will be 1 in the result
                    if ((a & (1 << i)) and (b & (1 << i)))
                        ans += (1 << i);
                }
            }
            cout << ans << endl;
        }
    }
}
