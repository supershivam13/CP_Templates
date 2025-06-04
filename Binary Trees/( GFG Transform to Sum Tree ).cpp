class Solution {
public:
        int changetoSum(Node* node) {
        if (node == NULL)    // Base Conditon
            return 0;

        // Case of leaf root {changing it's data to 0 and returning the original data stored in it}
        if (node->left == NULL && node->right == NULL) {
            int original = node->data;
            node->data = 0;  // Leaf root becomes 0
            return original;
        }

        int leftSum = changetoSum(node->left);
        int rightSum = changetoSum(node->right);

        int original = node->data;
        node->data = leftSum + rightSum;  // Update root to sum of its left and right subtree

        return original + leftSum + rightSum;  // Return total sum including this root
    }

    // CODE starts here
    void toSumTree(Node *node)
    {
        int sum = changetoSum(node);
    }
};
