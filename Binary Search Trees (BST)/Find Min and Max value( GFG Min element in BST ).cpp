// Minimum Value in a BST
int minValue(Node* root) {

    if (root == NULL)        // 0 nodes are present
        return -1;

    if (root->left == NULL)    // 1 node is root, and left subtree is not present
        return root->data;

    Node* temp = root;

    while (temp->left != NULL)   // going to the leftmost leaf node
        temp = temp->left;

    return temp->data;
}
// *********************************************************************** //

// Maximum Value in a BST ( NOT IN QUESTION )
int maxValue(Node* root) {

    if (root == NULL)  // 0 nodes are present
        return -1;

    if (root->right == NULL)   // 1 node is root, and right subtree is not present
        return root->data;

    Node* temp = root;

    while (temp->right != NULL)    // going to the rightmost leaf node
        temp = temp->right;

    return temp->data;
}
