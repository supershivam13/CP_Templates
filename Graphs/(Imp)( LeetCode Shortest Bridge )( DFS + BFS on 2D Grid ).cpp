// Concept Used - DFS + BFS

// Idea to Solve

// First find the first island in the matrix and put all its coordinates in a queue using DFS and mark all them as visited.
// Now start BFS on each coordinates in the queue simulataneously and keep counting the levels until you find a 1 which is
// unvisited (i.e second island). During BFS, keep on marking the coordinates and visited and push them into the queue.


int dx[] = { -1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int m, n;

class Solution {

    vector<vector<int>> mat;
    vector<vector<int>> vis2d;
    queue<pair<int, int> > q;

public:
    bool isvalid(int x, int y) {

        if (x<0 or y<0 or x >= n or y >= m)
            return false;

        if (vis2d[x][y] == 1 or mat[x][y] == 0)
            return false;

        return true;
    }

    // DFS on 2D grid
    void dfs2d(int x, int y) {
        vis2d[x][y] = 1;
        q.push({x, y});

        for (int i = 0; i < 4; i++)
            if (isvalid(x + dx[i], y + dy[i]))
                dfs2d(x + dx[i], y + dy[i]);
    }

    // Solution starts here
    int shortestBridge(vector<vector<int>>& A) {

        //  Created a global copy 'mat' of the matrix A to avoid passing the matrix A in function calls
        mat = A;

        m = mat.size();
        n = mat[0].size();

        vis2d.resize(m, vector<int>(n, 0));

        // 'flag' represents whether we found the first island or not
        int flag = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    dfs2d(i, j);
                    flag = 1;
                    break;
                }
            }
            if (flag)
                break;
        }


        // Now, BFS part starts

        int level = 0;

        while (!q.empty()) {
            int len = q.size();
            level++;

            while (len--) {
                pair<int, int> poi = q.front();
                q.pop();

                vis2d[poi.first][poi.second] = 1;

                for (int i = 0; i < 4; i++) {
                    int x = poi.first + dx[i];
                    int y = poi.second + dy[i];

                    if (x >= 0 && y >= 0 && x <= m - 1 && y <= n - 1) {

                        // found a land (i.e mat[x][y]==1 ) which is unvisited, so reached second island
                        if (vis2d[x][y] == 0 && mat[x][y] == 1)
                            return level - 1;
                        // else if we found a water (i.e mat[x][y]==0 ), so add to queue and mark as visited
                        else if (vis2d[x][y] == 0 && mat[x][y] == 0) {
                            vis2d[x][y] = 1;
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
