void inorder(node* curr, node*& prev)
{
    // Base case
    if (curr == NULL)
        return;

    inorder(curr->left, prev);
    prev->right = curr;
    prev->left = NULL;
    prev = curr;
    inorder(curr->right, prev);
}

// Function to flatten binary tree using level order traversal
node* flatten(node* parent)
{
    // Dummy node ( used as One Extra Node before the 1st node of the required linked list )
    node* dummy = new node(-1);

    // Pointer to previous element
    node* prev = dummy;

    // Calling in-order traversal
    inorder(parent, prev);

    // prev now points to the last node of the linked list, so storing NULL in left and right
    prev->left = NULL;
    prev->right = NULL;

    // dummy still point to the extra node created which is attached before
    // the 1st node of the required linked list
    node* head = dummy->right;

    // Delete dummy node
    delete dummy;
    return head;
}
