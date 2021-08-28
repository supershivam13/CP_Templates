// Level Order Traversal is an example of PreOrder Traversal.


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        // to store the levels of the tree
        vector<int> level;

        // Queue used in BFS ( Level Order Traversal == BFS )
        queue<TreeNode*> q;

        if (root == NULL)
            return ans;

        q.push(root);

        // NULL pointer indicates the end of a level of the Binary Tree
        q.push(NULL);

        while (!q.empty()) {

            TreeNode* curr = q.front();
            q.pop();

            // this means we have reached the end of a level of the tree, so storing the 'level' vector
            if (curr == NULL) {
                ans.push_back(level);
                level.clear();

                // To avoid Infinite loop, only push NULL when there are some elements left in queue
                if (!q.empty())
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
