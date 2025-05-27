// DFS APPROACH
// Time Complexity - O(N)  - Due to the visited[] array, each index is only visited once.
// Space Complexity - O(N) - visited[] array takes O(N)

class Solution {
public:
    bool solve(vector<int>& a, vector<int>& visited, int curr){

        // Base conditions
        if(curr>=a.size() or curr<0 or visited[curr]== 1) // if 'curr' is out of bound or is already visited
            return false;
        
        visited[curr] = 1;

        if(a[curr]==0)          // reached the final value of 0, so true
            return true;

        return ( solve(a, visited, curr + a[curr]) || solve(a, visited, curr - a[curr]) );
    }

    // CODE Stars here
    bool canReach(vector<int>& a, int start) {

        int n = a.size();
        vector<int> visited(n,0);

        return solve(a, visited, start);    // Solver Function
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
