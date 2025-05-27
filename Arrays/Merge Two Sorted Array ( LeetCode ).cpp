class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int first = m-1, second = n-1;
        int ind = m+n-1;
        
        while(first>=0 and second>=0){

            nums1[ind] = max(nums1[first],nums2[second]);    // nums1 has a size of (m+n)
            ind--;
            
            if(nums1[first] >= nums2[second])
                first--;
            else
                second--;
        }
    
    // only either one of the below while blocks will be executed
        while(first >= 0)
            nums1[ind--] = nums1[first--];
        
        while(second >= 0)
            nums1[ind--] = nums2[second--];
    
    }
};
