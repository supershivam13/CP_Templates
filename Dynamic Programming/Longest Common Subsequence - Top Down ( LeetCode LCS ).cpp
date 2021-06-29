// NOTE: In Top Down Approach ( Recursive approach ), if there is need of passing arrays/strings as parameter,
// then pass arrays/strings by address ( to avoid time and memory in copying the array/string in a new function call )

// ( In some cases, not doing this may result in TLE, just like in this question LCS on Leetcode )

// DP Array
int dp[1001][1001];

class Solution {
public:

    // passing arrays/strings by address to avoid time and memory in copying the array/string in a new function call
    // ( will result in TLE if not passed by address )
    int solve_lcs(string &x, string &y, int m, int n) {

        // Base condition ( when either of the string length becomes zero )
        if (m == 0 or n == 0)
            return 0;

        // Memoization
        if (dp[m][n] != -1)
            return dp[m][n];

        // if last character of both strings matches, then reducing the length of both strings by 1
        // and storing in the dp array
        if (x[m - 1] == y[n - 1])
            return dp[m][n] = (1 + solve_lcs(x, y, m - 1, n - 1));
        // else taking max of the two choices by reducing length of one of the two strings and keepingthe other string same
        else
            return dp[m][n] = max(solve_lcs(x, y, m, n - 1), solve_lcs(x, y, m - 1, n));

    }

    // Starts from here
    int longestCommonSubsequence(string x, string y) {

        // Initialsing the DP array with -1
        memset(dp, -1, sizeof(dp));

        int m = x.length();
        int n = y.length();

        return solve_lcs(x, y, m, n);
    }
};
