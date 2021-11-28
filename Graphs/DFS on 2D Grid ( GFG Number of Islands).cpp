int vis2d[1001][1001];

// left, up, right, down, left-up, right-up, right-down, left-down
int dx[] = { -1, 0, 1, 0, -1, 1, 1, -1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int n, m;

class Solution {
public:
    bool isvalid(int x, int y, vector<vector<char>>& grid) {

        if (x<0 or y<0 or x >= n or y >= m)
            return false;

        if (vis2d[x][y] == 1 or grid[x][y] == '0')
            return false;

        return true;
    }

    void dfs2d(int x, int y, vector<vector<char>>& grid) {

        vis2d[x][y] = 1;

        for (int i = 0; i < 8; i++)
            if (isvalid(x + dx[i], y + dy[i], grid))
                dfs2d(x + dx[i], y + dy[i], grid);
    }

    int numIslands(vector<vector<char>>& grid) {

        memset(vis2d, 0, sizeof(vis2d));
        n = grid.size();
        m = grid[0].size();
        int ans = 0;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (vis2d[i][j] == 0 and grid[i][j] == '1') {
                    dfs2d(i, j, grid);
                    ans++;
                }

        return ans;
    }
};
