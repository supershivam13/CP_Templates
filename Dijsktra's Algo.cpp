#include<bits/stdc++.h>

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

const int mod   = 1000000007;
const int inf   = 100000000000000000;
#define all(v)          v.begin(),v.end()

using namespace std;


// DIJKSTRA'S Algorithm ( WORKS FOR BOTH DIRECTED AND UNDIRECTED GRAPHS )

// 1) Works only with Positive weight edges ( i.e it fails in case of negative edges
//    and negative weighted cycles )

// 2) Time Complexity - O( VlogE )

// to store the adjacency list as pairs { weight,node }
vector<pair<int, int>> v[100001];

// to store the distance of the nodes
int dist[100001];

// to store the parents of each node
int parent[100001];



int32_t main()
{
    int n , m, a , b , w;

    cin >> n >> m;

    // initialising the dist array with very large numbers
    fo(i, 1, n) {
        dist[i] = inf;
    }


    while (m--) {
        cin >> a >> b >> w;
        // storing as { weight , node (to which its get connected)}

        // Assuming undirected graph
        v[a].pb({w, b});
        v[b].pb({w, a});
    }

    // min heap for Dijkstra's Algorithm
    priority_queue < pair<int, int> , vector<pair<int, int>>, greater <pair<int, int>> > pq;

    // pair of weight , edge ( weight is given first place so that priority queue give the min element
    // everytime based on the value of weights )
    // push( { 0, root } )
    pq.push({0, 1});

    // assuming 1 is the source node, so distance of source node from source node is zero
    dist[1] = 0;


    while (!pq.empty()) {

        int curr_w = pq.top().first;
        int curr_node = pq.top().second;
        pq.pop();

        //This prevents outdated values to enter the for loop.
        if (curr_w != dist[curr_node])
            continue;

        // trying to minimise all the edges around the curr_node
        for (auto child : v[curr_node]) {


            if (curr_w + child.first < dist[child.second]) {
                dist[child.second] = curr_w + child.first;
                pq.push({dist[child.second], child.second});

                // storing the parent of each node for path printing
                parent[child.second] = curr_node;
            }
        }


    }

    // Printing the distance of each node from source ( dist array )
    fo(i, 1, n) {
        cout << dist[i] << " ";
    }

    cout << endl;

    // Path printing for the destination node ( Assuming dest to be n and source is 1 )
    int dest = n;
    int src = 1;

    // if the destination is unreachable from source node
    if (dist[n] == inf)
        cout << "-1" << endl;

    else {
        // vector to store the path
        vi path;

        while (dest != src) {
            path.pb(dest);
            dest = parent[dest];
        }
        path.pb(src);
        reverse(all(path));

        arrout(path, path.size());
    }


}
