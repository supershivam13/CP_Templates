// Time Complexity - O ( N*logN)
// Space Complexity - O(1)

class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        
        int left = a.size()-1;  // left on last element of first array
        int right = 0;          // right on first element of second array
        
        while(left>=0 and right<b.size()){
            
            if(a[left] > b[right]){    
                swap(a[left],b[right]);
                left--;
                right++;
            }
            else    // left value is going to be smaller further and right value is going to be greater further, so break simply
                break;
        }
        
        sort(a.begin(),a.end());    // small elements in first array, so sort
        sort(b.begin(),b.end());    // larger elements in second array, so sort
    }
};
