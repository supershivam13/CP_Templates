class Solution {
public:
    int minDiff(Node *root, int k) {
       
        int closest;          // to store the closest element to K
        int diff = INT_MAX;   // to store the minimum absolute difference
        Node* temp = root;

        // Traversing the BST from root to leaf
        while (temp != NULL) {

            int cur_diff = abs(temp->data - k);

            if (cur_diff == 0)    // we have to return minimim absolute difference, so directly returning 0 here
                return 0;

            // Updating the 'closest' and 'diff'
            if (cur_diff < diff) {
                diff = cur_diff;
                closest = temp->data;
            }

            // Now traverse to either Left subtree or Right subtree
            if (temp->data > k)
                temp = temp->left;        // K may lie in the left sub-tree
            else
                temp = temp->right;       // K may lie in the right sub-tree
        }
        
        return diff;
    }
};
