int dp[1001][1001];

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        // to store the result
        int result = 0;

        // Initialisation ( Base Condition )
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 or j == 0)
                    dp[i][j] = 0;
            }
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {

                // if the element of both strings/arrays matches
                if (nums1[i - 1] == nums2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = 0;

                // storing the max value obtained in the whole dp matrix as LC Substring/Subarray can occur anywhere
                result = max(result, dp[i][j]);
            }
        }

        return result;
    }
};
