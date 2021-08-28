// Idea to Solve -

// To check if a tree is height-balanced, get the height of left and right subtrees.
// Return true if difference between heights is not more than 1 and left and right subtrees are balanced,
// otherwise return false.


// METHOD 1
// Time Complexity - O(N ^ 2)

// function to calculate height of a tree
int height(Node* root) {

    if (root == NULL)
        return 0;

    return max( height(root->left), height(root->right) ) + 1;
}

// Solution starts Here
class Solution {
public:
    bool isBalanced(Node *root)
    {
        if (root == NULL)
            return true;

        int h1 = height(root->left);
        int h2 = height(root->right);

        // Return true if difference between heights is not more than 1 and left and right
        // subtrees are balanced, otherwise return false.
        return abs(h1 - h2) <= 1 and isBalanced(root->left) and isBalanced(root->right);
    }
};



// METHOD 2
// Time Complexity - O(N)

// return a pair of {height, is_balanced} for 'root' node
pair<int, bool> isheightbalanced(Node* root) {

    // pair of { height, is_balanced }
    pair<int, bool> p, left, right;

    if (root == NULL) {
        p.first = 0;
        p.second = true;
        return p;
    }

    // Example of POST-ORDER METHOD {first left subtree, then right subtree, and then calculations for root}

    left = isheightbalanced(root->left);
    right = isheightbalanced(root->right);

    p.first = max(left.first, right.first) + 1;

    // true if difference between heights is not more than 1 and left and right subtrees are balanced
    p.second  = (abs(left.first - right.first) <= 1 and left.second and right.second) ? true : false;

    return p;
}

// Solution starts here
class Solution {
public:
    bool isBalanced(Node *root)
    {
        pair<int, bool> p = isheightbalanced(root);
        return p.second;
    }
};
