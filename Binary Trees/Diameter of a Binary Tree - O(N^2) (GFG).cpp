// Time Complexity - O( N^2 )
// BRUTE FORCE APPROACH


class Solution {
  public:
  
    int height(Node* root){    // Normal Height of a Binary Tree function
        
        if(root==NULL)
            return 0;
            
        int left = height(root->left);
        int right = height(root->right);
        
        return 1 + max(left,right);
    }
    
    // DIAMETER = Number of EDGES (not nodes) on the longest path between two leaf nodes
    int diameter(Node* root) {
        
        if(root==NULL)
            return 0;
        
        int d1 = height(root->left) + height(root->right);   // If asked as Diameter = Number of nodes, then add 1 to 'd1'.
        int d2 = diameter(root->left);        // when diameter lies in the left subtreee
        int d3 = diameter(root->right);       // when diameter lies in the right subtreee
        
        return max( d1, max(d2,d3) );
    }
};
