class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        
        // Step 1: Build adjacency list from edge list 
        vector<vector<vector<int>>> adj(V);     // Weighted Graph
        for (auto e : edges) {  
            int u = e[0], v = e[1], w = e[2];
            
            // Since graph is undirected, need to add both forward and backward edges
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});   
        }       

        // Step 2: Distance array
        vector<int> distance(V, INT_MAX);

        // Step 3: Min-heap priority queue {distance, node}
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;

        // Step 4: Initialize source
        pq.push({0, src});
        distance[src] = 0;

        // Step 5: Dijkstra's Algorithm
        while (pq.size() > 0) {

            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // Skip outdated entries of Priority Queue (edge is alreay relaxed)
            if (dist > distance[node])
                continue;

            // Relax all adjacent edges
            for (auto edge : adj[node]) {
                int adjNode = edge[0];
                int weight = edge[1];
                
                // distance[v] > distance[u] + edge(u,v)
                if (distance[adjNode] > distance[node] + weight) {
                    distance[adjNode] = distance[node] + weight;
                    pq.push({distance[adjNode], adjNode});
                }
            }
        }

        return distance;
    }
};
