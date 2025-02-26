// Time Complexity - O( N^2 )

class Solution {
public:

    int height(Node* root) {

        if (root == NULL)
            return 0;

        return 1 + max(height(root->left), height(root->right));
    }

    // Solution starts here
    int diameter(Node* root) {    // Function to return the diameter of a Binary Tree.

        if (root == NULL)
            return 0;

        
        int d1 = height(root->left) + height(root->right) + 1 ;   // when diameter passes through root
        int d2 = diameter(root->left);                            // when diameter lies in the left subtreee
        int d3 = diameter(root->right);                           // when diameter lies in the left subtreee

        return max(d1, max(d2, d3));
    }
};
