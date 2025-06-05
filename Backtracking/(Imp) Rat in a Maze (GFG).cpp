// OPTIMIZATION in terms of Space (Implemented in this Sokution)
// Instead of using a separate 'visited' array, we can use the grid to keep track of the visited cells
// by changing the values to '-1' and putting it back as '1' while backtracking
// and in the isValid function, we check if (grid[x][y]== -1), then return.


class Solution {
public:
    vector<vector<int>> grid;
    vector<string> ans;
    string dir = "URDL"; // Up, Right, Down, Left
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    void dfs2d(int x, int y, int n, string output) {
        // ✅ Boundary + Obstacle + Visited check first
        if (x < 0 || y < 0 || x >= n || y >= n || grid[x][y] == -1 || grid[x][y] == 0)
            return;

        // ✅ Base case: destination reached
        if (x == n - 1 && y == n - 1) {
            ans.push_back(output);
            return;
        }

        int temp = grid[x][y];
        grid[x][y] = -1;  // Mark as visited

        for (int d = 0; d < 4; d++) {
            int new_x = x + dx[d];
            int new_y = y + dy[d];
            
            output.push_back(dir[d]); // Pre-process: add direction
            dfs2d(new_x, new_y, n, output);
            output.pop_back();        // Backtrack
        }

        grid[x][y] = temp; // Unmark (backtrack)
    }
    
    //CODE starts here
    vector<string> ratInMaze(vector<vector<int>> &mat) {
        int n = mat.size();
        grid = mat;

        if (grid[0][0] == 0)
            return ans;

        dfs2d(0, 0, n, "");  // Start from (0,0) with empty path
        sort(ans.begin(), ans.end()); // Lexicographical sort
        return ans;
    }
};
