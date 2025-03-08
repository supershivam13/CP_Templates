//In matrix or 2D Grid, x-axis is vertcal and y-axis is horizontal (opposite as of Coordinate Geometry)
// Up , Right, Down , Left
int dx[] = { -1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

class Solution {
public:
    string dir = "URDL";
    vector<vector<int>> grid;
    vector<string> ans;
    string output="";
    int vis[6][6];      //maximum value of n is given as 5

     // Funtion to check the valid moves only
    bool isvalid(int x, int y, int n) {           

        if (x < 0 or y < 0 or x > n - 1 or y > n - 1)            // checking it it is moving out of grid
            return false;

        if (vis[x][y] == 1 or grid[x][y] == 0)                // if it is already visited or it has obstacle
            return false;

        return true;
    }

    void dfs2d(int x, int y, int n, string output) {

        // Base Condition
        if (x == n - 1 and y == n - 1) {
            ans.push_back(output);
            return;
        }

        // If it has obstacle { at the start itself (0,0) }
        if (grid[x][y] == 0)
            return;

        vis[x][y] = 1;

        for (int i = 0; i < 4; i++) {
            if (isvalid(x + dx[i], y + dy[i], n)) {

                output += dir[i];                            // Pre-rocessing for next move
                vis[x + dx[i]][y + dy[i]] = 1;

                dfs2d(x + dx[i], y + dy[i], n, output);      // next move

                output.pop_back();                           // backtrack
                vis[x + dx[i]][y + dy[i]] = 0;
            }
        }

        // Back-tracking
        vis[x][y] = 0;
    }

    // SOLUTION starts here
    vector<string> findPath(vector<vector<int>> &mat) {
        
        int n = mat.size();
        grid = mat;
        int start = 0, end = 0;

        memset(vis, 0, sizeof(vis));

        dfs2d(0, 0, n, output);
        
        sort(ans.begin(), ans.end());

        return ans;
    }
};
