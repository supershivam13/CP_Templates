// GREEDY APPROACH
// Time Complexity - O(N)
// Space Complexity - O(1)

class Solution {
public:
    int jump(vector<int>& nums) {

        int n = nums.size();
        int jumps = 0;      // final minimum jumps needed
        int l = 0;          // think of reachable ranges as [l,r] 
        int r  = 0;         // l = left, r = right, initially [l,r] range is [0,0]

        while(r < n-1 ){    // if r reaches the end of array or passes it, break the while loop

            int maxIndex = 0;       // maximum index we can reach

            // Check all positions from l to r
            for(int i=l;i<=r;i++){      // taking the maxIndex we can reach for each [l,r] range
                maxIndex = max(maxIndex, i + nums[i]);
            }

            // Update bounds for the next jump
            l = r + 1;      // l will always be one more to previous range high
            r = maxIndex;   // r will become the maxIndex which can be reached in next range
            jumps++;        // we took one more jump
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
