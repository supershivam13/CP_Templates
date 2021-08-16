// BINARY SEARCH

// Identification -
// Whenever 'sorted' word is used, always think of Binary Search {i.e whenever sorted data is given, we might can
// improve the complexity using binary search }


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
//
//


// IDEA TO SOLVE :-

// Number of time array is rotated is equal to the index of the minimum element.
// Number of times array is rotated  = Index of minimum element


class Solution {

    // Function to return the index of the maximum(pivot) element
    int find_pivot(int nums[], int left, int right)
    {
        // if the array on which function is called is strictly increasing
        // (it don't has the BC part of the graph )
        if (nums[left] < nums[right])
            return right;

        int mid;

        // Binary Search
        while (left <= right)
        {
            mid = left + ((right - left) / 2);

            // both the parts of graph are stricly increasing, so if next element is smaller than the current
            // element, it can occur only at place B
            if (nums[mid] > nums[mid + 1])
                return mid;

            // when mid falls in the CD part of the graph
            else if (nums[mid] < nums[0])
                right = mid - 1;

            // else mid is in the AB part, so changing left = mid + 1
            else
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
