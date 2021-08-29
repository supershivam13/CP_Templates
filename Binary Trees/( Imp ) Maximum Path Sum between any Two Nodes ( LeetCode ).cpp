// Maximum Path Sum between any Two Nodes
// { this code can't be used for maximum sum path between any Two leaf Nodes }


// intialised global variable to store the final result
int res;

int maxpathsum(TreeNode* root) {

    // Base Condition
    if (root == NULL)
        return 0;

    int l = maxpathsum(root->left);
    int r = maxpathsum(root->right);

    // s1 = when maxsum path goes through either (left subtree or right subtree) and root
    // s1 = take max of the left and right subtree and add the root value in it

    // We have used two time max function() because if l and r both are negative so, we don't need
    // to take either subtree and can take only root value.
    int s1 = max( max(l, r) + root->val , root->val );

    // s2 = when maxsum path goes through left subtree -> root -> right subtree
    int s2 = l + r + root->val;

    // res stores the max of every s1,s2 possible
    res = max(res, max(s1, s2));

    // we have to return s1 (and not s2) to it's parent because s1 is the max sum possible
    // from its child call
    return s1;
}

// Solution starts here
class Solution {
public:
    int maxPathSum(TreeNode* root) {

        if (root == NULL)
            return 0;

        res = INT_MIN;
        maxpathsum(root);

        return res;
    }
};
