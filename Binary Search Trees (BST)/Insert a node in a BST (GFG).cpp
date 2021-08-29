//Function to insert a node in a BST.
Node* insert(Node* root, int key)
{
    if (root == NULL) {
        Node *newroot = new Node(key);
        return newroot;
    }

    // if root->data > key, then call on the left subtree recursively
    if (root->data > key)
        root->left = insert(root->left, key);

    // See if root->data = key, then we are doing nothing

    // else if root->data < key, then call on the left subtree recursively
    else if (root->data < key)
        root->right = insert(root->right, key);

    return root;
}
