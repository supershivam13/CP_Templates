class Solution {
public:

    bool isBipartite(vector<vector<int>>&adj, vector<int>& visited, vector<int>& node_color, int node, int color){

        visited[node] = 1;
        node_color[node] = color;

        for(auto v : adj[node]){
            if(visited[v]==0){
                if(isBipartite(adj, visited, node_color, v, color^1) == false)
                    return false;
            }
            else if(node_color[node] == node_color[v])
                return false;
        }

        return true;
    }

    //SOLUTION starts here
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {

        vector<vector<int>> adj(n+1);   // using 1-based index
        vector<int> visited(n+1,0);
        vector<int> node_color(n+1,-1);

        for(auto dislike_pair : dislikes){
            adj[dislike_pair[0]].push_back(dislike_pair[1]);
            adj[dislike_pair[1]].push_back(dislike_pair[0]);
        }

        // Checking for all the nodes in given graph
        for(int i=1;i<=n;i++){
            if(visited[i]==0){
                if(isBipartite(adj, visited, node_color, i, 0) == false)
                    return false;
            }
        }

        return true;
    }
};
