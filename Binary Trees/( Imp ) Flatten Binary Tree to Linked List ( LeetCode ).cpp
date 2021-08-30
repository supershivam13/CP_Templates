// Flattenig Binary Tree to Linked List in order of Pre-Order Traversal

// ( We are generating linked list in the order of PreOrder Traversal, it does not mean that
//   we are using PreOrder mechanism to solve the question )

class Solution {
public:
    void flatten(TreeNode* root) {

        if (root == NULL)
            return;

        // Assume left and right subtree are flattened by these recursive call
        flatten(root->left);
        flatten(root->right);

        // Now if there is nothing in the left subtree, then no need to do anything
        // as root->right points to the right subtree and right subtree is already flattened.
        if (root->left == NULL)
            return;

        else {
            // storing the right subtree address in 'temp_right' pointer
            TreeNode *temp_right = root->right;

            // attaching the left subtree in the right of the root ( as in PreOrder = root,left,right )
            root->right = root->left;
            root->left = NULL;

            // moving to the last node
            while (root->right)
                root = root->right;

            // attaching the right subtree at the last
            root->right = temp_right;
        }
    }
};
