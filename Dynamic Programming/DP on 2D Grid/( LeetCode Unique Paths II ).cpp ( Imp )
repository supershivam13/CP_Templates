long long int dp[101][101];

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& a) {

        int n = a.size();
        int m = a[0].size();

        // DP Array is 1-based indexed while grid a[][] is 0-based indexed

        // if the final destination has obstacle
        if (a[n - 1][m - 1] == 1)
            return 0;
        else
            dp[n][m] = 1;

        // filling last row
        for (int i = m - 1; i >= 1; i--) {
            // if there is obstacle at that place OR obstacle in there in the only path to destination
            if (a[n - 1][i - 1] == 1 or dp[n][i + 1] == 0)
                dp[n][i] = 0;
            else
                dp[n][i] = 1;
        }

        // filling last column
        for (int i = n - 1; i >= 1; i--) {
            // if there is obstacle at that place OR obstacle in there in the only path to destination
            if (a[i - 1][m - 1] == 1 or dp[i + 1][m] == 0)
                dp[i][m] = 0;
            else
                dp[i][m] = 1;
        }


        // number of ways from (x,y) = number of ways(x+1,y) + number of ways(x,y+1)
        for (int i = n - 1; i >= 1; i--) {
            for (int j = m - 1; j >= 1; j--) {

                // if obstacle is there at a[i][j] ( grid a[][] is 0-based indexed, so a[i][j] -> a[i-1][j-1] )
                if (a[i - 1][j - 1] == 1)
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
            }
        }

        return dp[1][1];

    }
};
