int dp[101][101];

class Solution {
public:

    //return number of paths from (1,1) to (n,m) when only down or right movement is available
    int uniquePaths(int n, int m) {

        // when in the last row or last column, only 1 way is possible to reach (n,m)
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (i == n or j == m)
                    dp[i][j] = 1;
            }
        }


        // number of ways from (x,y) = number of ways(x+1,y) + number of ways(x,y+1)
        for (int i = n - 1; i >= 1; i--) {
            for (int j = m - 1; j >= 1; j--) {
                dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
            }
        }

        return dp[1][1];

    }
};
