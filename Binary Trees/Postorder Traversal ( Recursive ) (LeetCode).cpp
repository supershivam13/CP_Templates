// METHOD 1 - USING RECURSION
// Time Complexity - O(N)

class Solution {
public:

    vector<int> ans;

    void Postorder(TreeNode* root) {

        if (root == NULL)
            return;

        Postorder(root->left);
        Postorder(root->right);
        ans.push_back(root->val);
    }

    // Solution Starts here
    vector<int> postorderTraversal(TreeNode* root) {

        Postorder(root);
        return ans;
    }
};
