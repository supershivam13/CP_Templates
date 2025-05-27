// BFS APPROACH
// Time Complexity - O(N)  
// Space Complexity - O(N)

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();

        if (n == 1)     // Base Case
            return 0;
        
        unordered_map<int, vector<int>> valueToIndex; // { value: index1, index2, index3... } 
        for (int i = 0; i < n; i++)
            valueToIndex[arr[i]].push_back(i);

        vector<bool> visited(n, false);
        visited[0] = true;  // marking first index as visited
        queue<int> q;
        q.push(0);
        int steps = 0;
        
        // BFS starts
        while (q.size()>0) {

            int size = q.size();

            for (int i = 0; i < size; i++) {
                int curr = q.front();
                q.pop();

                if (curr == n - 1)      // reaches the last index of array
                    return steps;
                
                if (curr - 1 >= 0 && !visited[curr - 1]) {      // Choice 1
                    visited[curr - 1] = true;
                    q.push(curr - 1);
                }
                
                if (curr + 1 < n && !visited[curr + 1]) {       // Choice 2
                    visited[curr + 1] = true;
                    q.push(curr + 1);
                }
                
                for (int index : valueToIndex[arr[curr]]) {     // Choice 3
                    if (!visited[index]) {
                        visited[index] = true;
                        q.push(index);
                    }
                }
                
                // remove the indices with the same value to avoid revisiting them
                valueToIndex.erase(arr[curr]);
            }
            steps++;
        }
        
        return steps;
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
