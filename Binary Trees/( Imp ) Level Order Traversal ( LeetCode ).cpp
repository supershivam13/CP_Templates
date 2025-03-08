class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> ans;    // to return the vector of levels (final answer)
        vector<int> level;          // to store the levels of the tree

        queue<TreeNode*> q;     // Queue used in BFS ( Level Order Traversal == BFS )

        if (root == NULL)    // Base Condition
            return ans;

        q.push(root);

        q.push(NULL);   // NULL pointer indicates the end of a level of the Binary Tree

        
        while (q.size()>0) {

            TreeNode* curr = q.front();
            q.pop();

            if (curr == NULL) {    // this means we have reached the end of a level of the tree, so storing the 'level' vector
                ans.push_back(level);
                level.clear();

                // Put NULL back again as soon we get NULL, but only when there is some elements left in queue (to avoid Infinite loop)
                if (q.size()>0)
                    q.push(NULL);
            }
            else {
                level.push_back(curr->val);

                if (curr->left != NULL)
                    q.push(curr->left);
                if (curr->right != NULL)
                    q.push(curr->right);
            }
        }

        return ans;
    }
};
