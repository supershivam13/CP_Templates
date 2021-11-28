// Let's break n nodes of BST into 1, i - 1, and n - i nodes, where, 1 node is given to root, i - 1 nodes are given to left BST
// subtree and n - i nodes are given to right BST subtree respectively s.t overall we still have 1 + i - 1 + n - i = n nodes

class Solution {
public:
    int numTrees(int n) {

        vector<int> dp(n + 1);
        // Base Condition
        dp[0] = dp[1] = 1;

        for (int i = 2; i <= n; i++)
            // adding all scenes when j-1 nodes are on one side and (i-j) nodes on the other side
            for (int j = 1;  j <= i; j++)
                dp[i] += (dp[j - 1] * dp[i - j]);

        return dp[n];
    }
};
