int dp[1001][1001];

class Solution {
public:
    int longestCommonSubstring(string x, string y) {

        int m = x.length();
        int n = y.length();

        // to store the result ( the length of the longest common substring )
        int result = 0;

        // to store the end index of the longest common substring ( in string x )
        int end = -1;

        // Initialisation ( Base Condition )
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 or j == 0)
                    dp[i][j] = 0;
            }
        }

        // DP
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {

                // if the element of both strings/arrays matches
                if (x[i - 1] == y[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = 0;

                // storing the max value obtained in the whole dp matrix as LC Substring/Subarray can occur anywhere
                if (dp[i][j] > result) {
                    result = dp[i][j];

                    // storing the end index of the LCSS
                    end = i;
                }
            }
        }


        string lcss = "";

        // Getting the substring of length 'result' from string x starting from the index 'end-result'
        lcss = x.substr(end - result, result);
        cout << lcss;

        return dp[m][n];
    }
};
