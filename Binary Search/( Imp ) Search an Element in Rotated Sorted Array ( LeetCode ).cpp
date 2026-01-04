// BINARY SEARCH

// Identification -
// Whenever 'sorted' word is used, always think of Binary Search {i.e whenever sorted data is given, we might can
// improve the complexity using binary search }


// Property of Binary Search :-
// When a target element is not present in the array, then at the end of the loop, 'start' index points to the
// ceil element of the target and 'end' index points to the floor value of the target.

// Graph of the Rotated Sorted Array
//                B /.
//                 / .
//                /  .
//               /   .
//            A /    .
//                   .     / D
//                   .    /
//                   .   /
//                   .  /
//                   . /
//                 C  /
// IDEA TO SOLVE :-   1) Find the index of the maximum(pivot) element 
//                    2) Then, do binary on either of the two parts of the array { i.e either on AB part or on CD part }
class Solution {
public:
    int find_pivot(vector<int>& nums, int left, int right){    // Function to return the index of the maximum(pivot) element

        int n = nums.size();
        
        while (left <= right){
            
            int mid = left + ((right - left) / 2);

            // both the parts of graph are stricly increasing, so if next element is smaller than the current
            // element, it can occur only at place B
            if (nums[mid] > nums[(mid + 1) % n])
                return mid;

            else if (nums[mid] >= nums[0])     // when mid falls in the AB part of the graph
                left = mid + 1;
            else                              // else mid is in the CD part, so changing right = mid 1 1
                right = mid - 1;
        }
        return -1;
    }

    // Normal Binary Search function to return the index of the target element. If not found, return -1
    int binary_search(vector<int>& nums, int left, int right, int target){
        while (left <= right)
        {
            int mid = left + ((right - left) / 2);

            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }

        return -1;
    }

    // CODE starts here
    int search(vector<int>& nums, int target) {

        int n = nums.size();

        if(n==1)
            return nums[0]==target ? 0 : -1;

        int pivot = find_pivot(nums, 0, n - 1); // Finding the index of the Maximum element of array

        // if target > a[0], then binary search on the AB part, else on CD part
        if (target >= nums[0])
            return binary_search(nums, 0, pivot, target);
        else
            return binary_search(nums, (pivot + 1) % n, n - 1, target);
    }
};
