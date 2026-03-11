// Concept Used - DFS + Multi-source BFS

// IDEA TO SOLVE
// First, find the first island and put all its coordinates in a queue using DFS and mark all them as visited.
// Now start BFS on each coordinates in the queue simulataneously and keep counting the levels until you find a 1 which is
// unvisited (i.e second island). During BFS, keep on marking the coordinates and visited and push them into the queue.

class Solution {
    vector<vector<int>> grid;
    vector<vector<int>> visited;
    queue<pair<int, int> > q;a
public:
    int dx[4] = { -1, 0, 1,  0 };  // Up, Right, Down, Left
    int dy[4] = { 0,  1, 0, -1 };

    void dfs2d(int x, int y, int n, int m) {

        // Boundary Check, Visited Check and is land Check ('1')
        if (x < 0 || x >= n || y < 0 || y >= m || visited[x][y] == 1 || grid[x][y] == 0)
            return;

        visited[x][y] = 1;
        q.push({x, y});

        for (int i = 0; i < 4; i++){
            dfs2d(x + dx[i], y + dy[i], n, m);
        }
    }

    // CODE starts here
    int shortestBridge(vector<vector<int>>& A) {
        
        int n = A.size(), m = A[0].size();

        grid = A;        // Created a global copy 'grid' of the matrix A to avoid passing the matrix A in function calls
        visited.resize(n, vector<int>(m, 0));
        
        int foundFirst = 0;       // 'flag' represents whether we found the first island or not

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    dfs2d(i, j, n, m);
                    foundFirst = 1;
                    break;
                }
            }

            if (foundFirst)
                break;
        }

        // Now, Multi-source BFS starts
        int level = 0;

        while (q.size() > 0) {
            int size = q.size();
            level++;

            while (size--) {
                pair<int, int> poi = q.front();
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int x = poi.first + dx[i];
                    int y = poi.second + dy[i];

                    if (x >= 0 && y >= 0 && x <= n - 1 && y <= m - 1) {

                        // found a land (i.e grid[x][y]==1 ) which is unvisited, so reached second island
                        if (visited[x][y] == 0 && grid[x][y] == 1)
                            return level - 1;
                        // else if we found a water (i.e grid[x][y] == 0), so add to queue and mark as visited
                        else if (visited[x][y] == 0 && grid[x][y] == 0) {
                            visited[x][y] = 1;
                            q.push({x, y});
                        }
                        // Nothing to do with those coordinates which are already visited
                    }
                }
            }
        }

        return -1;
    }
};
