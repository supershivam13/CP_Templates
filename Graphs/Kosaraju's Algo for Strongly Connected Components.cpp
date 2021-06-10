#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define endl '\n'

using namespace std;
// Adjacency list of original graph
vi ar[1001];

// Adjacency list of transposed graph
vi tr[1001];

// to store the order in which the second dfs is to be performed
vi order;

// to store the node of a SCC
vi SCC;

// visited array
int vis[1001];

// to store total number of SCC
int no_of_scc;


// first normal dfs to get the order of nodes int the increasing order of their OutTimes
void dfs(int node)
{
    vis[node] = 1;

    for (int child : ar[node])
        if (vis[child] == 0)
            dfs(child);

    order.pb(node);
}

// second dfs to call in the order of nodes given by the first dfs
void dfs1(int node)
{
    vis[node] = 1;

// for all the nodes in the adjacency list of transposed graph, if child node is unvisited then make a dfs call
    for (int child : tr[node])
        if (vis[child] == 0)
            dfs1(child);

// inserting the nodes in SCC to print
    SCC.pb(node);
}

// Main function
int main()
{

    int n , a , b , m , t;
    cin >> t;

    while (t--)
    {
        cin >> n >> m;

//  clearing the adjacency list of original and transposed graph, and visited array for multiple test cases
        REP(i , n) ar[i].clear() , tr[i].clear() , vis[i] = 0;

//  clearing the order vector for multiple test cases
        order.clear();


        REP(i , m)
        {
            cin >> a >> b;
            ar[a].pb(b);
            tr[b].pb(a);
        }

//  Normal first dfs calls to get the order of nodes in the increasing order of their OutTimes
        REP(i , n)
        if (vis[i] == 0) dfs(i);

//  clearing visited array for next dfs calls
        REP(i , n) vis[i] = 0;

//  starting the dfs calls from last of order to the beginning
        REP(i , n)
        if (vis[order[n - i]] == 0)
        {
            SCC.clear();
//    if unvisited, then make a dfs call
            dfs1(order[n - i]);


            cout << "dfs1() called from " << order[n - i] << " and printing SCC" << endl;
            for (int node : SCC)
                cout << node << " ";
            no_of_scc++;
            cout << endl;
        }


        cout << "Total number of SCCs are " << no_of_scc << endl;
    }
}


