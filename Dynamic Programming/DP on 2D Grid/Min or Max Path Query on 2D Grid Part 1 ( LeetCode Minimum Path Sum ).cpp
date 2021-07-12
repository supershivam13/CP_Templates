class Solution {
public:
    int minPathSum(vector<vector<int>>& a) {

        // n = number of rows, m = number of columns
        int n = a.size();
        int m = a[0].size();

        // 1-based indexing and 1 extra row and column for base condition
        int dp[n + 2][m + 2];

        // Pre-processing (since we have to find the minimum , so initialising the extra row with INT_MAX )
        for (int i = 1; i <= m + 1; i++)
            dp[n + 1][i] = INT_MAX;

        // Pre-processing (since we have to find the minimum , so initialising the extra row with INT MAX )
        for (int i = 1; i <= n + 1; i++)
            dp[i][m + 1] = INT_MAX;

        // Base Case - Since cost to reach (n,m) from (n,m) is just a[n][m], so that min of both is zero
        dp[n + 1][m] = dp[n][m + 1] = 0;

        for (int i = n; i >= 1; i--) {
            for (int j = m; j >= 1; j--) {

                // cost to reach (n,m) from (i,j) is a[i][j] + min(right, down)
                // Here a[][] is 0 based indexed so a[i-][j-1] in place of a[i][j]
                dp[i][j] = a[i - 1][j - 1] + min(dp[i + 1][j], dp[i][j + 1]);
            }
        }

        return dp[1][1];

    }
};
