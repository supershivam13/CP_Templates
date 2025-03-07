class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        int n=nums.size();
        k = k%n;   // rotating array n times is basically the initial position of array

        reverse(nums.begin(),nums.end());     // reverse the whole array
        reverse(nums.begin(),nums.begin()+k); // reverse the first k elements
        reverse(nums.begin()+k,nums.end());   // reverse the remaining (n-k) elements

        return;
    }
};
