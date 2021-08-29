// Inorder Traversal of Binary Search Tree (BST) { not of Binary Tree } is always sorted.

// METHOD 1 - USING RECURSION
// Time Complexity - O(N)

class Solution {
public:

    vector<int> ans;

    void Inorder(TreeNode* root) {

        if (root == NULL)
            return;

        Inorder(root->left);
        ans.push_back(root->val);
        Inorder(root->right);
    }

    // Solution Starts here
    vector<int> inorderTraversal(TreeNode* root) {

        Inorder(root);

        return ans;
    }
};



// METHOD 2 - ITERATIVE { WITHOUT RECURSION }
// Time Complexity - O(N)

class Solution {
public:

    vector<int> ans;

    void Inorder(TreeNode* root) {

        stack<TreeNode*> s;
        TreeNode* curr = root;

        while (curr != NULL || s.empty() == false) {

            // Reach the left most Node of the curr Node
            while (curr != NULL) {
                s.push(curr);
                curr = curr->left;
            }

            // Current must be NULL at this point

            curr = s.top();
            s.pop();

            ans.push_back(curr->val);

            curr = curr->right;
        }

    }

    // Solution Starts here
    vector<int> inorderTraversal(TreeNode* root) {

        Inorder(root);

        return ans;
    }
};
