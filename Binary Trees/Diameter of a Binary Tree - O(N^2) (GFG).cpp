// Time Complexity - O( N^2 )

class Solution {
public:

    int height(Node* root) {

        if (root == NULL)
            return 0;

        return 1 + max(height(root->left), height(root->right));
    }

    // Solution starts here
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {

        if (root == NULL)
            return 0;

        // when diameter passes through root
        int d1 = height(root->left) + height(root->right) + 1 ;

        // when diameter lies in the left subtreee
        int d2 = diameter(root->left);

        // when diameter lies in the left subtreee
        int d3 = diameter(root->right);

        return max(d1, max(d2, d3));

    }
};
