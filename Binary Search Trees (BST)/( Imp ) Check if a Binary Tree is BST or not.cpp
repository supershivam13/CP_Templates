// Idea to Solve -

// In BST,
// Every node of the Left Subtree is strictly smaller than Root(upper bound) and larger than INT_MIN(lower bound) &
// Every node of the Right Subtree is strictly greater than Root(lower bound) and smaller than INT_MAX(upper bound).

class Solution {
public:

    bool isBST(TreeNode* root, long long low, long long high){

        if(root==NULL)
            return true;
        
        if(root->val<= low || root->val >= high)  // Every left node is STRICTLY SMALLER than Root and Every right node is STRICTLY GREATER than Root in BST
            return false;
        
        bool left = isBST(root->left, low, root->val);        // recursive call on left subtree with upper bound as root->data
        bool right = isBST(root->right,root->val, high);      // recursive call on right subtree with lower bound as root->data

        return (left and right);
    }

    // SOLUTION starts here
    bool isValidBST(TreeNode* root) {

        return isBST(root, LONG_MIN, LONG_MAX);           // Function to check whether a Binary Tree is BST or not.
    }
};
