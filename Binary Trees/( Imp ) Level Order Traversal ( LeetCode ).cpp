// Time Complexity - O(N) - Uses BFS Algorithm
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> ans;    // to return the vector of levels (final answer)
        vector<int> level;          // to store the levels of the tree
        if (root == NULL)
            return ans;

        queue<TreeNode*> q;
        q.push(root);                   

        while (q.size() > 0) {
            int size = q.size();              // number of nodes at the current level

            while (size--) {
                TreeNode* curr = q.front();
                q.pop();

                level.push_back(curr->val);   // Process current node

                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }

            ans.push_back(level);             // Add current level to answer
            level.clear();                    // clear 'level' vector for next level of tree
        }
        return ans;
    }
};
