class Solution {
  public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& component) {
        visited[node] = true;
        component.push_back(node);

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited, component);
            }
        }
    }

    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);  // Undirected graph
        }

        vector<bool> visited(V, false);
        vector<vector<int>> components;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                vector<int> component;
                dfs(i, adj, visited, component);
                components.push_back(component);
            }
        }

        return components;
    }
};
