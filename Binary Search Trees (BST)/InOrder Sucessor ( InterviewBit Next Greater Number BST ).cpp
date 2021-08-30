// Inorder Successor or Next Greater Element

TreeNode* Solution::getSuccessor(TreeNode* root, int k) {

    if (root == NULL)
        return NULL;

    // pointer to store the address of the 'k' ( element whose successor is to be find )
    TreeNode* target = NULL;

    TreeNode* temp = root;

    // Searching in BST { storing address of 'k' in 'target' pointer }
    while (temp != NULL) {

        if (temp->val > k)
            temp = temp->left;
        else if (temp->val < k)
            temp = temp->right;
        else {
            target = temp;
            break;
        }
    }

    // Now finding the Inorder Successor

    // When right subtree of 'target' node exists,
    // then the left most node in the right subtree of target is the InOrder Successor.
    if (target->right != NULL) {

        TreeNode* temp = target->right;

        while (temp->left) {
            temp = temp->left;
        }

        return temp;
    }

    // Else start from root and traverse to the 'target node', and keep storing the nodes which are greater
    // than the target node (at last, node which is least greater than target is the InOrder Successor)
    else {

        TreeNode* succ = NULL;
        TreeNode* temp = root;

        while (temp != NULL) {

            if (temp->val > k) {
                succ = temp;
                temp = temp->left;
            }
            else if (temp->val < k)
                temp = temp->right;
            else
                break;
        }

        return succ;
    }
}
