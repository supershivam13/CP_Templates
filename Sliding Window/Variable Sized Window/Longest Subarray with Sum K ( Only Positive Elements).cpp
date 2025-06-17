// IMPORTANT
// This Sliding Window approach does not work for negative numbers because it assumes that removing elements from the left
// will always reduce the sum, which is not true when negative numbers are present.

// When negative numbers are also present, then Instead of a sliding window,
// use a prefix sum and a hash map to find the longest subarray with sum K efficiently.

class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int i = 0, j = 0, n = nums.size();
        int sum = 0, ans = 0;
    
        while (j < n) {
            sum += nums[j];                   // Adding calculations of 'j'
    
            if (sum == k)                     // Condition is met
                ans = max(ans, j - i + 1);
    
            while (sum > k) {                 // Shrink window till 'sum' > 'k'
                sum -= nums[i];               // removing calculations of 'i'
                i++;
    
                if (sum == k)                 // Condition is met
                    ans = max(ans, j - i + 1);
            }
            j++;
        }
    
        return ans;
    }
};
