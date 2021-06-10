#include<bits/stdc++.h>
using namespace std;

// vector of pair<int,int> to store the graph edges and weight ( Adjacency list )
vector<pair<int, int> > adj[100001];

// to store the parent of nodes to print the MST
int parent[100001];

// to store the weights of the adjacent edges for nodes
int key[100001];

// to check whether a node is already a part of MST or not
bool mstSet[100001];


int main()
{
    // n = number of nodes, m = no. of edges
    int n, m;
    cin >> n >> m;


    int a, b, wt;
    for (int i = 0; i < m ; i++) {
        cin >> a >> b >> wt;
        adj[a].push_back({b, wt});
        adj[b].push_back({a, wt});
    }

    // initialising the values of key, parent and MSTset array for multiple test cases
    for (int i = 1; i <= n ; i++)
        key[i] = INT_MAX, mstSet[i] = false, parent[i] = -1;

    // Minheap to get the minimal weight edge among all the adjacent edges
    // stoing the values as { weight, node to which it is connected } ( weight is first so that priority
    // queue sorts on the basis of weights )
    priority_queue< pair<int, int>, vector <pair<int, int>> , greater<pair<int, int>> > pq;

    // to store the weight of MST
    int mstsum = 0;

    key[1] = 0;
    parent[1] = -1;
    pq.push({0, 1});


    // Run the loop till all the nodes have been visited
    while (!pq.empty())
    {
        int u = pq.top().second;
        int weigh = pq.top().first;
        pq.pop();

        // check whether the node u is already in MST
        if (mstSet[u] == false)
            mstsum += weigh;

        mstSet[u] = true;


        for (auto it : adj[u]) {

            // in Adjacency List, we stored as { node, weight}
            int v = it.first;
            int weight = it.second;

            if (mstSet[v] == false && weight < key[v]) {
                parent[v] = u;
                key[v] = weight;
                pq.push({weight, v});
            }
        }

    }

    cout << "The sum of the edges of MST is : " << mstsum << endl;

    for (int i = 1; i <= n; i++)
        cout << parent[i] << " -- " << i << " \n";
    return 0;
}

// Sample Test Case
// 6 7
// 1 2 5
// 1 3  10
// 1 4 100
// 2 4 50
// 2 5 200
// 4 5 250
// 5 6 50
