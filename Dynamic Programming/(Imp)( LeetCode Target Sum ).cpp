class Solution {
public:
    int findTargetSumWays(vector<int>& a, int target) {

        // Edge case when only one element is present in array
        if (a.size() == 1) {

            if (abs(a[0]) == abs(target))
                return 1;
            else
                return 0;
        }


        // THIS PROBLEM IS SAME AS COUNT THE NUMBER OF SUBSETS WITH A GIVEN SUM, WHERE GIVEN SUM = (ARRAY_SUM + TARGET)/2
        // ( SEE NOTES )

        // We will solve problem considering there is no zeroes in the input array, and we will deal with it in the last

        // To count the number of zeroes
        int z = 0;

        for (int i = 0; i < a.size(); i++)
            if (a[i] == 0)
                z++;

        int asum = accumulate(a.begin(), a.end(), 0);

        // Because the sum of a subset can't be in decimals
        if ((asum + target) % 2 == 1)
            return 0;

        // This is the given sum, of which we have to find the number of count of subsets with sum equal to given sum
        int t = (asum + target) / 2;

        // Since we are dealing with only positive integers, so sum of a subset can't be negative
        if (t < 0)
            return 0;

        // DP Array
        int dp[a.size() + 1][t + 1];

        // Initialising DP Array
        for (int i = 0; i <= a.size(); i++) {
            for (int j = 0; j <= t; j++) {

                dp[i][j] = 0;

                if (i == 0)
                    dp[i][j] = 0;

                if (j == 0)
                    dp[i][j] = 1;
            }
        }

        for (int i = 1; i <= a.size(); i++) {
            for (int j = 1; j <= t; j++) {

                if (a[i - 1] == 0)
                    dp[i][j] = dp[i - 1][j];

                else if (a[i - 1] > j)
                    dp[i][j] = dp[i - 1][j];

                else
                    dp[i][j] = dp[i - 1][j - a[i - 1]] + dp[i - 1][j];

            }
        }

        // Each zero can be put in either of the partitions, so 2^z ways to do this
        return pow(2, z) * dp[a.size()][t];

    }
};
