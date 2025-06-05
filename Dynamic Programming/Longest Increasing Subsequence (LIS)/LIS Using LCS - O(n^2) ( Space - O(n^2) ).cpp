// LIS using Concept of LCS (2D-DP)
// LIS of an array = LCS of the array with its sorted array containg one element only once.
// The second array should contain only unique elements because here LIS means
// LONGEST STRICTLY INCREASING SUBSEQUENCE.

// However, if LIS is not strictly increasing, then we can have the same element multiple times
// in the second sorted array. In such case, second array is just the sorted array of given array.

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        set<int> s;
        for(auto ele : nums)
            s.insert(ele);

        vector<int> nums2;      // Second array which is SORTED containing one element only once 

        for(auto x: s)
            nums2.push_back(x);

        int n = nums.size();
        int m = nums2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        // Array Initialisation is NOT REQURIED HERE AS ALREADY INITIALSED WITH 0
        
        for(int i=1;i<=n;i++) {  
            for(int j=1;j<=m;j++) {

                if (nums[i - 1] == nums2[j - 1])   // if elements of both array matches
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }

        return dp[n][m];
    }
};
