class Solution {
public:

    bool isBipartite(vector<vector<int>>&adj, vector<int>& visited, vector<int>& node_color, int node, int color){

        visited[node] = 1;
        node_color[node] = color;        // marking the color of node

        for(auto v : adj[node]){
            if(visited[v]==0){            // check only if 'v' is unvisited
                if(isBipartite(adj, visited, node_color, v, color^1) == false)      // if Recursive call returned false, then return false
                    return false;
            }
            else if(node_color[node] == node_color[v])            // if color of child and parent is same, then not possible to bi-partite graph
                return false;
        }

        return true;
    }

    //SOLUTION starts here
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {

        vector<vector<int>> adj(n+1);    // using 1-based index
        vector<int> visited(n+1,0);      // visited array
        vector<int> node_color(n+1,-1);  // color array to keep track of colors of node (either 0 or 1) {initialised with -1}

        for(auto dislike_pair : dislikes){        // generating adjacency list, ( bi-directional edges )
            adj[dislike_pair[0]].push_back(dislike_pair[1]);
            adj[dislike_pair[1]].push_back(dislike_pair[0]);
        }

        // Checking for all the nodes in given graph
        for(int i=1;i<=n;i++){
            if(visited[i]==0){                                                // check only if unvisited
                if(isBipartite(adj, visited, node_color, i, 0) == false)
                    return false;
            }
        }

        return true;
    }
};
