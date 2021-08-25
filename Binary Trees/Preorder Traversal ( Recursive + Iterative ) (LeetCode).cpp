// METHOD 1 - USING RECURSION
// Time Complexity - O(N)


class Solution {
public:

    vector<int> ans;

    void Preorder(TreeNode* root) {

        if (root == NULL)
            return;

        ans.push_back(root->val);
        Preorder(root->left);
        Preorder(root->right);
    }

    // Solution Starts here
    vector<int> preorderTraversal(TreeNode* root) {

        Preorder(root);
        return ans;
    }
};



// METHOD 2 - ITERATIVE { WITHOUT RECURSION }
// Time Complexity - O(N)

class Solution {
public:

    vector<int> ans;

    void Preorder(TreeNode* root) {

        stack<TreeNode*> s;
        TreeNode* curr = root;

        // run till stack is not empty or current is not NULL
        while (curr != NULL || s.empty() == false) {

            while (curr != NULL) {
                ans.push_back(curr->val);

                if (curr->right)
                    s.push(curr->right);

                curr = curr->left;
            }

            // We reach here when curr is NULL, so We take out a right child from stack
            if (s.empty() == false) {
                curr = s.top();
                s.pop();
            }
        }
    }

    vector<int> preorderTraversal(TreeNode* root) {

        Preorder(root);

        return ans;
    }
};
