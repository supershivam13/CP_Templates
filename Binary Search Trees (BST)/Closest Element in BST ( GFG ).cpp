class Solution {
public:
    int minDiff(Node *root, int k) {
        // to store the closest element to k
        int closest;
        int diff = INT_MAX;
        Node* temp = root;

        // Traversing the BST from root to leaf
        while (temp != NULL) {

            int cur_diff = abs(temp->data - k);

            // we have to return minimim absolute difference, so directly returning 0 here
            if (cur_diff == 0)
                return 0;

            // updating the closest and diff
            if (cur_diff < diff) {
                diff = cur_diff;
                closest = temp->data;
            }

            // left or right
            if (temp->data > k)
                temp = temp->left;
            else
                temp = temp->right;
        }
        return diff;
    }
};
