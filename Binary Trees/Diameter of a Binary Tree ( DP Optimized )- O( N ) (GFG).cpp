// Time Complexity - O( N ) { using DP }
// { We are calculating height and diameter simulataneouly, so it is now O(N) }

class Solution {
public:

    pair<int,int> OptimisedDiameter(Node *root) {
        
        pair<int,int> p, left, right;      // pair of {diameter, height}

        if (root == NULL) {    // Base Condition
            p.first = 0;
            p.second = 0;
            return p;
        }

        left = OptimisedDiameter(root->left);
        right = OptimisedDiameter(root->right);

        // Now calculating the heigth(p.second) and diamter(d.first) of the parent node
        // using the results of recursive calls on childs.

        p.second = max(left.second, right.second) + 1;

        int d1 = left.second + right.second; // If asked as Diameter = Number of nodes, then add 1 to 'd1'.
        int d2 = left.first;
        int d3 = right.first;

        p.first = max(d1, max(d2, d3));

        return p;
    }

    // SOLUTIOIN Starts here
    int diameter(Node* root) {
        return OptimisedDiameter(root).first;
    }
};
