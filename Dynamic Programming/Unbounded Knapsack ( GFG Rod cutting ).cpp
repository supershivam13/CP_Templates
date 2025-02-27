class Solution {
public:

    int cutRod(int price[], int n) {

        // Array which contains the permissible length of the pieces
        // (In this question, all lengths from 1 to N are permissible )
        // (Otherwise, this array will also be given as input )
        int a[n];
        for (int i = 0; i < n; i++)
            a[i] = i + 1;

        // DP Array ( dp[size of array + 1][length of rod + 1])
        int dp[n + 1][n + 1];

        // Initialising the dp array
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++)
                if (i == 0 or j == 0)
                    dp[i][j] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {

                // if permssible length of piece is greater than the rod itself
                if (a[i - 1] > j)
                    dp[i][j] = dp[i - 1][j];
                // else max of (included, not included)
                else
                    dp[i][j] = max(price[i - 1] + dp[i][j - a[i - 1]], dp[i - 1][j]);
            }
        }

        return dp[n][n];
    }
};
