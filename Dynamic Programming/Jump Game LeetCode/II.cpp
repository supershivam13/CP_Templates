// Method 1:

// Time Complexity - O(N)
// Space Complexity - O(1)

class Solution {
public:
  int jump(vector<int> a) {
    
    int n=a.size();
    if (n == 1)
      return 0;
    
    int maxReach = a[0];
    int step=a[0];
    int jumps=1;
    
    for(int i=1;i<n;i++){
        
        if(i==n-1)
            return jumps;
        else{
            maxReach = max(maxReach,a[i]+i);
            step--;
            
            if(step==0){
                jumps++;
                step=maxReach - i;
            }
        }
    }
    
    return jumps;
  }
};


// **************************************************************************

// Method 2: Easy DP {will result in TLE}

// Time Complexity - O(N^2)
// Space Complexity - O(N)

class Solution {
public:
  int jump(vector<int> a) {
    
    int n=a.size();
    int dp[n];
    for (int i = 0; i < n; i++)
      dp[i] = INT_MAX;

    dp[0] = 0;

    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {

        if (dp[j] != INT_MAX and a[j] + j >= i)
          dp[i] = min(dp[i], dp[j] + 1);
      }
    }

    return (dp[n - 1] == INT_MAX) ? -1 : dp[n - 1];
  }
};
