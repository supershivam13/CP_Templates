// 0/1 Knapsack
class Solution {
public:
    int findTargetSumWays(vector<int>& a, int target) {

        int n = a.size();
        // Edge case when only one element is present in array
        if (n == 1){
            if(a[0] == 0 && target == 0)         
                return 2;                   // +0 and -0
    
            return abs(a[0]) == abs(target) ? 1 : 0;
        }
        
        // THIS PROBLEM IS SAME AS COUNT THE NUMBER OF SUBSETS WITH A GIVEN SUM, 
        // WHERE GIVEN SUM = (ARRAY_SUM + TARGET)/2     (target which is given in question)
        
        // S1 + S2 = ARRAY_SUM
        // S1 - S2 = TARGET         (S1 has all '+' and S2 has all '-' )

        // S1 = (ARRAY_SUM + TARGET)/2

        // We will solve problem considering there is no zeroes in the input array,
        // and we will deal with it in the last

        int zeroes = 0;
        for (int i = 0; i < n; i++)
            if (a[i] == 0)
                zeroes++;

        int asum = accumulate(a.begin(), a.end(), 0);

        // Because the sum of a subset S1 can't be in decimals
        if ((asum + target) % 2 == 1)     //  S1 = (ARRAY_SUM + TARGET)/2 (proved above)
            return 0;

        // This is the given sum, of which we have to find the number of count of subsets with sum equal to given sum
        int S1_sum = (asum + target) / 2;

        // Since we assumed Subset S1 has all '+', so sum of a subset S1 can't be negative
        if (S1_sum < 0)
            return 0;

        vector<vector<int>> dp(n + 1, vector<int>(S1_sum + 1, 0));   // DP Array
        
        for (int i = 0; i <= n; i++) {       // i --> represents length of array
            for (int j = 0; j <= S1_sum; j++) {     // j --> represents sum

                dp[i][j] = 0;

                if (j == 0)
                    dp[i][j] = 1;                   // one way possible i.e  empty subset
            }
        }

        for (int i = 1; i <= n; i++) {       // i --> [1 to N]
            for (int j = 1; j <= S1_sum; j++) {     // j --> [1 to M]

                if (a[i - 1] == 0)                  // we are excluding zeroes (handled at last)
                    dp[i][j] = dp[i - 1][j];

                else if (a[i - 1] > j)              
                    dp[i][j] = dp[i - 1][j];        // excluded
                else            
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - a[i - 1]];  // excluded + included
            }
        }

        // Each zero can be put in either of the partitions, so 2^z ways to do this
        return pow(2, zeroes) * dp[n][S1_sum];
    }
};
