// Time Complexity - O( N )
// { We are calculating height and diameter simulataneouly, so it is now O(N) }

/*

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

*/

class Solution {
public:

    pair<int, int> OptimisedDiameter(Node *root) {

        // pair of {diameter, height}
        pair<int, int> p;

        // Base Condition
        if (root == NULL) {
            p.first = 0;
            p.second = 0;
            return p;
        }

        pair<int, int> left = OptimisedDiameter(root->left);
        pair<int, int> right = OptimisedDiameter(root->right);

        // Now calculating the heigth and diamter using the results of recursive calls

        p.second = max(left.second, right.second) + 1;

        int d1 = left.second + right.second + 1;
        int d2 = left.first;
        int d3 = right.first;

        p.first = max(d1, max(d2, d3));

        return p;
    }

    // Solution Starts here
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {

        if (root == NULL)
            return 0;

        return OptimisedDiameter(root).first;
    }
};
