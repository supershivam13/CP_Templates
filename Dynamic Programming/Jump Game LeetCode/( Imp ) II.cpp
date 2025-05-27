// GREEDY APPROACH
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


// Problem	      Main Approach
// Jump Game I	  Greedy
// Jump Game II	  Greedy
// Jump Game III	BFS / DFS
// Jump Game IV	  BFS

// So,
// Jump Game I & II → Greedy dominates.
// III & IV → Graph/BFS based.
