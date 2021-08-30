// Idea to Solve -

// In BST,
// Every node of the Left Subtree is smaller than Root(upper bound) and larger than INT_MIN(lower bound) &
// Every node of the Right Subtree is greater than Root(lower bound) and smaller than INT_MAX(upper bound).

class Solution {
public:

    bool isBST(Node* root, int low, int high) {

        if (root == NULL)
            return true;

        if (root->data <= low or root->data >= high )
            return false;

        // recursive call on left subtree with upper bound as root->data
        bool left = isBST(root->left, low, root->data);

        // recursive call on right subtree with lower bound as root->data
        bool right = isBST(root->right, root->data, high);

        return (left and right);
    }

    // Solution starts here
    //Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) {

        return isBST(root, INT_MIN, INT_MAX);
    }
};
