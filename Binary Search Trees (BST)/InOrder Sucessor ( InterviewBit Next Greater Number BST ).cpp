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

    // Now finding the INORDER SUCCESSOR
    
    if (target->right != NULL) {  // When right subtree of 'target' node exists, then the left most node in the right subtree of target is the InOrder Successor.

        TreeNode* temp = target->right;   // entered the right subtree of target

        while (temp->left != NULL)       // keep going to the left most node
            temp = temp->left;

        return temp;
    }
    else {                                // right subtree of 'target' node DOES NOT exists, Else start from root and traverse to the 'target node', 
                                          // and keep storing the nodes which are greater than the 'target' node 
        TreeNode* succ = NULL;
        TreeNode* temp = root;

        while (temp != NULL) {

            if (temp->val > k) {        
                succ = temp;               // storing the potential InOrder Successor
                temp = temp->left;
            }
            else if (temp->val < k)        
                temp = temp->right;
            else                            // target node is reached
                break;
        }

        return succ;
    }
}
