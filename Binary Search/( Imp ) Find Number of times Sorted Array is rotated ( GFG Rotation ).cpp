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
//
// IDEA TO SOLVE :-  1) Number of time array is rotated is equal to the index of the minimum element
//                   2) The minimum element index will be the right adjacent to the maximum(pivot) element index.
class Solution {
    int find_pivot(int nums[], int left, int right)    // Function to return the index of the maximum(pivot) element
    {
        if (nums[left] < nums[right])  // if the array on which function is called is strictly increasing, i.e. it don't has the BC part
            return right;

        int mid;
        while (left <= right)  // BINARY SEARCH
        {
            mid = left + ((right - left) / 2);

            if (nums[mid] > nums[mid + 1])    // both the parts of graph are stricly increasing, so if next element is smaller than the current
                return mid;                   // element, it can occur only at place B

            else if (nums[mid] < nums[0])     // when mid falls in the CD part of the graph
                right = mid - 1;
                
            else                              // else mid is in the AB part, so changing left = mid + 1
                left = mid + 1;
        }
        return mid;
    }

public:

    // Solution starts here
    int findKRotation(int a[], int n) {

        // Finding the index of the maximum element of the array
        int pivot = find_pivot(a, 0, n - 1);

        // Number of times array is rotated  = Index of minimum element
        // The minimum element index will be the right adjacent to the maximum(pivot) element index.
        return (pivot + 1) % n;
    }
};
