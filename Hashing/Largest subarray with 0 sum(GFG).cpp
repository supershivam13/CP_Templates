// IMPORTANT
// Here, Sliding Window approach does not work for negative numbers because it assumes that removing elements from the left
// will always reduce the sum, which is not true when negative numbers are present.

// CONCEPT
// If a prefixsum 'x' is repeated again, it means that the  sum of subarray in between is 0
// because x + 0 = x

class Solution {
  public:
    int maxLen(vector<int>& a) {
        
        int n=a.size();
        int ans = 0, sum = 0;
        
        map<int,int> mp;   // { sum : index}
        mp[0]=-1;      // assuming a sum = 0 till index -1. { 0, -1 }
        
        for(int i=0;i<n;i++){
            sum += a[i];
            
            if(mp.find(sum)!=mp.end())  // if that prefix sum is already present, then calculate ans
                ans = max(ans, i - mp[sum]);    // (i - mp[sum]) gives the length of subarray with zero-sum
            else
                mp[sum]=i;       // else store the {sum:index}
        }
        
        return ans;
    }
};
