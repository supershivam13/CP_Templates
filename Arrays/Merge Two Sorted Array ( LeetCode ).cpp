class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int f=m-1;
        int s=n-1;
        int ind=m+n-1;
        
        while(f>=0 and s>=0){
            nums1[ind--]=max(nums1[f],nums2[s]);
            
            if(nums1[f]>=nums2[s])
                f--;
            else
                s--;
        }
    
        while(f>=0)
            nums1[ind--]=nums1[f--];
        
        while(s>=0)
            nums1[ind--]=nums2[s--];
    }
};
