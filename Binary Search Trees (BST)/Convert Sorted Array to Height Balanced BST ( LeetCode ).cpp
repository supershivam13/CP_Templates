// Sorted Array to a Height Balanced BST is same as Sorted Array to a Minimum Height BST.

class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {

        // Base Condition
        if (num.size() == 0)
            return NULL;

        int middle = num.size() / 2;

        // Making the middle element as root
        TreeNode* root = new TreeNode(num[middle]);

        // Iterators are passed here, which will copy from 1st iterator to 2nd iterator in new vector
        vector<int> left(num.begin(), num.begin() + middle);
        vector<int> right(num.begin() + middle + 1, num.end());

        // Recursively calls for the left and right subtree with passing new vectors
        root->left = sortedArrayToBST(left);
        root->right = sortedArrayToBST(right);

        return root;
    }
};
