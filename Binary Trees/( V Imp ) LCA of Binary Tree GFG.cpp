// Time Complexity - O(N)
// Space Complexity - O(Height of Tree)

class Solution {
public:
    Node* lca(Node* root , int n1 , int n2 )
    {
        if (root == NULL)    // Base Condition
            return NULL;

        // if root is either of one node we are looking, return root
        // no need of check further, as even if other comes below this node, LCA is going to be this node
        if (root->data == n1 or root->data == n2)
            return root;

        // calling recursively on left and right subtree
        Node* left = lca(root->left, n1, n2);
        Node* right = lca(root->right, n1, n2);
    
        // if both of its child_LCA are not NULL, then it means root is LCA
        if (left != NULL and right != NULL)  // Case when n1 and n2 lies in separate subtrees
            return root;

        // OTHERWISE return 'left' or 'right' whichever is not NULL
        // ( if both left and right are NULL, then 'right' is returned which is NULL anyways )
        if (left != NULL)
            return left;
        else
            return right;
    }
};
