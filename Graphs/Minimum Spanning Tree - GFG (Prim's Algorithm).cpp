class Solution {
public:
    int spanningTree(int V, vector<vector<int>>& edges) {

        // Step 1:  Build adjacency list --> (node -> {neighbor, weight})
        vector<vector<pair<int,int>>> adj(V);
        for (auto e : edges) {
            int u = e[0], v = e[1], wt = e[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        // Step 2: Visited array
        vector<int> visited(V, 0);
        
         // Step 3: Min-heap priority queue {distance, node}
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        // // Step 4: Initialize with node 0 (any node works if graph is connected)
        pq.push({0, 0});
        int mstWeight = 0;
        
        // Step 5: Prim's Algorithm
        while (pq.size() > 0) {
            auto [wt, node] = pq.top();
            pq.pop();

            if (visited[node] == 1) 
                continue;

            visited[node] = 1;
            mstWeight += wt;

            for (auto edge : adj[node]) {
                int nextNode = edge.first;
                int nextWt   = edge.second;

                if (visited[nextNode] == 0) 
                    pq.push({nextWt, nextNode});
            }
        }

        return mstWeight;
    }
};
