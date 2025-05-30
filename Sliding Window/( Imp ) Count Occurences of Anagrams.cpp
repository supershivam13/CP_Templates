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


void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

// PROCEDURE -

// 1) Generate a map of all character occurences of the 2nd string, i.e char and its count.

// 2) The window size becomes the length of 2nd string, as the anangrams wil also be of this
// length, and another variable 'count' denotes the distinct characters left in a sliding window.

// 3) In a window if the current character is present in map, then decrease its count, and
// if the count becomes 0, decrease the 'count' variable.

// 4) If the 'count' variable is 0, it means all the characters needed for its anagram is here in it,
// therefore increase your answer

// 5) To remove the last part (arr[i] part) so that the window can be shifted ->
// If the s[i] is present in map then increase its count and if it changes from 0->1
// then increase the 'count' variable


// Given a string, and another string, find count of occurances of all anagrams of 2nd one in 1st one.

// Input : "forxxorfxdofr", "for"
// Output : 3
// Explanation : Anagrams of the word for - for, orf, ofr appear in the text and hence the output is 3.


// Time Complexity : O(n)
// Space Complexity : O( no. of distinct chars in second(pattern) string)


int a[100001];

int32_t main()
{
    fio;
    c_p_c();

    string s, pat;
    cin >> s >> pat;

    // map of all character occurences of the pat string, i.e char and its count.
    unordered_map<char, int> m;
    for (auto it : pat) m[it]++;

    // variable 'count' denotes the distinct characters left in a sliding window.
    int count = m.size();

    // k = window size
    int k = pat.length();
    int n = s.length();
    int ans = 0;


    // Pre-processing of first window of size K
    for (int i = 0; i < k; i++) {

        if (m.find(s[i]) != m.end()) {
            m[s[i]]--;

            // when the no. of occurence of a character becomes zero, so number of distinct
            // characters also decrease by 1
            if (m[s[i]] == 0)
                count--;
        }
    }

    // SLIDING WINDOW TECHNIQUE
    for (int i = 0; i <= n - k; i++) {

        // case of first window of size K
        if (i == 0) {

            // If the count is 0, it means all the characters needed for its anagram is here in it,
            // therefore increase your answer
            if (count == 0)
                ans++;
        }

        // for subsequent windows of size k ( except the first window )
        else {

            // Remember i is already incremented by the for loop

            // processing the newly added element in the window
            if (m.find(s[i + k - 1]) != m.end()) {
                m[s[i + k - 1]]--;

                // if changes from 1->0, then it indicates that character is present in required quantity
                if (m[s[i + k - 1]] == 0)
                    count--;
            }

            // processing the recently removed element from the window
            if (m.find(s[i - 1]) != m.end()) {
                m[s[i - 1]]++;

                // if changes from 0->1
                if (m[s[i - 1]] == 1)
                    count++;
            }

            // NOW PRE-PROCESSING IS DONE, CALCULATING THE ANS FROM THE WINDOW
            if (count == 0)
                ans++;
        }
    }

    cout << ans << endl;

}
