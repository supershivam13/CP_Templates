// KADANE'S ALGORITHM
// Time Complexity - O(N)
// Space Complexity - O(1)


class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        
        int ans = INT_MIN;
        
        //initialise current sum as zero
        int cur_sum = 0;
        
        for (int i=0;i<arr.size();i++){
            
            cur_sum += arr[i];
      
            ans = max(ans,cur_sum);
            
            //If current sum becomes negative at any time, that means we can't include that
            //sub-array in our solution, so we  re-initialise it to 0.
            if(cur_sum<0)
                cur_sum = 0;
        }
        
        return ans;
    }
};
