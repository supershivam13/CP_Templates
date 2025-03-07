//IMPORTANT
// Kadane's Algorithm can also be used to find the MINIMUM SUBARRAY SUM (by 3 minor changes).

 //        int ans = INT_MAX;    // should be initialised with INT_MAX       (CHANGE 1)
        
 //        int cur_sum = 0;     //initialise current sum as zero
        
 //        for (int i=0;i<arr.size();i++){
            
 //            cur_sum += arr[i];
      
 //            ans = min(ans,cur_sum);                                        (CHANGE 2)
            
 //            //If current sum becomes positive at any time, that means we can't include that
 //            //sub-array in our solution, so we  re-initialise it to 0.
 //            // THIS SHOULD BE DONE IN THE LAST, so we get atleast one answer for minimum subarray sum (Case when all numbers in array are positive)
 //            if(cur_sum>0)                                                  (CHANGE 3)
 //                cur_sum = 0;
 //        }
        
 //        return ans;

// -----------------------------------------------------------------------------------------------------------------------//

// KADANE'S ALGORITHM
// Time Complexity - O(N)
// Space Complexity - O(1)

class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        
        int ans = INT_MIN;    // should be initialised with INT_MIN, not zero as negative numbers are there
        
        int cur_sum = 0;     //initialise current sum as zero
        
        for (int i=0;i<arr.size();i++){
            
            cur_sum += arr[i];
      
            ans = max(ans,cur_sum);
            
            //If current sum becomes negative at any time, that means we can't include that
            //sub-array in our solution, so we  re-initialise it to 0.
            // THIS SHOULD BE DONE IN THE LAST, so we get atleast one answer for maximum subarray sum (Case when all numbers in array are negative)
            if(cur_sum<0)
                cur_sum = 0;
        }
        
        return ans;
    }
};


