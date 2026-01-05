class Solution {
public:
    int longestCommonSubsequence(string a, string b) {

        int n = a.length(), m = b.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));    // dp[n + 1][m + 1]

        for(int i = 0; i <= n; i++)       // DP Array Initialisatoin (not required, as initialised with 0)
            for(int j = 0; j <= m; j++)
                dp[i][j] = 0;

        for(int i = 1; i <= n; i++){      
            for(int j = 1; j <= m; j++){
                if(a[i - 1] == b[j - 1])                  // if character of both strings matches
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else 
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[n][m];
    }
};
