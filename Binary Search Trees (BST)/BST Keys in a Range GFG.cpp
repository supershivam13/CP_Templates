class Solution {
  public:
    vector<int> ans;
    
    void BSTKeysinRange(Node *root, int low, int high){
        
        if(root==NULL)
            return;
        
        if(root->data >= low and root->data <= high)  // low <= root->data <= high
        {
            BSTKeysinRange(root->left, low, high);
            ans.push_back(root->data);
            BSTKeysinRange(root->right, low, high);
        }
        else if(root->data > high)                    // root->data > high, so all lies in left Subtree
            BSTKeysinRange(root->left, low, high);
        else
            BSTKeysinRange(root->right, low, high);   // root->data < low, so all lies in right Subtree
    }
    
    // SOLUTION starts here
    vector<int> printNearNodes(Node *root, int low, int high) {
        
        BSTKeysinRange(root, low, high);    // funtion to add BST Keys in vector 'ans'
        return ans;
    }
};
