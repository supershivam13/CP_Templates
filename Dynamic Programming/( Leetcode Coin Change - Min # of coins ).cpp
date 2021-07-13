class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        // 1-based indexing

        // Initialising DP array with INT_MAX;
        long long int dp[amount + 1];
        for (int i = 0; i <= amount; i++)
            dp[i] = INT_MAX;

        // Zero coins are needed to make a sum of zero
        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (i - coins[j] >= 0)
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }

        // if amount can't be formed using the given coins
        if (dp[amount] == INT_MAX)
            return -1;
        else
            return dp[amount];
    }
};
