class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();
        vector<int> ans(n);
        vector<int> left_product(n);
        vector<int> right_product(n);

        //Pre-processing for left product vector
        left_product[0] = 1;
        for(int i=1;i<n;i++)
            left_product[i] = (left_product[i-1] * nums[i-1]);
        
        //Pre-processing for right product vector
        right_product[n-1]=1;
        for(int i=n-2;i>=0;i--)
            right_product[i] = (right_product[i+1] * nums[i+1]);

        //Calculating final ans vector
        for(int i=0;i<n;i++)
            ans[i] = left_product[i] * right_product[i];

        return ans;
    }
};
