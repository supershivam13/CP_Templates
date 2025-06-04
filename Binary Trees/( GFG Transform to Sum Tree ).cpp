class Solution {
public:

    int changetoSum(Node *root) {
        if (root == NULL)    // Base Conditon
            return 0;

        // Case of leaf node {changing it's data to 0 and returning the original data stored in it}
        if (root->left == NULL && root->right == NULL) {
            int original = node->data;
            node->data = 0;  // Leaf node becomes 0
            return original;
        }

        int leftSum = SumTree(node->left);
        int rightSum = SumTree(node->right);

        int original = node->data;
        node->data = leftSum + rightSum;  // Update node to sum of its left and right subtree

        return original + leftSum + rightSum;  // Return total sum including this node
    }

    // CODE starts here
    void toSumTree(Node *node)
    {
        int sum = SumTree(node);
    }
};
