// IMPORTANT
// This Sliding Window approach does not work for negative numbers because it assumes that removing elements from the left
// will always reduce the sum, which is not true when negative numbers are present.

// When negative numbers are also present, then Instead of a sliding window,
// use a prefix sum and a hash map to find the longest subarray with sum K efficiently.

class Solution {
public:
    int lenOfLongSubarr(int nums[],  int N, int k)
    {
        int i = 0, j = 0, ans = 0, localSum = 0;

        while (j < N)
        {
            localSum = localSum + nums[j];

            if (localSum == k)
                ans = max(ans, (j - i + 1));

            else
            {
                while (localSum > k)
                {
                    localSum -= nums[i];
                    i++;
                    if (localSum == k)
                        ans = max(ans, (j - i + 1));
                }
            }

            j++;
        }

        return ans;
    }
};
