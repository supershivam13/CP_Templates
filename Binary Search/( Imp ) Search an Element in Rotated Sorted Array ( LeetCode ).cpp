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

// Find the index of the maximum(pivot) element and then do binary on either of the two parts of the array
// { i.e either on AB part or on CD part }


class Solution {
public:

    // Function to return the index of the maximum(pivot) element
    int find_pivot(vector<int>& nums, int left, int right)
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

    // Normal Binary Search function to return the index of the target element. If not found, return -1
    int binary_search(vector<int>& nums, int left, int right, int target)
    {
        int mid;

        while (left <= right)
        {
            mid = left + ((right - left) / 2);

            if (nums[mid] == target)
                return mid;

            else if (nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }

        return -1;
    }


    // Solution starts here
    int search(vector<int>& a, int target) {

        int n = a.size();

        if (n == 1) {
            if (target == a[0])
                return 0;
            else
                return -1;
        }

        // Finding the index of the maximum element of the array
        int pivot = find_pivot(a, 0, n - 1);


        // if target > a[n-1], then binary search on the AB part, else on CD part
        if (target > a[n - 1])
            return binary_search(a, 0, pivot, target);
        else
            return binary_search(a, (pivot + 1) % n, n - 1, target);

    }
};
