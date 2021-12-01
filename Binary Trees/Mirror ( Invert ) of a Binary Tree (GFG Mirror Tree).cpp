// Time Complexity - O(N)
// Space Complexity - O( Height of tree ) { used in storing recursive calls in stack }

class Solution {
  public:
    void mirror(Node* node) {
        
        if(node==NULL)
            return;
         
         mirror(node->left);
         mirror(node->right);
         swap(node->left,node->right);    
    }
};
