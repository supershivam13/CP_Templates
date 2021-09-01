// Time Complexity - O(N)
// Space Complexity - O(Height of Tree)


class Solution {
public:
    Node* lca(Node* root , int n1 , int n2 )
    {
        // Base Condition
        if (root == NULL)
            return NULL;

        // if root is either of one node we are looking, return root
        // no need of check further, as even if other comes below this node, LCA is going to be this node
        if (root->data == n1 or root->data == n2)
            return root;

        // calling recursively on left and right subtree
        Node* l = lca(root->left, n1, n2);
        Node* r = lca(root->right, n1, n2);

        // if both of its child are not null, then it means it is LCA, so return root
        if (l != NULL and r != NULL)
            return root;

        // OTHERWISE return 'l' or 'r' whichever is not NULL
        // ( if both l and r are NULL, then 'r' is returned which is NULL )
        if (l != NULL)
            return l;
        else
            return r;
    }

};
