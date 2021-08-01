//  Time Complexity: O(n)
//  Auxiliary Space: O(n)

class Solution {
public:
    int lenOfLongSubarr(int nums[],  int n, int k)
    {
        unordered_map<int, int> mp;
        int sum = 0, int len = 0;

        for (int i = 0; i < n; i++) {

            sum += nums[i];

            // when subarray starts from index '0'
            if (sum == k)
                len = max(len, i + 1);

            // make an entry for 'sum' if it is not present in 'mp'
            if (mp.find(sum) == mp.end())
                mp[sum] = i;

            // check if 'sum-k' is present in 'mp' or not
            if (mp.find(sum - k) != mp.end())
                // update maxLength
                len = max(len, i - mp[sum - k]);
        }

        return len;
    }
};
