class Solution {
public:
    int dx[4] = { -1, 0, 1,  0 };  // Up, Right, Down, Left
    int dy[4] = { 0,  1, 0, -1 };

    void dfs(int x, int y, int n, int m, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        // Boundary Check, Visited Check and is land ('1')
        if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] != '1' || visited[x][y]==true)
            return;

        visited[x][y] = true;

        for (int i = 0; i < 4; i++) {
            dfs(x + dx[i], y + dy[i], n, m, grid, visited);
        }
    }
    // CODE starts here
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int islands = 0;

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && visited[i][j]==0) { // check if found land {grid[i][j]==1} and it is unvisited
                    dfs(i, j, n, m, grid, visited);
                    islands++;
                }
            }
        }

        return islands;
    }
};
