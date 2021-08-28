// See Apni Kaksha Video first

vector<int> ans;

// Funtion to print k-th level nodes from the given root
void printKlevel(TreeNode *root, int k)
{
    // Base Case
    if (root == NULL || k < 0)
        return;

    // If we reach a k distant node, store it
    if (k == 0) {
        ans.push_back(root->val);
        return;
    }

    // Recursive call for left and right subtrees
    printKlevel(root->left, k - 1);
    printKlevel(root->right, k - 1);
}



// Function to print all K Distace nodes from target Node
int printKdistanceNode(TreeNode* root, TreeNode* target, int k) {

    if (root == NULL)
        return -1;

    if (root == target) {
        printKlevel(target, k);
        return 0;
    }

    // Recur for left subtree
    int dl = printKdistanceNode(root->left, target, k);

    // Check if target node was found in left subtree
    if (dl != -1)
    {
        // If root is at distance k from target, print root
        // Note that dl is Distance of root's left child from target
        if (dl + 1 == k)
            ans.push_back(root->val);

        // Else go to right subtree and print all (k-dl-2) distant nodes
        // Note that the right child is 2 edges away from left child
        else
            printKlevel(root->right, k - dl - 2);

        // Add 1 to the distance and return value for parent calls
        return 1 + dl;
    }

    // MIRROR OF ABOVE CODE FOR RIGHT SUBTREE
    // Note that we reach here only when node was not found in left subtree
    int dr = printKdistanceNode(root->right, target, k);

    if (dr != -1)
    {
        if (dr + 1 == k)
            ans.push_back(root->val);
        else
            printKlevel(root->left, k - dr - 2);
        return 1 + dr;
    }

    // If target was neither present in left nor in right subtree
    return -1;
}


// Solution starts here
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        ans.clear();

        // function to print all k distace nodes from target
        printKdistanceNode(root, target, k);

        return ans;
    }
};
