/* Dynamic Programming C++ implementation
of LIS problem */
#include <bits/stdc++.h>
using namespace std;

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


// LONGEST INCREASING SUBSEQUENCE WITH PRINTING

// TIME COMPLEXITY - O( N^2 )
// SPACE COMPLEXITY - O( N )


int a[1001];


// LIS() returns the vector containing LIS of the array a[] of size n
vector<int> LIS(int n)
{
    // LIS array to store the length LIS found till now
    int lis[n];

    // Initialising the LIS array with as each element is a LIS in itself
    f(i, n)
    lis[i] = 1;

    // Compute optimized LIS values in bottom up manner

    // first loop covers all the elements of the array
    for (int i = 1; i < n; i++) {
        // second loop checks for previous elemens of a[i] to get the max value of LIS by including a[i]
        for (int j = 0; j < i; j++)

            // if prev element is smaller and including it will increase the LIS obtained till now
            if (a[i] > a[j] and lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
    }

    // Getting the maximum value of LIS from the lis array ( FINAL RESULT )
    int max_lis = *max_element(lis, lis + n);



    // NOW,PRINTING ONE OF THE (ONE OR MANY POSSIBLE) SUCH LIS

    int lis_ind = 0;

    // Finding the index at which LIS length occurs
    for (int i = n - 1; i >= 0; i--) {
        if (lis[i] == max_lis ) {
            lis_ind = i;
            break;
        }
    }

    vector<int> result;

    // pushing the element at the index where the LIS is obtained
    result.pb(a[lis_ind]);

    for (int i = lis_ind - 1; i >= 0; i--) {

        // checking the index where 1 length shorter LIS value is found and if a[i]<a[lis_ind],
        // and updating the value of lis_ind to index where 1 length shorter LIS value is found
        if (lis[i] == lis[lis_ind] - 1 and a[i] < a[lis_ind]) {
            lis_ind = i;
            result.pb(a[lis_ind]);
        }
    }

    reverse(all(result));

    return result;

}

void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}



int32_t main()
{

    fio;

    c_p_c();

    int n;
    cin >> n;

    arrin(a, n);

    vector<int> ans = LIS(n);
    cout << "Length of the Longest Increaasing Subsequence is " << ans.size() << endl;
    arrout(ans, ans.size());

    return 0;
}
