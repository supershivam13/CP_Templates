// BINARY SEARCH
// Identification -
// Whenever 'sorted' word is used, always think of Binary Search {i.e whenever sorted data is given, we might can
// improve the complexity using binary search }

// Property of Binary Search :-
// When a target element is not present in the array, then at the end of the loop, 'start' index points to the
// ceil element of the target and 'end' index points to the floor value of the target.

// *************************************************************************************************************


// CONCEPT
// Since all numbers are appearing twice and one element once only, so array size is always odd.
// A) If mid is even, then it has even number of elements in left subarray and right subarray. (0-based index)
// B) If mid is odd, then it has odd number of elements in left subarray and right subarray. (0-based index)

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int n = nums.size(), start = 0, end = n - 1;

        if(n==1)   return nums[0];     // Case when array has 1 element
            
        if(n==3){                      // Case when array has 3 element
            if(nums[0]==nums[1])   
                return nums[2];
            else                    
                return nums[0];
        }

        // Binary Search starts here
        while(start<=end){

            int mid = start + ((end-start)/2);

            // if mid is the unique element, so it does not match with its both adjacent elements
            if(nums[mid]!=nums[(mid-1+n)%n] and nums[mid]!=nums[(mid+1+n)%n])
                return nums[mid];

            // If mid is even, then it has even number of elements in left subarray and right subarray
            if (mid%2 == 0){
                if(nums[mid] == nums[(mid-1+n)%n]) // it paired-up with prev element,so left-space has odd elements
                    end = mid - 1;
                else
                    start = mid + 1;            //  else right search-space has odd elements
            }

            // If mid is odd, then it has odd number of elements in left subarray and right subarray
            else{
                if(nums[mid] == nums[(mid-1+n)%n]) // it paired-up with prev element,so left-space has even elements, so moving right
                    start = mid + 1;
                else
                    end = mid - 1;       //  else left search-space has odd elements
            }
        }
        return start;
    }
};
