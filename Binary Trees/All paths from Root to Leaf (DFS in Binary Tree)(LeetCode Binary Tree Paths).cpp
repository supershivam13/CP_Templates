// DFS on a Binary Tree

class Solution {
public:
    void dfs(TreeNode *root, string s, vector<string> &ans)
    {
        if (root == NULL)
            return;

        s += to_string(root->val);

        // If reaches the leaf node of the Binary Tree
        if (root->left == NULL && root->right == NULL)
        {
            ans.push_back(s);
            return;
        }

        s += "->";
        dfs(root->left, s, ans);
        dfs(root->right, s, ans);
    }

    // Solution Starts from here
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        dfs(root, "", ans);
        return ans;
    }
};
