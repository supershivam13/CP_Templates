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



class Solution {

    // Function to return the index of the maximum(pivot) element
    int find_pivot(vector<int>& nums, int left, int right)
    {
        if (nums[left] < nums[right])
            return right;

        int mid;

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
    int findMin(vector<int>& a) {

        int n = a.size();

        if (n == 1)
            return a[0];

        // Finding the index of the maximum element of the array
        int pivot = find_pivot(a, 0, n - 1);

        // The minimum element will be the right adjacent to the maximum(pivot) element
        return a[(pivot + 1) % n];
    }
};
