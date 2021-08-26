class Solution {
public:

    int changetoSum(Node *root) {

        // Base Conditon
        if (root == NULL)
            return 0;

        // Case of leaf node {changing it's data to 0 and returning the original data stored in it}
        if (root->left == NULL and root->right == NULL) {
            int temp = root->data;
            root->data = 0;
            return temp;
        }

        // Recursive calls to get the sum of left subtree and right subtree
        int LS = changetoSum(root->left);
        int RS = changetoSum(root->right);

        int temp = root->data;
        root->data = LS + RS;

        // returning originally stored root data + {sum of left subtree} + {sum of right subtree}
        return temp + LS + RS;
    }

    // Solution starts here
    void toSumTree(Node *node)
    {
        int sum = changetoSum(node);
    }
};
