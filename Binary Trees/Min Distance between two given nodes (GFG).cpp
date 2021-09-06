class Solution {
public:
    // Function to return the address of LCA of n1 and n2
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

    // Function to calculate the distance of k from root
    int dist(Node* root, int k, int d) {
        if (root == NULL)
            return -1;

        if (root->data == k)
            return d;

        int left = dist(root->left, k, d + 1);
        if (left != -1)
            return left;
        else
            return dist(root->right, k, d + 1);
    }

    // Solution starts here
    int findDist(Node* root, int a, int b) {

        Node* LCA = lca(root, a, b);

        int d1 = dist(LCA, a, 0);
        int d2 = dist(LCA, b, 0);

        return d1 + d2;
    }
};
