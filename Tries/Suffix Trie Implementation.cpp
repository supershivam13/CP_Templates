// TRIES

// a) efficient information retrieval data structure
// b) searchs in optimal time O( word.length() ), but takes extra space for storage


// IMPORTANT -

// A Normal Trie is also called a Prefix Trie because it contains all the prefixes of a word as well.
// A Suffix Trie is a Trie in which we insert all the sufffixes of the word along with the full word { as full word is also a suffix }.


// Insertion in Suffix Trie - O( N*N ) { where n is the word length }
// Searching in Suffx Trie - O( N )



// Normal Trie ( Prefix Trie )
// Insertion in Trie - O( word.length() );
// Searching in Trie - O( word.length() )


// **********************************************************************************


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
const int SIZE  = 26;

#define all(v)          v.begin(),v.end()
#define sum(v)          accumulate(v.begin(),v.end(),(ll)0)
#define asum(a,n)       accumulate(a,a+n,(ll)0)
#define rev(v)          reverse(v.begin(),v.end());
//  stoi() function - converts string to integer ( Example- int x = stoi(s) )
//  stoll() funtion - converts string to long long ( Example- long long x = stoll(s) )
//  to_string() function - converts integer to string ( Example- string s = to_string(x) )


// structure of node ( changes as per the requirements )
struct node {
    bool isLeaf;
    node* ar[SIZE];
};


// Function to create a new node and return back its address
node* getNode()
{
    // creating a dynamically allocated new node
    node* n = new node;

    n->isLeaf = false;

    // initialising all the addresses in the arr array as NULL
    for (int i = 0; i < SIZE; i++)
        n->ar[i] = NULL;

    return n;
}


// Function to insert a word in Trie
void insert_helper(node *root , string st)
{
    // creating a copy of the main root node (as root node is the most important node of Trie)
    node *tempRoot = root;

    // inserting word character by character in Trie
    for (int i = 0; i < st.size(); i++)
    {
        int index = st[i] - 'a';

        // create new node if already not present
        if (tempRoot->ar[index] == NULL)
            tempRoot->ar[index] = getNode();

        // moving to the next node
        tempRoot = tempRoot->ar[index];
    }

    tempRoot->isLeaf = true;
}


// Inserting all the suffixes in the Suffix Trie
void insert(node *root , string st) {

    for (int i = 0; i < st.length(); i++)
        insert_helper(root, st.substr(i));

}

// Function to search whether string 'st' exists in Trie or not
bool getAns(node *root , string st)
{
    // creating a copy of the main root node (as root node is the most important node of Trie)
    node *tempRoot = root;

    for (int i = 0; i < st.size(); i++)
    {
        int index = st[i] - 'a';

        // if word is not present, simply return 0
        if (tempRoot->ar[index] == NULL)
            return false;

        tempRoot = tempRoot->ar[index];
    }

    return tempRoot->isLeaf;
}

int32_t main()
{
    // Creating the main root node of Suffix Trie
    node *root = getNode();

    int n , q , code;
    string st;

    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> st , insert(root , st);


    while (q--) {
        cin >> st;
        if (getAns(root , st))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;

}
