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
