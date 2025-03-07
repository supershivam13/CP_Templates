// Kadane's Algorithm is used to find the MAXIMUM SUBARRAY SUM
// Kadane's Algorithm can also be used to find the MINIMUM SUBARRAY SUM (by 3 minor changes)

// Kadane’s Algorithm can also be used to solve the Maximum Circular Subarray Sum problem.

// The maximum circular subarray is either:
//     1) The normal max subarray sum (found using Kadane’s Algorithm).
//     2) The total sum of the array minus the minimum subarray sum (wrap-around case).

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxSum = maxSubArray(nums);
        int minSum = minSubArray(nums);

        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        // Edge case: If all elements are negative, totalSum - minSum will be 0
        // [-2, -3, -5], totalSum = -10, minSum = -10, maxSum = -2
        if (totalSum == minSum)
            return maxSum;

        return max(maxSum, totalSum - minSum);
    }

    int maxSubArray(vector<int>& nums) {   // Normal Kadane's Algo for Maximum Subarray Sum
        int cur_sum = 0, ans = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            cur_sum += nums[i];
            ans = max(ans, cur_sum);

            if(cur_sum<0)
                cur_sum=0;
        }
        return ans;
    }

    int minSubArray(vector<int>& nums) {    // Normal Kadane's Algo for Minimum Subarray Sum
        int cur_sum = 0, ans = INT_MAX;                  //(Change 1)

        for (int i = 0; i < nums.size(); i++) {
            cur_sum += nums[i];
            ans = min(ans, cur_sum);                     //(Change 2)

            if(cur_sum>0)                                //(Change 3)
                cur_sum=0;
        }
        return ans;
    }
};
