// Sorted Array to a Height Balanced BST is same as Sorted Array to a Minimum Height BST.

// Method 1 ( Better Method )

class Solution {
public:

    TreeNode* createBST(vector<int>& nums, int start, int end){

        if(start>end)
            return NULL;
        
        int mid = start + (end-start)/2;
        TreeNode* root = new TreeNode(nums[mid]); // Making the middle element as root

        // Recursively calls for the left and right subtree with passing left and right subarray
        root->left = createBST(nums, start, mid - 1);
        root->right = createBST(nums, mid + 1, end);

        return root;
    }

    // CODE starts here
    TreeNode* sortedArrayToBST(vector<int>& nums) {

         int n = nums.size()-1;
        return createBST(nums,0,n);
    }
};

// **********************************************************************************************

// Method 2

class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {

        // Base Condition
        if (num.size() == 0)
            return NULL;

        int middle = num.size() / 2;

        // Making the middle element as root
        TreeNode* root = new TreeNode(num[middle]);

        // Iterators are passed here, which will copy from 1st iterator to 2nd iterator in new vector
        vector<int> left(num.begin(), num.begin() + middle);
        vector<int> right(num.begin() + middle + 1, num.end());

        // Recursively calls for the left and right subtree with passing new vectors
        root->left = sortedArrayToBST(left);
        root->right = sortedArrayToBST(right);

        return root;
    }
};
