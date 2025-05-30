/* Dynamic Programming C++ implementation
of LIS problem */
#include <bits/stdc++.h>
using namespace std;

#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

#define f(i,n)          for(int i=0;i<n;i++)
#define F(i,a,n)        for(int i=a;i<n;i++)
#define fo(i,a,b)       for(int i=a;i<=b;i++)
#define arrin(a,n)      for(int i=0;i<n;i++)cin>>a[i]
#define arrout(a,n)     for(int i=0;i<n;i++)cout<<a[i]<<" "<<i<<"\n"
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


int32_t main()
{
    fio;

    // to store the frequencies of different arrangements of vowels in given strings
    // (i.e if 0th bit is set, then a is present, 1th bit is set, then e is present, and so on )
    // ( since 5 characters are present only, so 2^5 ways possible )
    int freq[32];
    w(t) {

        int n;
        cin >> n;
        string s;

        // initializing the freq array with 0
        f(i, 32)
        freq[i] = 0;

        f(i, n) {
            cin >> s;

            // making a mask to identify the characters present in the string
            // if string has all characters present, then mask will be 11111 (i.e 31)
            int mask = 0;

            for (auto ch : s) {
                if (ch == 'a')  mask = mask | (1 << 0);
                if (ch == 'e')  mask = mask | (1 << 1);
                if (ch == 'i')  mask = mask | (1 << 2);
                if (ch == 'o')  mask = mask | (1 << 3);
                if (ch == 'u')  mask = mask | (1 << 4);
            }

            freq[mask]++;
        }

        int result = 0;

        // starting from 1 as freq[0] = 0 as each string has atleast 1 character
        for (int i = 1; i < 32; i++) {
            for (int j = i + 1; j < 32; j++) {
                // if i|j together makes up 31, then it means there strings on combining will be
                // having all the five vowels, so adding to our result number of such pairs possible
                if ((i | j) == 31 and freq[i] != 0 and freq[j] != 0) {
                    result += (freq[i] * freq[j]);
                }

            }
        }
        
        // strings which already has all five vowels present can make pairs among themselves as well
        // so nC2 = ( n*(n-1) )/2
        result += ((freq[31] * (freq[31] - 1)) / 2);

        cout << result << endl;

    }
}
