#define f(i,n)          for(int i=0;i<n;i++)
#define F(i,a,n)        for(int i=a;i<n;i++)
#define fo(i,a,b)       for(int i=a;i<=b;i++)

int dp[1001][1001];

class Solution {
public:
    int longestCommonSubsequence(string x, string y) {

        int n = x.length();
        int m = y.length();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Initialisation ( Base condition )
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= m; j++) {
                if (i == 0 or j == 0)
                    dp[i][j] = 0;
            }
        }

        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= m; j++) {
                
                if (x[i - 1] == y[j - 1])                // if character of both strings matches
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }

        return dp[n][m];
    }
};
