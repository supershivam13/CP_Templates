// Time Complexity - O(N)


// return a pair of maximum possible sum when root is included and excluded {included,excluded} respectively
pair<int, int> maxsum(Node* root) {

    // { included, excluded }
    pair<int, int> p, left, right;

    if (root == NULL)
        return {0, 0};

    // Example of POST-ORDER METHOD {first left subtree, then right subtree, and then calculations for root}

    left = maxsum(root->left);
    right = maxsum(root->right);

    // when root included, then childs are excluded for sure
    p.first = root->data + left.second + right.second;

    // when root is excluded, then both childs can be either included or not, so taking that condition
    // which gives the maximum sum possible
    p.second = max(left.first, left.second) + max(right.first, right.second);

    return p;
}

// Solution starts here
class Solution {
public:
    int getMaxSum(Node *root)
    {
        if (root == NULL)
            return 0;

        pair<int, int> p = maxsum(root);

        // return max of {root included, root excluded}
        return max(p.first, p.second);
    }
};
