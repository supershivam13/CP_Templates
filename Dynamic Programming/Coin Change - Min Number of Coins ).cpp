// MINIMUM NUMBER OF COINS
// This questions has one twists, from the normal Aditya Verma Unbounded Knapsack problem
// 1) We have to initialise with INT_MAX - 1, instead of 0/1

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));

        for(int i=0;i<=n;i++){              //Array Initialisation
            for(int j=0;j<=amount;j++){
                if(i==0)
                    dp[0][j] = INT_MAX - 1;     // Impossible to make amount without coins
                if(j==0)
                    dp[i][j] = 0;               // Zero coins needed to make amount 0                  
            }                                   // (can't put 0/1 here as we have to use min() functions)
        }

        for(int i=1;i<=n;i++){                  // i --> [1 to N]
            for(int j=1;j<=amount;j++){         // j --> [1 to amount]

                if(coins[i-1]>j)                // excluded
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = min(dp[i-1][j], 1 + dp[i][j-coins[i-1]]);  // excluded + included
            }
        }

        return (dp[n][amount]==INT_MAX-1)? -1 :  dp[n][amount];
    }
};
