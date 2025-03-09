// Graph of the Mountain Array
//                   B
//                  /\ 
//                 /  \ 
//                /    \ 
//               /      \ 
//            A /        \ C
//        

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {

        if(arr.size()==3)       // Case when array has 3 elements
            return arr[1];

        int n = arr.size();
        int start = 0, end = n - 1;

        while(start<=end){      // Simple Binary Search

            int mid = start + ((end-start)/2);

            if(arr[mid]>arr[(mid+1)%n] and arr[mid] > arr[(mid-1+n)%n])
                return mid;
            else if(arr[mid]>arr[(mid+1)%n])        // mid lies in BC range
                end = mid - 1;
            else                                    // mid lies in AB range
                start = mid + 1;
        }

        return start;
    }
};
