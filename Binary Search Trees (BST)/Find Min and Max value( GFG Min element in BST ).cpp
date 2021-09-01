// Minimum Value in a BST

int minValue(Node* root) {

    if (root == NULL)
        return -1;

    if (root->left == NULL)
        return root->data;

    Node* temp = root;

    while (temp->left != NULL)
        temp = temp->left;

    return temp->data;
}

// ***********************************************************************

// Maximum Value in a BST ( NOT IN QUESTION )

int maxValue(Node* root) {

    if (root == NULL)
        return -1;

    if (root->right == NULL)
        return root->data;

    Node* temp = root;

    while (temp->right != NULL)
        temp = temp->right;

    return temp->data;
}
