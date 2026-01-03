// 1) Bellman-Ford is a DP algorithm.
// 2) Works on the Edges List.
// 3) Performs edge relaxation on all the edges for N - 1 times.
// 4) Time Complexity - O(V * E)

// NOTE: Test for Negative-weighted Cycle
// Perform edge relaxation on all the edges for N - 1 times. If an edge can be relaxed 
// in the N-th iteration as well, it indicates the presence of a negative weight cycle


class Solution {
public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        
        // Step 1: Distance array & initialise source
        // GFG requires unreachable nodes = 1e8
        vector<int> distance(V, 100000000);
        distance[src] = 0;
        
        // Step 2: Bellman-Ford Algorithm
        // Relax all edges for V-1 times
        for (int i = 0; i < V - 1; i++) {
            for (auto e : edges) {
                int u = e[0], v = e[1], w = e[2];

                if (distance[u] != 100000000 && distance[v] > distance[u] + w)
                    distance[v] = distance[u] + w;
            }
        }
        
        // Step 3: Negative cycle detection (mandatory in GFG)
        // Nth phase checks for a negative cycle: If any distance can still be relaxed after
        // n−1 phases, the graph contains a negative-weight cycle.
        for (auto e : edges) {
            int u = e[0], v = e[1], w = e[2];

            if (distance[u] != 100000000 && distance[v] > distance[u] + w) {
                return {-1};
            }
        }

        return distance;
    }
};
