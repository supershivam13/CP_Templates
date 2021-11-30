class Solution {
public:
    int triangleNumber(vector<int>& nums) {

        int count = 0;
        if (nums.size() < 3) 
            return 0;

        sort(nums.begin(), nums.end());

        // Assuming nums[i] be the third largest side of the triangle, and calculating how many pairs
        // are possible with nums[i] as the third largest side
        for (int i = 2; i < nums.size() ; i++) {

            //left pointer from 0, right pointer from (i-1)
            int left = 0, right = i - 1;

            while (left < right) {

                if (nums[left] + nums[right] > nums[i]) {
                    count += (right - left);
                    right--;
                }
                else
                    left++;
            }
        }
        
        return count;
    }
};
