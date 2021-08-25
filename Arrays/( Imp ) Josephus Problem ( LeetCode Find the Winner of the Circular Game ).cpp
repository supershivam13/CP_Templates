// Time Comlexity - O(N * 2) { as v.erase() takes O(N) time , so overall it becomes O(N*2) }
// Space Comlexity - O(N)


class Solution {
public:
    int findTheWinner(int n, int k) {

        // vector to store the id of each of 'n' persons
        vector<int> v(n, 0);
        for (int i = 0; i < n; i++)
            v[i] = i + 1;

        // as we are going to start the count from index 0 {person with id 1}
        int start = 0;

        // to reach the next target to kill, we only have to jump (k-1) times not k times
        k--;

        // Run loop until only one element remains in the vector
        while (v.size() > 1) {

            int kill = (start + k) % (v.size());
            v.erase(v.begin() + kill);
            start = kill % v.size();
        }

        return v[0];
    }
};
