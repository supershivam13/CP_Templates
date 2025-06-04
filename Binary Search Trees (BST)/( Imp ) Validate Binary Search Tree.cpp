// Idea to Solve -

// In BST,
// Every node of the Left Subtree is strictly smaller than Root(upper bound) and larger than INT_MIN(lower bound) &
// Every node of the Right Subtree is strictly greater than Root(lower bound) and smaller than INT_MAX(upper bound).

class Solution {
public:

    bool isBST(TreeNode* root, long long low, long long high){

        if(root==NULL)
            return true;

        // Every left node is STRICTLY SMALLER than Root and Every right node is STRICTLY GREATER than Root in BST
        if(root->val<= low || root->val >= high)
            return false;
        
        // recursive call on left subtree with upper bound as root->data
        // recursive call on right subtree with lower bound as root->data
        return ( isBST(root->left, low, root->val) && isBST(root->right,root->val, high) );
    }

    // Solution starts here
    bool isValidBST(TreeNode* root) {

        return isBST(root, LONG_MIN, LONG_MAX);
    }
};
