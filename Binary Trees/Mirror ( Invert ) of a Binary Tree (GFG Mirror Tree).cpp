// Time Complexity - O(N)
// Space Complexity - O( Height of tree ) { used in storing recursive calls in stack }

class Solution {
  public:
    void mirror(Node* node) {
        
        if(node==NULL)
            return;

         swap(node->left,node->right);   // swap the right and left
         mirror(node->left);            // invert the left subtree
         mirror(node->right);           // invert the right subtree
    }
};
