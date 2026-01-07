// FLOYD-WARSHALL ALGORITHM
// Time Complexity - O(V^3), Space Complexity - O(V^2)

// It’s a DP-based Multi Source Shortest Path (MSSP) algorithm.
// Works on Adjacency Matrix representation of graph.
// Use three nested for loops
// Time Complexity - O(V^3), Space Complexity - O(V^2)
// Works with cycles and negative edges, but fails when negative weighted cycles are present.


// Test for Negative-weighted Cycle
// After running Floyd–Warshall algorithm, if dist[i][i] < 0 for any vertex i, 
// then a negative cycle exists in the graph.

class Solution {
public:
    void floydWarshall(vector<vector<int>>& dist) {
        int n = dist.size();
        int INF = 1e8;

        // Floyd–Warshall Algorithm
        for (int k = 0; k < n; k++) {       // k is the middle 'via' node 
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    // Avoid overflow when adding INF (INF + INF will overflow)
                    if (dist[i][k] != INF && dist[k][j] != INF)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        
        return;
    }
};
